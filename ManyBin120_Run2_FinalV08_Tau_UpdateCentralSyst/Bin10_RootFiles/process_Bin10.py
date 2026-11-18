#!/usr/bin/env python3
import os
import glob
import array
import ROOT

def merge_hist_bins(input_path: str, output_path: str) -> None:
    """
    Open a ROOT file, merge bins 6-10 into one bin while keeping bins 1-5 and 11-15 unchanged,
    and write all histograms (rebinned 1D + untouched objects) into a new ROOT file.
    """
    # open input file
    f_in = ROOT.TFile.Open(input_path)
    if not f_in or f_in.IsZombie():
        raise IOError(f"Cannot open input file: {input_path}")

    # create (or overwrite) output file
    f_out = ROOT.TFile.Open(output_path, "RECREATE")
    if not f_out or f_out.IsZombie():
        raise IOError(f"Cannot create output file: {output_path}")

    # original histogram parameters
##    xmin, xmax = 0.25, 0.75
    # define custom bin boundaries exactly as specified:
    bin_0  = 0.0
    bin_1  = 0.1
    bin_2  = 0.2
    bin_3  = 0.3
    bin_4  = 0.4
    bin_5  = 0.5
    bin_6  = 0.6
    bin_7  = 0.7
    bin_8  = 0.8
    bin_9  = 0.9
    bin_10 = 1.0

    edges = [
        bin_0,
        bin_1,
        bin_2,
        bin_3,
        bin_4,
        bin_5,
        bin_6,
        bin_7,
        bin_8,
        bin_9,
        bin_10
    ]
    # pack into C-style double array
    new_edges_arr = array.array('d', edges)
    # number of new bins is one less than number of edges
    nbins_new = len(edges) - 1

    # loop over all objects in the input file
    for key in f_in.GetListOfKeys():
        obj = key.ReadObj()
        # if it's a 1D histogram, apply the custom rebin
        if obj.InheritsFrom("TH1") and obj.GetDimension() == 1:
            h = obj
            name  = h.GetName()
            title = h.GetTitle()

            # variable-bin rebin: merges bins 5-11 into one
            h2 = h.Rebin(nbins_new, name, new_edges_arr)
            h2.SetTitle(title)
            h2.SetDirectory(0)

            f_out.cd()
            h2.Write()
        else:
            # copy non-1D histograms or other objects unchanged
            f_out.cd()
            obj.Clone().Write()

    # close files
    f_out.Close()
    f_in.Close()


if __name__ == "__main__":
    # find all ROOT files in the specified directory
    input_dir = "../ManyBin120_FinalV04_nbin120_RootFiles"
    pattern   = os.path.join(input_dir, "*.root")
    files     = glob.glob(pattern)

    if not files:
        print(f"No ROOT files found in {input_dir}")
        sys.exit(1)

    # process each file
    for in_file in files:
        out_file = os.path.join(os.getcwd(), os.path.basename(in_file))
        out_file = out_file.replace("_Tau_data_obs.root", "_Tau_nbin10_data_obs.root")
        print(f"Processing {in_file} -> {out_file}")
        merge_hist_bins(in_file, out_file)

    print("Done.")
