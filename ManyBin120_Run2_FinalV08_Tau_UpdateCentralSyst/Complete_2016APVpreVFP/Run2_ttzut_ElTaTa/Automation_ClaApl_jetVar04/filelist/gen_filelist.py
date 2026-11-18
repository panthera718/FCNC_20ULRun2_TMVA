import sys, os

#channel = ["ElTaTa", "MuElEl", "ElMuMu", "MuMuMu"]
channel = ["ElTaTa"]
#basedir = "%s/src/TMVA/Complete20UL18NanoAODv9"%os.getenv("CMSSW_BASE")
basedir = "/cms/ldap_home/yhoonlee/FCNCforApproval/TopLeptonMVA_Run2/FCNC_work/CMSSW_13_3_3/src/TMVA/Complete20UL1*v9"

nfolder = "HalfEvenMerged_FCNC_RunIISummer20UL16NanoAODAPVv9_jetVar04"
DATAandNPL_nfolder = "EventIDDataNPLMerged_FCNC_RunIISummer20UL16NanoAODAPVv9_central"

for k, ch in enumerate(channel):
    os.system("ls %s/%s/reco/%s/*NANOAOD/*.root > filelist_%s_data.txt"%(basedir,DATAandNPL_nfolder,ch,ch))
    os.system("ls %s/%s/reco/%s/TTZToLLNuNu*/*.root %s/%s/reco/%s/TTZToLL_M-1to10*/*.root > filelist_%s_ttZ.txt"%(basedir,nfolder,ch,basedir,nfolder,ch,ch))
    os.system("ls %s/%s/reco/%s/TTWJetsToLNu*/*.root %s/%s/reco/%s/TTWW*/*.root %s/%s/reco/%s/TTWZ*/*.root %s/%s/reco/%s/TTZZ*/*.root %s/%s/reco/%s/TTGamma_Dilept*/*.root %s/%s/reco/%s/ttHToNonbb*/*.root > filelist_%s_ttX.txt"%(basedir,nfolder,ch,basedir,nfolder,ch,basedir,nfolder,ch,basedir,nfolder,ch,basedir,nfolder,ch,basedir,nfolder,ch,ch))
    os.system("ls %s/%s/reco/%s/tZq_ll*/*.root > filelist_%s_tZq.txt"%(basedir,nfolder,ch,ch))
    os.system("ls %s/%s/reco/%s/TWZToLL*/*.root > filelist_%s_tWZ.txt"%(basedir,nfolder,ch,ch))
    os.system("ls %s/%s/reco/%s/WZTo3LNu*/*.root > filelist_%s_WZ.txt"%(basedir,nfolder,ch,ch))
    os.system("ls %s/%s/reco/%s/ZZ_TuneCP5*/*.root > filelist_%s_ZZ.txt"%(basedir,nfolder,ch,ch))
    os.system("ls %s/%s/reco/%s/WW_TuneCP5*/*.root %s/%s/reco/%s/GluGluToContinToZZTo*/*.root > filelist_%s_VV.txt"%(basedir,nfolder,ch,basedir,nfolder,ch,ch))

#    os.system("ls %s/%s/reco/%s/WWW_4F_TuneCP5*/*.root %s/%s/reco/%s/WWZ_4F_TuneCP5*/*.root > filelist_%s_WWV.txt"%(basedir,nfolder,ch,basedir,nfolder,ch,ch))
#    os.system("ls %s/%s/reco/%s/WZZ_TuneCP5*/*.root %s/%s/reco/%s/ZZZ_TuneCP5*/*.root > filelist_%s_ZZV.txt"%(basedir,nfolder,ch,basedir,nfolder,ch,ch))
    os.system("ls %s/%s/reco/%s/WWW_4F_TuneCP5*/*.root %s/%s/reco/%s/WWZ_4F_TuneCP5*/*.root %s/%s/reco/%s/WZZ_TuneCP5*/*.root %s/%s/reco/%s/ZZZ_TuneCP5*/*.root > filelist_%s_VVV.txt"%(basedir,nfolder,ch,basedir,nfolder,ch,basedir,nfolder,ch,basedir,nfolder,ch,ch))

    os.system("ls %s/%s/reco/%s/ZGToLLG_01J*/*.root %s/%s/reco/%s/WGToLNuG_01J*/*.root > filelist_%s_XGamma.txt"%(basedir,nfolder,ch,basedir,nfolder,ch,ch))
    os.system("ls %s/%s/reco/%s/TTTo*/*.root > filelist_%s_TT.txt"%(basedir,nfolder,ch,ch))

    os.system("ls %s/%s/reco/%s/ST_FCNC*zut*/*.root > filelist_%s_st1zut.txt"%(basedir,nfolder,ch,ch))
    os.system("ls %s/%s/reco/%s/ST_FCNC*zct*/*.root > filelist_%s_st1zct.txt"%(basedir,nfolder,ch,ch))
    os.system("ls %s/%s/reco/%s/ST_FCNC*zut*/*.root > filelist_%s_st2zut.txt"%(basedir,nfolder,ch,ch))
    os.system("ls %s/%s/reco/%s/ST_FCNC*zct*/*.root > filelist_%s_st2zct.txt"%(basedir,nfolder,ch,ch))
    os.system("ls %s/%s/reco/%s/TT_FCNC*zut*/*.root > filelist_%s_ttzut.txt"%(basedir,nfolder,ch,ch))
    os.system("ls %s/%s/reco/%s/TT_FCNC*zct*/*.root > filelist_%s_ttzct.txt"%(basedir,nfolder,ch,ch))

    os.system("ls %s/%s/reco/NPL%s/*NANOAOD/*.root > filelist_%s_dataNPL.txt"%(basedir,DATAandNPL_nfolder,ch,ch))
    os.system("ls %s/%s/reco/NPL%s/*NANOAODSIM/*.root > filelist_%s_mcNPL_dummy.txt"%(basedir,DATAandNPL_nfolder,ch,ch))
    with open("filelist_%s_mcNPL_dummy.txt"%(ch), "r") as txtfileDNPL:
        textDNPL=txtfileDNPL.readlines()
    with open("filelist_%s_mcNPL.txt"%(ch), "a") as txtfileNPL:
        for lineNPL in textDNPL:
            if "ST_FCNC" not in lineNPL and "TT_FCNC" not in lineNPL: txtfileNPL.write(lineNPL)
    print("File list generation for channel : %s is finished."%(ch))
