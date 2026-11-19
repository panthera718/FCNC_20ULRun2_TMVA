import ROOT
import os

def get_and_merge_files(dir_path):
    mode_list = os.listdir(dir_path)

    for m in mode_list:
        process_path = os.path.join(dir_path, m)
        process_list = os.listdir(process_path)

        for p in process_list:
            root_file_path = os.path.join(process_path, p)
            full_list = os.listdir(root_file_path)
            root_file_full_list = [file for file in full_list if file.endswith(".root")]
            root_file_full_list_sort = sorted(root_file_full_list)

            merged_root_file_path = "Merged_" + root_file_path
            if not os.path.exists(merged_root_file_path):
                os.makedirs(merged_root_file_path)

            merged_root_file = os.path.join(merged_root_file_path, p + ".root")
            mode_process_files = []

            for file_list in root_file_full_list_sort:
                full_file_path = os.path.join(root_file_path, file_list)
                mode_process_files.append(full_file_path)

            merge_root_files(mode_process_files, merged_root_file)
            print("complete merge:", merged_root_file)

        print("")
        print("complete mode:", m)
        print("")

def merge_root_files(input_files, output_file):
    try:
        chain1 = ROOT.TChain("Events")
        chain2 = ROOT.TChain("Runs")
        chain3 = ROOT.TChain("LuminosityBlocks")

        for input_file in input_files:
            chain1.Add(input_file)
            chain2.Add(input_file)
            chain3.Add(input_file)

        output = ROOT.TFile(output_file, "RECREATE")

        if chain1.GetEntries() == 0:
            empty_tree1 = chain1.CloneTree(0)
            empty_tree1.Write()
        else:
            output_tree1 = chain1.CloneTree(0)
            n_entries1 = chain1.GetEntries()
            for i_entry in range(n_entries1):
                chain1.GetEntry(i_entry)
                output_tree1.Fill()
            output_tree1.Write()

        if chain2.GetEntries() == 0:
            empty_tree2 = chain2.CloneTree(0)
            empty_tree2.Write()
        else:
            output_tree2 = chain2.CloneTree(0)
            n_entries2 = chain2.GetEntries()
            for i_entry in range(n_entries2):
                chain2.GetEntry(i_entry)
                output_tree2.Fill()
            output_tree2.Write()

        if chain3.GetEntries() == 0:
            empty_tree3 = chain3.CloneTree(0)
            empty_tree3.Write()
        else:
            output_tree3 = chain3.CloneTree(0)
            n_entries3 = chain3.GetEntries()
            for i_entry in range(n_entries3):
                chain3.GetEntry(i_entry)
                output_tree3.Fill()
            output_tree3.Write()

        nEvents_hist = None
        nEventsGenWeighted_hist = None
        for input_file in input_files:
            root_file = ROOT.TFile(input_file)
            hist_nEvents = root_file.Get("nEvents")
            hist_nEventsGenWeighted = root_file.Get("nEventsGenWeighted")
            if hist_nEvents:
                if not nEvents_hist:
                    nEvents_hist = ROOT.TH1D()
                    nEvents_hist.AddDirectory(0)
                    nEvents_hist = hist_nEvents.Clone("nEvents")
                else:
                    nEvents_hist.Add(hist_nEvents)
            if hist_nEventsGenWeighted:
                if not nEventsGenWeighted_hist:
                    nEventsGenWeighted_hist = ROOT.TH1D()
                    nEventsGenWeighted_hist.AddDirectory(0)
                    nEventsGenWeighted_hist = hist_nEventsGenWeighted.Clone("nEventsGenWeighted")
                else:
                    nEventsGenWeighted_hist.Add(hist_nEventsGenWeighted)
            root_file.Close()

        if nEvents_hist:
            output.cd()
            nEvents_hist.Write()

        if nEventsGenWeighted_hist:
            output.cd()
            nEventsGenWeighted_hist.Write()

        output.Close()

        print("Trees successfully merged to", output_file)

    except Exception as e:
        print("An error occurred: {}".format(e))

if __name__ == "__main__":
    ntuple_file = [
        "FCNC_RunIISummer20UL18NanoAODv9_central/reco"
    ]
    for nf in ntuple_file:
        get_and_merge_files(nf)
        print("")
        print("### Merge process complete:", nf, "###")
        print("")
