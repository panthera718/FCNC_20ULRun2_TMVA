import ROOT
import math

def check_histograms_in_root_file(filename):
    root_file = ROOT.TFile.Open(filename, "READ")
    if not root_file or root_file.IsZombie():
        print(f"Cannot open file: {filename}")
        return
    
    key_list = root_file.GetListOfKeys()
    for key in key_list:
        obj = key.ReadObj()
        if obj.InheritsFrom("TH1"):
            hist = obj
            hist_name = hist.GetName()
            
            found_problem = False
            nbins = hist.GetNbinsX()
            for i in range(1, nbins + 1):
                content = hist.GetBinContent(i)
                if math.isnan(content) or math.isinf(content):
                    found_problem = True
                    break
            
            if found_problem:
                print(f"{filename}: Histogram '{hist_name}' has invalid bin content (NaN).")
    
    root_file.Close()

if __name__ == "__main__":
    filenames = [
        "Run2_st1zct_ElElEl/ST1zct_20UL16postVFP_ElElEl.root",
        "Run2_st1zct_ElMuMu/ST1zct_20UL16postVFP_ElMuMu.root",
        "Run2_st1zct_MuElEl/ST1zct_20UL16postVFP_MuElEl.root",
        "Run2_st1zct_MuMuMu/ST1zct_20UL16postVFP_MuMuMu.root",
        "Run2_st1zut_ElElEl/ST1zut_20UL16postVFP_ElElEl.root",
        "Run2_st1zut_ElMuMu/ST1zut_20UL16postVFP_ElMuMu.root",
        "Run2_st1zut_MuElEl/ST1zut_20UL16postVFP_MuElEl.root",
        "Run2_st1zut_MuMuMu/ST1zut_20UL16postVFP_MuMuMu.root",
        "Run2_st2zct_ElElEl/ST2zct_20UL16postVFP_ElElEl.root",
        "Run2_st2zct_ElMuMu/ST2zct_20UL16postVFP_ElMuMu.root",
        "Run2_st2zct_MuElEl/ST2zct_20UL16postVFP_MuElEl.root",
        "Run2_st2zct_MuMuMu/ST2zct_20UL16postVFP_MuMuMu.root",
        "Run2_st2zut_ElElEl/ST2zut_20UL16postVFP_ElElEl.root",
        "Run2_st2zut_ElMuMu/ST2zut_20UL16postVFP_ElMuMu.root",
        "Run2_st2zut_MuElEl/ST2zut_20UL16postVFP_MuElEl.root",
        "Run2_st2zut_MuMuMu/ST2zut_20UL16postVFP_MuMuMu.root",
        "Run2_ttzct_ElElEl/TTzct_20UL16postVFP_ElElEl.root",
        "Run2_ttzct_ElMuMu/TTzct_20UL16postVFP_ElMuMu.root",
        "Run2_ttzct_MuElEl/TTzct_20UL16postVFP_MuElEl.root",
        "Run2_ttzct_MuMuMu/TTzct_20UL16postVFP_MuMuMu.root",
        "Run2_ttzut_ElElEl/TTzut_20UL16postVFP_ElElEl.root",
        "Run2_ttzut_ElMuMu/TTzut_20UL16postVFP_ElMuMu.root",
        "Run2_ttzut_MuElEl/TTzut_20UL16postVFP_MuElEl.root",
        "Run2_ttzut_MuMuMu/TTzut_20UL16postVFP_MuMuMu.root"
    ]
    for fn in filenames:
        print(f"Process for '{fn}'")
        check_histograms_in_root_file(fn)

