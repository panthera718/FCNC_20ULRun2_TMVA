import ROOT

def ModifyHistograms(input_filename, output_filename):
    oldFile = ROOT.TFile.Open(input_filename, "READ")
    if not oldFile or oldFile.IsZombie():
        print(f"Error: Cannot open input file {input_filename}")
        return

    newFile = ROOT.TFile.Open(output_filename, "RECREATE")
    if not newFile or newFile.IsZombie():
        print(f"Error: Cannot create output file {output_filename}")
        oldFile.Close()
        return

    keys = oldFile.GetListOfKeys()
    if not keys:
        print("Error: No keys found in the input file.")
        oldFile.Close()
        newFile.Close()
        return

    nKeys = keys.GetEntries()

    for i in range(nKeys):
        key = keys.At(i)
        if not key:
            continue

        classname = key.GetClassName()
        cl = ROOT.gROOT.GetClass(classname)
        if not cl:
            continue

        if cl.InheritsFrom("TH1"):
            h = key.ReadObj()
            if not h:
                continue

            nbins = h.GetNbinsX()
            for bin_idx in range(1, nbins + 1):
                content = h.GetBinContent(bin_idx)
                if content <= 0:
                    h.SetBinContent(bin_idx, 0)

            newFile.cd()
            h.Write(h.GetName())
        else:
            pass

    newFile.Close()
    oldFile.Close()

    print(f"Histograms modified and saved to {output_filename}")

if __name__ == "__main__":
    ModifyHistograms(input_filename="TTzut_20UL18_Tau_nbin15_Base.root", output_filename="TTzut_20UL18_Tau_nbin15_Base_New.root")
    ModifyHistograms(input_filename="TTzut_20UL18_Tau_nbin10_Base.root", output_filename="TTzut_20UL18_Tau_nbin10_Base_New.root")
    ModifyHistograms(input_filename="TTzut_20UL18_Tau_nbin5_Base.root",  output_filename="TTzut_20UL18_Tau_nbin5_Base_New.root")
