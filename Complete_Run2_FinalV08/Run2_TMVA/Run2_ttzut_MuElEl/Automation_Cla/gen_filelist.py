import sys, os

channel = ["MuElEl"]
basedir = "/cms/ldap_home/yhoonlee/FCNCforApproval/TopLeptonMVA_Run2/FCNC_work/CMSSW_13_3_3/src/TMVA/Complete20UL1*v9"

nfolder = "HalfOddMerged_FCNC_RunIISummer20UL1*v9_central"
for j, ch in enumerate(channel):
    os.system("ls %s/%s/reco/%s/*NANOAODSIM/*.root > filelist_bkg_dummy_%s.txt"%(basedir,nfolder,ch,ch))
    with open("filelist_bkg_dummy_%s.txt" % ch, "r") as txtfileD:
        textD=txtfileD.readlines()
    with open("filelist_bkg.txt", "a") as txtfile:
        for line in textD:
            if "ST_FCNC" not in line and "TT_FCNC" not in line: txtfile.write(line)

sig_nfolder = "HalfOddMerged_FCNC_RunIISummer20UL1*v9_central"
#os.system("ls %s/%s/reco/El*/ST_FCNC*zut*/*.root %s/%s/reco/Mu*/ST_FCNC*zut*/*.root > filelist_sig_stzut.txt"%(basedir,sig_nfolder,basedir,sig_nfolder))
#os.system("ls %s/%s/reco/El*/ST_FCNC*zct*/*.root %s/%s/reco/Mu*/ST_FCNC*zct*/*.root > filelist_sig_stzct.txt"%(basedir,sig_nfolder,basedir,sig_nfolder))
#os.system("ls %s/%s/reco/El*/TT_FCNC*zut*/*.root %s/%s/reco/Mu*/TT_FCNC*zut*/*.root > filelist_sig_ttzut.txt"%(basedir,sig_nfolder,basedir,sig_nfolder))
#os.system("ls %s/%s/reco/El*/TT_FCNC*zct*/*.root %s/%s/reco/Mu*/TT_FCNC*zct*/*.root > filelist_sig_ttzct.txt"%(basedir,sig_nfolder,basedir,sig_nfolder))
os.system("ls %s/%s/reco/MuElEl/ST_FCNC*zut*/*.root > filelist_sig_stzut.txt"%(basedir,sig_nfolder))
os.system("ls %s/%s/reco/MuElEl/ST_FCNC*zct*/*.root > filelist_sig_stzct.txt"%(basedir,sig_nfolder))
os.system("ls %s/%s/reco/MuElEl/TT_FCNC*zut*/*.root > filelist_sig_ttzut.txt"%(basedir,sig_nfolder))
os.system("ls %s/%s/reco/MuElEl/TT_FCNC*zct*/*.root > filelist_sig_ttzct.txt"%(basedir,sig_nfolder))
print("File list generation for central signal is finished.")
