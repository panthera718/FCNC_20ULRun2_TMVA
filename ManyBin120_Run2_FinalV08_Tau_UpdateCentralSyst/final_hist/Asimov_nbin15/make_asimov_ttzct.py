#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import ROOT
import argparse

def main():
    parser = argparse.ArgumentParser(description="Make Asimov histograms from TTzct analysis files using PyROOT")
    parser.add_argument('--file_in', type=str, default='../UpdatedAnalysisRootFiles_nbin15/TTzct_20UL18_Tau_nbin15_Analysis.root',
                        help='Input analysis file (default: TTzct_20UL18_Tau_nbin15_Analysis.root)')
    parser.add_argument('--file_out_nosig', type=str, default='AsimovWithoutSig_TTzct_20UL18_Tau_nbin15_Analysis.root',
                        help='Output file name for Asimov without signal (default: AsimovWithoutSig_TTzct_20UL18_Tau_nbin15_Analysis.root)')
    parser.add_argument('--file_out_sig', type=str, default='AsimovWithSig_TTzct_20UL18_Tau_nbin15_Analysis.root',
                        help='Output file name for Asimov with signal (default: AsimovWithSig_TTzct_20UL18_Tau_nbin15_Analysis.root)')

    args = parser.parse_args()

    f_in = ROOT.TFile.Open(args.file_in, "READ")

    categories = ["ElTaTa", "TaElEl", "MuTaTa", "TaMuMu"]
    sig_sample  = "ttzct"
    main_bkg    = "ttZ"
    bkg_others  = ["ttX", "tZq", "tWZ", "WZ", "ZZ", "VV", "VVV", "XGamma", "Nonprompt"]

    h_data = {}
    h_mc   = {}

    for cat in categories:
        data_name = f"TT{cat}_data_obs"
        h_data[cat] = f_in.Get(data_name)

        h_mc[cat] = {}
        mc_name = f"TT{cat}_{main_bkg}"
        h_mc[cat][main_bkg] = f_in.Get(mc_name)
        sig_name = f"TT{cat}_{sig_sample}"
        h_mc[cat][sig_sample] = f_in.Get(sig_name)
        for b in bkg_others:
            mc_name = f"TT{cat}_{b}"
            h_mc[cat][b] = f_in.Get(mc_name)

    for cat in categories:
        for b in bkg_others:
            h_mc[cat][main_bkg].Add(h_mc[cat][b])

    print()
    print("Asimov Without Signal MC")
    cat_order_nosig = ["ElTaTa","MuTaTa","TaElEl","TaMuMu"]
    for c in cat_order_nosig:
        print(f"TT{c}: {h_mc[c][main_bkg].Integral()}")
    vals_nosig = [str(h_mc[c][main_bkg].Integral()) for c in cat_order_nosig]
    print(" ".join(vals_nosig))

    asimovNoSig = {}
    for cat in categories:
        tmp_hist = h_mc[cat][main_bkg].Clone(f"TT{cat}_data_obs")
        tmp_hist.SetTitle(f"TT{cat}_data_obs")
        asimovNoSig[cat] = tmp_hist

    for cat in categories:
        h_mc[cat][sig_sample].Add(h_mc[cat][main_bkg])

    print()
    print("Asimov With Signal MC")
    cat_order_sig = ["ElTaTa","MuTaTa","TaElEl","TaMuMu"]
    for c in cat_order_sig:
        print(f"TT{c}: {h_mc[c][sig_sample].Integral()}")
    vals_sig = [str(h_mc[c][sig_sample].Integral()) for c in cat_order_sig]
    print(" ".join(vals_sig))

    asimovWithSig = {}
    for cat in categories:
        tmp_hist = h_mc[cat][sig_sample].Clone(f"TT{cat}_data_obs")
        tmp_hist.SetTitle(f"TT{cat}_data_obs")
        asimovWithSig[cat] = tmp_hist

    fout_nosig = ROOT.TFile(args.file_out_nosig, "RECREATE")
    for cat in categories:
        asimovNoSig[cat].Write()
    fout_nosig.Close()

    fout_sig = ROOT.TFile(args.file_out_sig, "RECREATE")
    for cat in categories:
        asimovWithSig[cat].Write()
    fout_sig.Close()

    f_in.Close()

if __name__ == "__main__":
    main()
