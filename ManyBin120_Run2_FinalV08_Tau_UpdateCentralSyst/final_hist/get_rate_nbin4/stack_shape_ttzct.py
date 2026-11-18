#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import ROOT
import argparse

def main():
    parser = argparse.ArgumentParser(description="Stack shape TTZCT example in PyROOT")
    parser.add_argument('--file_mc',   type=str, default='../UpdatedAnalysisRootFiles_nbin4/TTzct_20ULCombined_Tau_nbin4_Analysis.root', 
                        help='Input MC file (default: TTzct_20ULCombined_Tau_nbin4_Analysis.root)')
    parser.add_argument('--file_data', type=str, default='../OriginalAnalysisRootFiles_nbin4/TTzct_20ULCombined_Tau_nbin4_data_obs.root', 
                        help='Input Data file (default: TTzct_20ULCombined_Tau_nbin4_data_obs.root)')
    args = parser.parse_args()

    f_mc   = ROOT.TFile.Open(args.file_mc,   "READ")
    f_data = ROOT.TFile.Open(args.file_data, "READ")

    categories = ["ElTaTa", "TaElEl", "MuTaTa", "TaMuMu"]
    samples    = ["ttzct", "ttZ", "ttX", "tZq", "tWZ", "WZ", "ZZ", "VV", "VVV", "XGamma", "TT", "Nonprompt"]

    h_data = {
        "ElTaTa": f_data.Get("TTElTaTa_data_obs"),
        "TaElEl": f_data.Get("TTTaElEl_data_obs"),
        "MuTaTa": f_data.Get("TTMuTaTa_data_obs"),
        "TaMuMu": f_data.Get("TTTaMuMu_data_obs")
    }

    h_mc = {}
    for cat in categories:
        h_mc[cat] = {}
        for s in samples:
            hname = f"TT{cat}_{s}"
            h_mc[cat][s] = f_mc.Get(hname)

    print()
    print("DataElTaTa:", h_data["ElTaTa"].GetEntries(),
          "DataMuTaTa:", h_data["MuTaTa"].GetEntries(),
          "DataTaElEl:", h_data["TaElEl"].GetEntries(),
          "DataTaMuMu:", h_data["TaMuMu"].GetEntries())

    print("\nElTaTa")
    print_integrals(h_mc, "ElTaTa", samples)

    print("MuTaTa")
    print_integrals(h_mc, "MuTaTa", samples)

    print("TaElEl")
    print_integrals(h_mc, "TaElEl", samples)

    print("TaMuMu")
    print_integrals(h_mc, "TaMuMu", samples)

    print()
    print(h_data["ElTaTa"].GetEntries(),
          h_data["MuTaTa"].GetEntries(),
          h_data["TaElEl"].GetEntries(),
          h_data["TaMuMu"].GetEntries())
    print()

    print_all_in_one_line(h_mc, samples)

    f_mc.Close()
    f_data.Close()

def print_integrals(h_mc, category, samples):
    integrals_str = " ".join(str(h_mc[category][s].Integral()) for s in samples)
    print(integrals_str)

def print_all_in_one_line(h_mc, samples):
    cat_order = ["ElTaTa", "MuTaTa", "TaElEl", "TaMuMu"]
    vals = []
    for cat in cat_order:
        for s in samples:
            vals.append(str(h_mc[cat][s].Integral()))
    print(" ".join(vals))
    print()

if __name__ == "__main__":
    main()
