#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import ROOT
import argparse

def main():
    parser = argparse.ArgumentParser(description="Stack shape ST2ZCT example in PyROOT")
    parser.add_argument('--file_mc',   type=str, default='../UpdatedAnalysisRootFiles_nbin8/ST2zut_20UL16APVpreVFP_Tau_nbin8_Analysis.root', 
                        help='Input MC file (default: ST2zut_20UL16APVpreVFP_Tau_nbin8_Analysis.root)')
    parser.add_argument('--file_data', type=str, default='../OriginalAnalysisRootFiles_nbin8/ST2zut_20UL16APVpreVFP_Tau_nbin8_data_obs.root', 
                        help='Input Data file (default: ST2zut_20UL16APVpreVFP_Tau_nbin8_data_obs.root)')
    args = parser.parse_args()

    f_mc   = ROOT.TFile.Open(args.file_mc,   "READ")
    f_data = ROOT.TFile.Open(args.file_data, "READ")

    categories = ["ElTaTa", "MuTaTa", "TaElEl", "TaMuMu"]
    samples    = ["st2zut", "ttZ", "ttX", "tZq", "tWZ", "WZ", "ZZ", "VV", "VVV", "XGamma", "TT", "Nonprompt"]

    h_data = {
        "ElTaTa": f_data.Get("ST2ElTaTa_data_obs"),
        "MuTaTa": f_data.Get("ST2MuTaTa_data_obs"),
        "TaElEl": f_data.Get("ST2TaElEl_data_obs"),
        "TaMuMu": f_data.Get("ST2TaMuMu_data_obs")
    }

    h_mc = {}
    for cat in categories:
        h_mc[cat] = {}
        for s in samples:
            hname = f"ST2{cat}_{s}"
            h_mc[cat][s] = f_mc.Get(hname)

    print()
    print("DataElTaTa:", h_data["ElTaTa"].GetEntries(),
          "DataTaElEl:", h_data["TaElEl"].GetEntries(),
          "DataMuTaTa:", h_data["MuTaTa"].GetEntries(),
          "DataTaMuMu:", h_data["TaMuMu"].GetEntries())

    print("\nElTaTa")
    print_integrals(h_mc, "ElTaTa", samples)

    print("TaElEl")
    print_integrals(h_mc, "TaElEl", samples)

    print("MuTaTa")
    print_integrals(h_mc, "MuTaTa", samples)

    print("TaMuMu")
    print_integrals(h_mc, "TaMuMu", samples)

    print()
    print(h_data["ElTaTa"].GetEntries(),
          h_data["TaElEl"].GetEntries(),
          h_data["MuTaTa"].GetEntries(),
          h_data["TaMuMu"].GetEntries())
    print()

    print_all_in_one_line(h_mc, samples)

    f_mc.Close()
    f_data.Close()

def print_integrals(h_mc, category, samples):
    integrals_str = " ".join(str(h_mc[category][s].Integral()) for s in samples)
    print(integrals_str)

def print_all_in_one_line(h_mc, samples):
    cat_order = ["ElTaTa", "TaElEl", "MuTaTa", "TaMuMu"]
    vals = []
    for cat in cat_order:
        for s in samples:
            vals.append(str(h_mc[cat][s].Integral()))
    print(" ".join(vals))
    print()

if __name__ == "__main__":
    main()
