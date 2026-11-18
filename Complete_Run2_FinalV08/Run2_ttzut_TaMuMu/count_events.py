#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
Count selected events for signal and background from filelists.

Compatible with uproot v4/v5: open each file, then use tree.iterate().
Falls back to ROOT RDataFrame if uproot is unavailable.

Selection:
(CutStep>=1) && (JetVetoSum<9) && (abs(Z_mass-91.2)<15.0) &&
(MET_pt>15.0) && (nGoodJet>=2) &&
(nBjet>=1) && (abs(KinTopZq_mass-172.5)<50.0)
"""

import os
import sys

FILELIST_SIG = "Automation_Cla/filelist_sig_ttzut.txt"
FILELIST_BKG = "Automation_Cla/filelist_bkg.txt"
TTREE_NAME   = "Events"

BRANCHES = [
    "CutStep",
    "JetVetoSum",
    "MET_pt",
    "nGoodJet",
    "nBjet",
    "KinTopZq_mass",
]

def read_filelist(path):
    if not os.path.exists(path):
        print(f"[ERROR] Filelist not found: {path}", file=sys.stderr)
        return []
    out = []
    with open(path, "r") as f:
        for line in f:
            s = line.strip()
            if not s or s.startswith("#"):
                continue
            out.append(s)
    return out

def print_result(label, n_pass, n_total):
    eff = (n_pass / n_total) if n_total > 0 else 0.0
    print(f"[{label}]")
    print(f"  Total events     : {n_total}")
    print(f"  Passed selection : {n_pass}")
    print(f"  Efficiency       : {eff:.6f}")
    print("-" * 44)

def try_uproot_perfile(filelist):
    try:
        import numpy as np
        import uproot
    except Exception:
        return None  # trigger fallback

    n_total = 0
    n_pass  = 0
    for fn in filelist:
        try:
            with uproot.open(fn) as f:
                # explicitly pick the Events TTree
                if TTREE_NAME not in f:
                    raise KeyError(f"'{TTREE_NAME}' not found in {fn}")
                tree = f[TTREE_NAME]

                # iterate in chunks to keep memory bounded
                for arrays in tree.iterate(expressions=BRANCHES,
                                           step_size="100 MB",
                                           library="np"):
                    CutStep          = arrays["CutStep"]
                    JetVetoSum       = arrays["JetVetoSum"]
                    MET_pt           = arrays["MET_pt"]
                    nGoodJet         = arrays["nGoodJet"]
                    nBjet            = arrays["nBjet"]
                    KinTopZq_mass    = arrays["KinTopZq_mass"]

                    mask = (
                        (CutStep >= 1)
                        & (JetVetoSum < 9)
                        & (MET_pt > 30.0)
                        & (nGoodJet >= 2)
                        & (nBjet >= 1)
                        & (np.abs(KinTopZq_mass - 172.5) < 50.0)
                    )
                    n_total += CutStep.shape[0]
                    n_pass  += int(mask.sum())

        except Exception as e:
            # keep going even if a single file is bad
            print(f"[WARN] Skipping file (problem reading): {fn}\n        -> {e}", file=sys.stderr)
            continue

    return (n_pass, n_total)

def count_with_root_rdf(filelist):
    import ROOT
    ROOT.gROOT.SetBatch(True)
    ROOT.EnableImplicitMT()
    if not filelist:
        return (0, 0)

    v = ROOT.std.vector("string")()
    for fn in filelist:
        v.push_back(fn)

    cut_expr = (
        "(CutStep>=1)"
        " && (JetVetoSum<9)"
        " && (MET_pt>30.0)"
        " && (nGoodJet>=2)"
        " && (nBjet>=1)"
        " && (abs(KinTopZq_mass-172.5)<50.0)"
    )

    try:
        df = ROOT.RDataFrame(TTREE_NAME, v)
    except Exception as e:
        print(f"[ERROR] Could not create RDataFrame: {e}", file=sys.stderr)
        return (0, 0)

    n_total = int(df.Count().GetValue())
    n_pass  = int(df.Filter(cut_expr).Count().GetValue())
    return (n_pass, n_total)

def count_selected_events(label, filelist_paths):
    files = []
    for p in filelist_paths:
        files.extend(read_filelist(p))

    # uproot (per-file) first
    res = try_uproot_perfile(files)
    if res is None:
        # fallback to ROOT RDataFrame
        res = count_with_root_rdf(files)
    return res

def main():
    sig_pass, sig_total = count_selected_events("signal", [FILELIST_SIG])
    bkg_pass, bkg_total = count_selected_events("background", [FILELIST_BKG])

    print("=" * 44)
    print_result("Signal", sig_pass, sig_total)
    print_result("Background", bkg_pass, bkg_total)

if __name__ == "__main__":
    main()
