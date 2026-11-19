# FCNC UL Run 2 DNN analysis with TMVA

This repository contains the workflow for training deep neural networks (DNNs) for the Run 2 FCNC analysis, producing DNN score histograms, and preparing ROOT files for CMS Combine.

| Directory | Purpose |
| --- | --- |
| [`merged_and_split_python`](merged_and_split_python/) | Merge ROOT files by dataset and split the prompt-lepton MC into independent samples for training and histogram production. |
| [`Complete_Run2_FinalV08`](Complete_Run2_FinalV08/) | Train a DNN for each signal region, FCNC coupling, and three-lepton channel. |
| [`ManyBin120_Run2_FinalV08_Normal_UpdateCentralSyst`](ManyBin120_Run2_FinalV08_Normal_UpdateCentralSyst/) | Produce score histograms and Combine inputs for channels containing only electrons and muons. |
| [`ManyBin120_Run2_FinalV08_Tau_UpdateCentralSyst`](ManyBin120_Run2_FinalV08_Tau_UpdateCentralSyst/) | Produce score histograms and Combine inputs for channels containing tau leptons. |

## 1. Merge and split the input ROOT files

Merge the ROOT files separately for each dataset and lepton channel. In the table below, `{mode}` denotes a three-lepton channel such as `ElElEl`. The names in the second column are shorthand for sample categories.

| Sample | Input category | DNN training | DNN score histograms |
| --- | --- | --- | --- |
| Prompt-lepton data | `{mode}data` | — | All central events |
| Nonprompt-lepton data | `NPL{mode}` (data) | — | All central events |
| Prompt-lepton MC | `{mode}MC` | Odd-position entries from `central` | Even-position entries from `central`, `jerDown`, `jerUp`, and `jetVar01` through `jetVar09` |
| Nonprompt-lepton MC | `NPL{mode}MC` | — | All central events |
| Additional MC for training the DNN on nonprompt leptons | `{mode}MC` from the separate `NPL` production | All central events | — |

The shorthand `jerVar0X` refers to the nine JES configurations named `jetVar01` through `jetVar09` in the repository. The JER variations are `jerDown` and `jerUp`.

1. Set `ntuple_file` in [`mkSameDirAndMergeRootFiles.py`](merged_and_split_python/mkSameDirAndMergeRootFiles.py) to the input directory for the era and variation you want to process. Run the script to merge the ROOT files.
2. For prompt-lepton MC, set `merged_file` in [`mkSameDirAndSelectEvenEvents.py`](merged_and_split_python/mkSameDirAndSelectEvenEvents.py) and [`mkSameDirAndSelectOddEvents.py`](merged_and_split_python/mkSameDirAndSelectOddEvents.py) to the corresponding merged input. Run both scripts. The other four sample categories use the full merged samples.

For example, the 2018 central input for the merge step is

```python
ntuple_file = [
    "FCNC_RunIISummer20UL18NanoAODv9_central/reco"
]
```

The split uses the entry position in each merged tree. `HalfOdd` contains the first, third, fifth, and subsequent odd-position entries. `HalfEven` contains the second, fourth, sixth, and subsequent even-position entries. Train the DNN on `HalfOdd` from the central prompt-lepton MC and produce score histograms from `HalfEven`. The prompt-lepton MC histogram normalization includes a factor of two to account for using half the sample.

The central and shifted prompt-lepton ntuples use the same lepton-only preselection so that events with the same selected leptons enter all configurations. Preserve the same entry ordering across configurations when splitting them. Using the even-position entries for every variation keeps the nominal and varied histograms on the same statistical footing.

### Legacy `EventID` directory names

Two scripts were originally written to add an entry index for k-fold cross-validation. The final analysis does not use k-fold cross-validation, but some file lists still expect the directory names produced by these scripts.

| Script | Merged input | Output directory expected by the legacy file lists |
| --- | --- | --- |
| [`mkSameDirAndAddEventIDToAll.py`](merged_and_split_python/mkSameDirAndAddEventIDToAll.py) | `Merged_NPL_..._central/reco` | `EventIDAllMerged_NPL_..._central/reco` |
| [`mkSameDirAndAddEventIDToDataAndNPL.py`](merged_and_split_python/mkSameDirAndAddEventIDToDataAndNPL.py) | `Merged_FCNC_..._central/reco` | `EventIDDataNPLMerged_FCNC_..._central/reco` |

In `Merged_NPL_...`, `NPL` identifies the **additional MC production used for DNN training**. In a channel name such as `NPLElElEl`, `NPL` identifies the **nonprompt control sample**. The second script handles data in the standard channels and both data and MC in the `NPL{mode}` channels. If you skip the indexing step, update the file-list generators to point to the corresponding unsplit merged inputs.

## 2. Train the DNNs

Train a separate model for each combination of signal region (`ST1`, `ST2`, or `TT`), FCNC coupling (`zut` or `zct`), and lepton channel. `ST1` and `ST2` are the two single-top signal regions. `TT` is the top–antitop signal region. Only `TT` uses tau channels because the single-top regions have too few events in those channels.

For each model, open its directory under `Complete_Run2_FinalV08/`. The following steps use [`Run2_st1zct_ElElEl`](Complete_Run2_FinalV08/Run2_st1zct_ElElEl/) as an example.

