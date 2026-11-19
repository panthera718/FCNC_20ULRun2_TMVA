import ROOT
import os
import ctypes

def get_and_split_files(dir_path):
    mode_list_all = os.listdir(dir_path)
    mode_list = []

    for m_all in mode_list_all:
        if not "NPL" in m_all:
            mode_list.append(m_all)

    for m in mode_list:
        process_path = os.path.join(dir_path, m)
        process_list_all = os.listdir(process_path)
        process_list = []

        for p_all in process_list_all:
            if "NANOAODSIM" in p_all:
                process_list.append(p_all)

        for p in process_list:
            root_file_path = os.path.join(process_path, p)
            full_list = os.listdir(root_file_path)
            root_file_full_list = [file for file in full_list if file.endswith(".root")]
            root_file_full_list_sort = sorted(root_file_full_list)

            split_root_dir_path = "HalfEven"+root_file_path
            if not os.path.exists(split_root_dir_path):
                os.makedirs(split_root_dir_path)

            for file_name in root_file_full_list_sort:
                merged_root_file_path = os.path.join(root_file_path, file_name)
                split_root_file_path = os.path.join(split_root_dir_path, file_name)
                split_tree_half_even(merged_root_file_path, split_root_file_path)
                print("complete split:", split_root_file_path)

        print("")
        print("complete mode:", m)
        print("")

def split_tree_half_even(input_file_name, output_file_name_even):
    try:
        input_file = ROOT.TFile.Open(input_file_name)
        if not input_file or input_file.IsZombie():
            print("Error: Unable to open input file")
            return

        input_tree = input_file.Get("Events")
        if not input_tree:
            print("Error: Unable to retrieve TTree from input file")
            input_file.Close()
            return

        total_entries = input_tree.GetEntries()
        output_file_odd = ROOT.TFile(output_file_name_even, "RECREATE")
        output_tree_odd = input_tree.CloneTree(0)

        eventID = ctypes.c_int(0)
        branch_eventID = output_tree_odd.Branch("eventID", ctypes.addressof(eventID), "eventID/I")

        for i in range(total_entries):
            input_tree.GetEntry(i)
            if i % 2 == 1:
                j = i // 2
                eventID.value = j
                output_tree_odd.Fill()
        output_tree_odd.Write()

        chain2 = ROOT.TChain("Runs")
        chain3 = ROOT.TChain("LuminosityBlocks")

        chain2.Add(input_file_name)
        chain3.Add(input_file_name)

        output_file_odd.cd()

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

        hist_nEvents = input_file.Get("nEvents")
        hist_nEventsGenWeighted = input_file.Get("nEventsGenWeighted")
        if hist_nEvents:
            nEvents_hist = hist_nEvents.Clone("nEvents")
        if hist_nEventsGenWeighted:
            nEventsGenWeighted_hist = hist_nEventsGenWeighted.Clone("nEventsGenWeighted")

        if nEvents_hist:
            nEvents_hist.Write()

        if nEventsGenWeighted_hist:
            nEventsGenWeighted_hist.Write()

        output_file_odd.Close()
        input_file.Close()

        print("Trees successfully split and saved to", output_file_name_even)

    except Exception as e:
        print("An error occurred: {}".format(e))

if __name__ == "__main__":
    merged_file = [
        "Merged_FCNC_RunIISummer20UL18NanoAODv9_central/reco"
    ]
    for mf in merged_file:
        get_and_split_files(mf)
        print("")
        print("### Split process complete:", mf, "###")
        print("")
