import ROOT
import math

def create_analysis_rootfile(signal_name ,input_filename, output_filename):
    # input ROOT
    fin = ROOT.TFile.Open(input_filename, "READ")
    if not fin or fin.IsZombie():
        print(f"Cannot open input file: {input_filename}")
        return
    
    # output ROOT
    fout = ROOT.TFile(output_filename, "RECREATE")
    
    # CHANNEL, PROCESS, JESSYS
    channels = ["ElElEl", "ElMuMu", "MuElEl", "MuMuMu"]
    processes = [signal_name, "ttZ", "ttX", "tZq", "tWZ", "WZ", "ZZ", "VV", "VVV", "XGamma", "TT", "Nonprompt"]
    commonsyslist = [
        "BtagLF",
        "BtagHF",
        "BtagHFStats1",
        "BtagHFStats2",
        "BtagLFStats1",
        "BtagLFStats2",
        "BtagCFErr1",
        "BtagCFErr2",

        "ElRecoSF",
        "ElSFStat",
        "ElSFSyst",
        "MuSFStat",
        "MuSFSyst",
        "PU",
        "JetPUID",
        "MuR",
        "MuF",
        "PSWeightISR",
        "PSWeightFSR",
        "LHEPdfWeight",

        "L1PreFiringWeight",
        "L1PreFiringWeightECAL",
        "L1PreFiringWeightMuonStat",
        "L1PreFiringWeightMuonSyst",

        "TauIDSF",
        "TauIDSF_genuineTau",
        "TauIDSF_eToTau",
        "TauIDSF_muToTau",
        "TauIDSF_otherVSlepWP",
        "TauTriggerWeight",

        "jer",

        "AbsoluteStat",
        "AbsoluteScale",
        "AbsoluteMPFBias",
        "Fragmentation",
        "SinglePionECAL",
        "SinglePionHCAL",
        "FlavorQCD",
        "TimePtEta",
        "RelativeJEREC1",
        "RelativeJEREC2",
        "RelativeJERHF",
        "RelativePtBB",
        "RelativePtEC1",
        "RelativePtEC2",
        "RelativePtHF",
        "RelativeBal",
        "RelativeSample",
        "RelativeFSR",
        "RelativeStatFSR",
        "RelativeStatEC",
        "RelativeStatHF",
        "PileUpDataMC",
        "PileUpPtRef",
        "PileUpPtBB",
        "PileUpPtEC1",
        "PileUpPtEC2",
        "PileUpPtHF"
    ]
    nonpromptsyslist = ["Nonprompt"]
    
    # loop
    for ch in channels:
        for proc in processes:
            # central
            centralName = "ST2" + ch + "_" + proc
            h_central = fin.Get(centralName)
            if not h_central:
                print(f"Central histogram not found: {centralName}")
                continue
            fout.cd()
            h_central.Write()

            syslist = []
            if proc == "Nonprompt":
                syslist = nonpromptsyslist
            else:
                syslist = commonsyslist

            # systematic variation
            for sysl in syslist:
                hname_common = "ST2" + ch + "_" + proc + "_" + sysl
                hname_up = hname_common + "Up"
                hname_down = hname_common + "Down"
                
                h_up = fin.Get(hname_up)
                h_down = fin.Get(hname_down)

                if not proc == signal_name and sysl == "LHEPdfWeight":
                    continue
                elif not h_up or not h_down:
                    if not h_up:
                        print(f"Up histogram not found: {hname_up}")
                    if not h_down:
                        print(f"Down histogram not found: {hname_down}")
                    continue

                # "_correlated", "_uncorrelated_2018"
                h_up_correlated = h_up.Clone(hname_common + "CorrelatedUp")
                h_down_correlated = h_down.Clone(hname_common + "CorrelatedDown")
                h_up_uncorrelated = h_up.Clone(hname_common + "Uncorrelated2018Up")
                h_down_uncorrelated = h_down.Clone(hname_common + "Uncorrelated2018Down")
                
                fout.cd()
                h_up_correlated.Write()
                h_down_correlated.Write()
                h_up_uncorrelated.Write()
                h_down_uncorrelated.Write()
                
                # partial correlation
                factor = math.sqrt(0.5)
                
                # up variation partial correlation
                h_partial_up_common = h_central.Clone(hname_common + "PartiallyCorrelatedCommonUp")
                h_partial_up_common.Reset()
                h_partial_up_common.Add(h_up, 1.0)
                h_partial_up_common.Add(h_central, -1.0)
                h_partial_up_common.Scale(factor)
                h_partial_up_common.Add(h_central, 1.0)
                
                h_partial_up_2018 = h_central.Clone(hname_common + "PartiallyUncorrelated2018Up")
                h_partial_up_2018.Reset()
                h_partial_up_2018.Add(h_up, 1.0)
                h_partial_up_2018.Add(h_central, -1.0)
                h_partial_up_2018.Scale(factor)
                h_partial_up_2018.Add(h_central, 1.0)
                
                # down variation partial correlation
                h_partial_down_common = h_central.Clone(hname_common + "PartiallyCorrelatedCommonDown")
                h_partial_down_common.Reset()
                h_partial_down_common.Add(h_down, 1.0)
                h_partial_down_common.Add(h_central, -1.0)
                h_partial_down_common.Scale(factor)
                h_partial_down_common.Add(h_central, 1.0)
                
                h_partial_down_2018 = h_central.Clone(hname_common + "PartiallyUncorrelated2018Down")
                h_partial_down_2018.Reset()
                h_partial_down_2018.Add(h_down, 1.0)
                h_partial_down_2018.Add(h_central, -1.0)
                h_partial_down_2018.Scale(factor)
                h_partial_down_2018.Add(h_central, 1.0)
                
                fout.cd()
                h_partial_up_common.Write()
                h_partial_down_common.Write()
                h_partial_up_2018.Write()
                h_partial_down_2018.Write()
    
    fout.Close()
    fin.Close()

    print(f"Analysis root file was made: {output_filename}")

if __name__ == "__main__":
    signal = "st2zut"
    create_analysis_rootfile(
        signal_name = signal,
        input_filename  = "ST2zut_20UL18_All_nbin15_Base_New.root",
        output_filename = "ST2zut_20UL18_All_nbin15_Analysis.root"
    )
    create_analysis_rootfile(
        signal_name = signal,
        input_filename  = "ST2zut_20UL18_All_nbin10_Base_New.root",
        output_filename = "ST2zut_20UL18_All_nbin10_Analysis.root"
    )
    create_analysis_rootfile(
        signal_name = signal,
        input_filename  = "ST2zut_20UL18_All_nbin5_Base_New.root",
        output_filename = "ST2zut_20UL18_All_nbin5_Analysis.root"
    )
