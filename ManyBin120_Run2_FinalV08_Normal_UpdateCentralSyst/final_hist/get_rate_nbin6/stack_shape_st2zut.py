#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import ROOT
import argparse

def main():
    parser = argparse.ArgumentParser(description="Stack shape ST2ZCT example in PyROOT")
    parser.add_argument('--file_mc',   type=str, default='../UpdatedAnalysisRootFiles_nbin6/ST2zut_20ULCombined_All_nbin6_Analysis.root', 
                        help='Input MC file (default: ST2zut_20ULCombined_All_nbin6_Analysis.root)')
    parser.add_argument('--file_data', type=str, default='../OriginalAnalysisRootFiles_nbin6/ST2zut_20ULCombined_All_nbin6_data_obs.root', 
                        help='Input Data file (default: ST2zut_20ULCombined_All_nbin6_data_obs.root)')
    args = parser.parse_args()

    f_mc   = ROOT.TFile.Open(args.file_mc,   "READ")
    f_data = ROOT.TFile.Open(args.file_data, "READ")

    categories = ["ElElEl", "ElMuMu", "MuElEl", "MuMuMu"]
    samples    = ["st2zut", "ttZ", "ttX", "tZq", "tWZ", "WZ", "ZZ", "VV", "VVV", "XGamma", "TT", "Nonprompt"]

    h_data = {
        "ElElEl": f_data.Get("ST2ElElEl_data_obs"),
        "ElMuMu": f_data.Get("ST2ElMuMu_data_obs"),
        "MuElEl": f_data.Get("ST2MuElEl_data_obs"),
        "MuMuMu": f_data.Get("ST2MuMuMu_data_obs")
    }

    h_mc = {}
    for cat in categories:
        h_mc[cat] = {}
        for s in samples:
            hname = f"ST2{cat}_{s}"
            h_mc[cat][s] = f_mc.Get(hname)

    print()
    print("DataElElEl:", h_data["ElElEl"].GetEntries(),
          "DataMuElEl:", h_data["MuElEl"].GetEntries(),
          "DataElMuMu:", h_data["ElMuMu"].GetEntries(),
          "DataMuMuMu:", h_data["MuMuMu"].GetEntries())

    print("\nElElEl")
    print_integrals(h_mc, "ElElEl", samples)

    print("MuElEl")
    print_integrals(h_mc, "MuElEl", samples)

    print("ElMuMu")
    print_integrals(h_mc, "ElMuMu", samples)

    print("MuMuMu")
    print_integrals(h_mc, "MuMuMu", samples)

    print()
    print(h_data["ElElEl"].GetEntries(),
          h_data["MuElEl"].GetEntries(),
          h_data["ElMuMu"].GetEntries(),
          h_data["MuMuMu"].GetEntries())
    print()

    print_all_in_one_line(h_mc, samples)

    f_mc.Close()
    f_data.Close()

def print_integrals(h_mc, category, samples):
    integrals_str = " ".join(str(h_mc[category][s].Integral()) for s in samples)
    print(integrals_str)

def print_all_in_one_line(h_mc, samples):
    cat_order = ["ElElEl", "MuElEl", "ElMuMu", "MuMuMu"]
    vals = []
    for cat in cat_order:
        for s in samples:
            vals.append(str(h_mc[cat][s].Integral()))
    print(" ".join(vals))
    print()

if __name__ == "__main__":
    main()