1. In `Automation_Cla/`, remove the previously generated `.txt` file lists and update the input paths in [`gen_filelist.py`](Complete_Run2_FinalV08/Run2_st1zct_ElElEl/Automation_Cla/gen_filelist.py). From that directory, run `python3 gen_filelist.py`.
2. The default generator builds `filelist_bkg.txt` from the odd-position central prompt-lepton MC. To include the additional nonprompt training MC, add the corresponding unsplit central ROOT files to `filelist_bkg.txt` once, before counting the selected events.
3. In the parent model directory, edit [`TMVAClassification_FCNC.C`](Complete_Run2_FinalV08/Run2_st1zct_ElElEl/TMVAClassification_FCNC.C). Set `nTrain_Signal` and `nTrain_Background` from the signal and background counts **after selection**. Use a 3:1 training-to-test ratio within the sample supplied to TMVA. The even-position prompt-lepton MC remains reserved for score histograms.

For example, with 52,944 selected signal events and 31,494 selected background events, the macro uses

```cpp
dataloader->PrepareTrainingAndTestTree(
    mycuts, mycutb,
    "nTrain_Signal=39708:nTrain_Background=23621:SplitMode=Random:SplitSeed=123456:NormMode=NumEvents:!V");
```

From the model directory, run

```bash
root -l -b -q TMVAClassification_FCNC.C
```

The trained model weights are written to `dataset/weights/` in that directory. Use the same weights for the matching region, coupling, and lepton channel in each era.

## 3. Produce score histograms for electron and muon channels

Work in [`ManyBin120_Run2_FinalV08_Normal_UpdateCentralSyst`](ManyBin120_Run2_FinalV08_Normal_UpdateCentralSyst/). In the steps below, *project directory* refers to this directory.

### Configure the weights and file lists

1. For each era directory (`Complete_2016APVpreVFP`, `Complete_2016postVFP`, `Complete_2017`, and `Complete_2018`), copy each model's `dataset/weights/` into the matching `Run2_<region>z<u-or-c>t_<mode>/dataset/weights/` directory.
2. For each era, model, and variation, update the ntuple paths in `Automation_ClaApl_<variation>/filelist/gen_filelist.py`. See the [2018 central configuration for `Run2_st1zct_ElElEl`](ManyBin120_Run2_FinalV08_Normal_UpdateCentralSyst/Complete_2018/Run2_st1zct_ElElEl/Automation_ClaApl_central/filelist/gen_filelist.py) for an example.
3. From the project directory, generate the application file lists.

```bash
python3 run_all_gen_filelist.py
```

### Run the DNN application

From **each** `Complete_<era>/` directory, run the four channel scripts, followed by the nonprompt histogram script. This step can take a long time.

```bash
bash run_gen_ElElEl.sh
bash run_gen_ElMuMu.sh
bash run_gen_MuElEl.sh
bash run_gen_MuMuMu.sh
bash run_nonprompt_histo.sh
```

### Merge the histograms and prepare the Combine inputs

From the **project directory**, run [`copy_rootfiles.py`](ManyBin120_Run2_FinalV08_Normal_UpdateCentralSyst/copy_rootfiles.py), then [`batch_hadd.py`](ManyBin120_Run2_FinalV08_Normal_UpdateCentralSyst/batch_hadd.py). Next, run [`batch_hadd_data_obs.py`](ManyBin120_Run2_FinalV08_Normal_UpdateCentralSyst/ManyBin120_FinalV04_nbin120_RootFiles/batch_hadd_data_obs.py) from the shared 120-bin directory.

```bash
python3 copy_rootfiles.py
python3 batch_hadd.py
(cd ManyBin120_FinalV04_nbin120_RootFiles && python3 batch_hadd_data_obs.py)
```

Before rebinning, copy or symlink the merged per-channel ROOT files from the channel directories into `ManyBin120_FinalV04_nbin120_RootFiles/`. For example, the 2018 `ST1zct` electron-channel file is `Complete_2018/Run2_st1zct_ElElEl/ST1zct_20UL18_ElElEl.root`. The `batch_hadd_data_obs.py` step produces the observed-data histograms separately.

From the project directory, run the rebinning script and then `run_hadd.py` inside each binning directory.

```bash
(cd Bin15_RootFiles && python3 process_Bin15.py && python3 run_hadd.py)
(cd Bin10_RootFiles && python3 process_Bin10.py && python3 run_hadd.py)
(cd Bin5_RootFiles  && python3 process_Bin5.py  && python3 run_hadd.py)
```

Finally, run the era-level scripts from the project directory, in this order.

```bash
python3 run_era_haddProcess_Bin15.py
python3 run_era_haddProcess_Bin10.py
python3 run_era_haddProcess_Bin5.py
python3 run_era_mainProcess.py
```

The final ROOT files for CMS Combine are written to `Complete_<era>/Run2_<region>z<u-or-c>t/`. Their names follow this pattern:

```text
{ST1,ST2,TT}z{u,c}t_20UL{16APVpreVFP,16postVFP,17,18}_All_nbin{5,10,15}_Analysis.root
```

For example, the 15-bin `ST1zct` output for 2018 is `Complete_2018/Run2_st1zct/ST1zct_20UL18_All_nbin15_Analysis.root`.

## 4. Produce score histograms for tau channels

Use [`ManyBin120_Run2_FinalV08_Tau_UpdateCentralSyst`](ManyBin120_Run2_FinalV08_Tau_UpdateCentralSyst/) for the `ElTaTa`, `MuTaTa`, `TaElEl`, and `TaMuMu` channels in the `TT` signal region. Follow the same steps for copying weights, generating file lists, merging histograms, and rebinning, using the directories and scripts in the tau project.

For the DNN application, run the following scripts from **each** `Complete_<era>/` directory:

```bash
bash run_gen_ttzct_Tau.sh
bash run_gen_ttzut_Tau.sh
bash run_nonprompt_histo.sh
```

The combined tau-channel filenames use `Tau` as the channel label, for example `TTzct_20UL18_Tau_nbin15_Analysis.root`.
