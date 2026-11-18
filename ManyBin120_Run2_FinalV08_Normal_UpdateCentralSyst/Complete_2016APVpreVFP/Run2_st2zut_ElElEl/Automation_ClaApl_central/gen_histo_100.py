import sys, os

###############################################
###   This code do not contain DATA shape.  ###
### Shapes for Data should be run manually. ###
###############################################

sigchannel = "st2zut"

SYS = ["central"]
#sub_SYS1 = [
#
#]
#sub_SYS2 = ["Up", "Down"]
#for range_sub_SYS1 in range(len(sub_SYS1)):
#    for range_sub_SYS2 in range(len(sub_SYS2)):
#        SYS_element = sub_SYS1[range_sub_SYS1] + sub_SYS2[range_sub_SYS2]
#        SYS.append(SYS_element)

#CH = ["ElElEl", "MuElEl", "ElMuMu", "MuMuMu"]
CH = ["ElElEl"]

#MC = [sigchannel, "ttZ", "ttX", "tZq", "tWZ", "WZ", "ZZ", "VV", "WWV", "ZZV", "XGamma", "Nonprompt"]
MC = [sigchannel, "ttZ", "ttX", "tZq", "tWZ", "WZ", "ZZ", "VV", "VVV", "XGamma", "TT"]

# TMVA Variables : fix manually.
originVARS = [
    "TriLepton_pt",
    "TriLepton_mass",
    "TriLepton_WleptonZdR",
    "TriLepton_WleptonZdPhi",
    "Z_mass",
    "W_MT",
    "MET_pt",
    "MET_phi",
    "KinTopWb_pt",
    "KinTopWb_eta",
    "KinTopWb_phi",
    "KinTopWb_mass",
    "MVAinput_WLZL1_dR",
    "MVAinput_WLZL1_dPhi",
    "MVAinput_WLZL1_dEta",
    "MVAinput_WLZL2_dR",
    "MVAinput_WLZL2_dPhi",
    "MVAinput_WLZL2_dEta",
    "MVAinput_ZL1ZL2_dR",
    "MVAinput_ZL1ZL2_dPhi",
    "MVAinput_ZL1ZL2_dEta",
    "MVAinput_Wlepchapt",
    "MVAinput_Wlepchaeta",
    "MVAinput_WJ_DeepJetB",
    "MVAinput_WJ_pt",
    "MVAinput_WLWJ_dR",
    "MVAinput_WLWJ_dPhi",
    "MVAinput_WLWJ_dEta",
    "MVAinput_ZL1WJ_dR",
    "MVAinput_ZL1WJ_dPhi",
    "MVAinput_ZL1WJ_dEta",
    "MVAinput_ZL2WJ_dR",
    "MVAinput_ZL2WJ_dPhi",
    "MVAinput_ZL2WJ_dEta",
    "MVAinput_Z_WJ_dR",
    "MVAinput_Z_WJ_dPhi",
    "MVAinput_Z_WJ_dEta"
]

# STSR
DEFAULT_cut = "!((CutStep>=1)&&(JetVetoSum<9)&&(MET_pt>30.0)&&(nGoodJet>=2)&&(nBjet>=1)&&(TMath::Abs(KinTopZq_mass-172.5)>50.0)&&(TMath::Abs(KinTopWb_mass-172.5)<60.0))"
# TTSR
#DEFAULT_cut = "!((CutStep>=1)&&(nGoodJet>=2)&&(nBjet>=1)&&(JetVetoSum<9)&&((TMath::Power(((KinTopWb_mass-172.5)/60.0),2)+TMath::Power(((KinTopZq_mass-172.5)/50.0),2))<1.0))"

for i, channel in enumerate(CH):
    for j, syst in enumerate(SYS):

        # MC
        for k, mc in enumerate(MC):

            # Prompt MC
            if mc != "Nonprompt":
                DEFAULT_mc = mc

                print("========================================")
                print("Process for : %s_%s_%s"%(channel, syst, DEFAULT_mc))
                print("========================================")

                if "st1" in sigchannel:
                    DEFAULT_ch = "ST1"+channel
                elif "st2" in sigchannel:
                    DEFAULT_ch = "ST2"+channel
                elif "tt" in sigchannel:
                    DEFAULT_ch = "TT"+channel
                # Central
                if (syst == "central"):
#                    fileName = "TMVAClassificationApplication_%s_%s.C"%(DEFAULT_ch, DEFAULT_mc)
                    if DEFAULT_mc == sigchannel and "st" in sigchannel:
                        fileName = "TMVAClassificationApplication_%s_%s_OneHundred.C"%(DEFAULT_ch, DEFAULT_mc)
                        os.system("cp ../../Default_ST/Default_central_OneHundred_STFCNCsig.C %s"%fileName)
                    elif DEFAULT_mc == sigchannel and "tt" in sigchannel:
                        fileName = "TMVAClassificationApplication_%s_%s_OneHundredTwo.C"%(DEFAULT_ch, DEFAULT_mc)
                        os.system("cp ../../Default_ST/Default_central_OneHundredTwo_TTFCNCsig.C %s"%fileName)
#                    elif DEFAULT_mc in ["ttZ", "ttX", "tWZ", "WZ", "XGamma", "ZZV"]:
#                        fileName = "TMVAClassificationApplication_%s_%s_OneHundredTwo.C"%(DEFAULT_ch, DEFAULT_mc)
#                        os.system("cp ../../Default_ST/Default_central_OneHundredTwo.C %s"%fileName)
#                    elif DEFAULT_mc in ["tZq", "WWV"]:
#                        fileName = "TMVAClassificationApplication_%s_%s_OneHundred.C"%(DEFAULT_ch, DEFAULT_mc)
#                        os.system("cp ../../Default_ST/Default_central_OneHundred.C %s"%fileName)
#                    elif DEFAULT_mc in ["ZZ", "VV"]:
#                        fileName = "TMVAClassificationApplication_%s_%s.C"%(DEFAULT_ch, DEFAULT_mc)
#                        os.system("cp ../../Default_ST/Default_central.C %s"%fileName)
                    else:
                        fileName = "TMVAClassificationApplication_%s_%s.C"%(DEFAULT_ch, DEFAULT_mc)
                        os.system("cp ../../Default_ST/Default_central.C %s"%fileName)
                    DEFAULT_sys = ""
                else:
                    DEFAULT_sys = syst
                    fileName = "TMVAClassificationApplication_%s_%s_%s.C"%(DEFAULT_ch, DEFAULT_sys, DEFAULT_mc)
                    if DEFAULT_mc == sigchannel and "st" in sigchannel:
                        os.system("cp ../../Default_ST/Default_syst_STFCNCsig.C %s"%fileName)
                    elif DEFAULT_mc == sigchannel and "tt" in sigchannel:
                        os.system("cp ../../Default_ST/Default_syst_TTFCNCsig.C %s"%fileName)
                    else:
                        os.system("cp ../../Default_ST/Default_syst.C %s"%fileName)
                    os.system("sed -i 's|_DEF_SYS_|%s|g' %s"%(DEFAULT_sys, fileName))

                # The name of .txt file which is listing the .root files
#                DEFAULT_txt = "filelist/filelist_"+syst+"_"+channel+"_"+mc+".txt"
                DEFAULT_txt = "filelist/filelist_"+channel+"_"+mc+".txt"

                # Change appropriate strings in the copied TMVAClassApp file.
                for l, originvar in enumerate(originVARS):
                    os.system("sed -i 's|_DEF_VAR%i_|%s|g' %s"%(l, originvar, fileName))
                if (syst != "central"):
                    os.system("sed -i 's|_JETVAR_|%s|g' %s"%(syst, fileName))
                    if ("Up" == syst[-2:]):
                        midname = "up_jes"
                        systoriginal = syst[:-2]
                    elif ("Down" == syst[-4:]):
                        midname = "down_jes"
                        systoriginal = syst[:-4]
                    systofjes = "%s_%s" % (midname, syst)
                    os.system("sed -i 's|_JETVARofJES_|%s|g' %s"%(systofjes, fileName))
                os.system("sed -i 's|_DEF_CH_|%s|g' %s"%(DEFAULT_ch, fileName))
                os.system("sed -i 's|_DEF_MC_|%s|g' %s"%(DEFAULT_mc, fileName))
                os.system("sed -i 's|_DEF_TEXT_|%s|g' %s"%(DEFAULT_txt, fileName))
                os.system("sed -i 's|_DEF_CUT_|%s|g' %s"%(DEFAULT_cut, fileName))
                # For fix bug
                os.system("sed -i 's|_DEF_CUT_|\&|g' TMVAClassificationApplication*")

                # Run the code
                os.system("root -l -q %s"%fileName)

                # Delete the code
                os.system("rm %s"%fileName)

            # Nonprompt MC
            if (syst == "central") and (mc == "Nonprompt"):
                DEFAULT_NPL = mc

                print("========================================")
                print("Process for : %s_%s_%s"%(channel, syst, DEFAULT_NPL))
                print("========================================")

                if "st1" in sigchannel:
                    DEFAULT_ch = "ST1"+channel
                elif "st2" in sigchannel:
                    DEFAULT_ch = "ST2"+channel
                elif "tt" in sigchannel:
                    DEFAULT_ch = "TT"+channel

                ##########################
                # Nonprompt MC : dataNPL #
                ##########################
                # The name of .txt file which is listing the .root files
#                DEFAULT_dataNPL_txt = "filelist/filelist_"+syst+"_"+channel+"_"+"dataNPL"+".txt"
                DEFAULT_dataNPL_txt = "filelist/filelist_"+channel+"_"+"dataNPL"+".txt"
                DEFAULT_data_NPL = DEFAULT_NPL+"_dataNPL"

                # Central
                if (syst == "central"):
                    fileName_dataNPL = "TMVAClassificationApplication_%s_%s.C"%(DEFAULT_ch, DEFAULT_data_NPL)
                    os.system("cp ../../Default_ST/Default_central_dataNPL.C %s"%fileName_dataNPL)
                    DEFAULT_sys = ""
                else:
                    DEFAULT_sys = syst
                    fileName_dataNPL = "TMVAClassificationApplication_%s_%s_%s.C"%(DEFAULT_ch, DEFAULT_sys, DEFAULT_data_NPL)
                    os.system("cp ../../Default_ST/Default_syst_dataNPL.C %s"%fileName_dataNPL)
                    os.system("sed -i 's|_DEF_SYS_|%s|g' %s"%(DEFAULT_sys, fileName_dataNPL))

                # Change appropriate strings in the copied TMVAClassApp file.
                for l, originvar in enumerate(originVARS):
                    os.system("sed -i 's|_DEF_VAR%i_|%s|g' %s"%(l, originvar, fileName_dataNPL))
                if (syst != "central"):
                    os.system("sed -i 's|_JETVAR_|%s|g' %s"%(syst, fileName_dataNPL))
                    if ("Up" == syst[-2:]):
                        midname = "Up_up_jes"
                        systoriginal = syst[:-2]
                    elif ("Down" == syst[-4:]):
                        midname = "Down_down_jes"
                        systoriginal = syst[:-4]
                    systofjes = "%s%s%s" % (systoriginal, midname, systoriginal)
                    os.system("sed -i 's|_JETVARofJES_|%s|g' %s"%(systofjes, fileName_dataNPL))
                os.system("sed -i 's|_DEF_CH_|%s|g' %s"%(DEFAULT_ch, fileName_dataNPL))
                os.system("sed -i 's|_DEF_MC_|%s|g' %s"%(DEFAULT_NPL, fileName_dataNPL))
                os.system("sed -i 's|_DEF_TEXT_|%s|g' %s"%(DEFAULT_dataNPL_txt, fileName_dataNPL))
                os.system("sed -i 's|_DEF_CUT_|%s|g' %s"%(DEFAULT_cut, fileName_dataNPL))
                # For fix bug
                os.system("sed -i 's|_DEF_CUT_|\&|g' TMVAClassificationApplication*")

                # Run the code
                os.system("root -l -q %s"%fileName_dataNPL)

                # Delete the code
                os.system("rm %s"%fileName_dataNPL)

                ########################
                # Nonprompt MC : mcNPL #
                ########################
                # The name of .txt file which is listing the .root files
#                DEFAULT_mcNPL_txt = "filelist/filelist_"+syst+"_"+channel+"_"+"mcNPL"+".txt"
                DEFAULT_mcNPL_txt = "filelist/filelist_"+channel+"_"+"mcNPL"+".txt"
                DEFAULT_mc_NPL = DEFAULT_NPL+"_mcNPL"

                # Central
                if (syst == "central"):
                    fileName_mcNPL = "TMVAClassificationApplication_%s_%s.C"%(DEFAULT_ch, DEFAULT_mc_NPL)
                    os.system("cp ../../Default_ST/Default_central_mcNPL.C %s"%fileName_mcNPL)
                    DEFAULT_sys = ""
                else:
                    DEFAULT_sys = syst
                    fileName_mcNPL = "TMVAClassificationApplication_%s_%s_%s.C"%(DEFAULT_ch, DEFAULT_sys, DEFAULT_mc_NPL)
                    os.system("cp ../../Default_ST/Default_syst_mcNPL.C %s"%fileName_mcNPL)
                    os.system("sed -i 's|_DEF_SYS_|%s|g' %s"%(DEFAULT_sys, fileName_mcNPL))

                # Change appropriate strings in the copied TMVAClassApp file.
                for l, originvar in enumerate(originVARS):
                    os.system("sed -i 's|_DEF_VAR%i_|%s|g' %s"%(l, originvar, fileName_mcNPL))
                if (syst != "central"):
                    os.system("sed -i 's|_JETVAR_|%s|g' %s"%(syst, fileName_mcNPL))
                os.system("sed -i 's|_DEF_CH_|%s|g' %s"%(DEFAULT_ch, fileName_mcNPL))
                os.system("sed -i 's|_DEF_MC_|%s|g' %s"%(DEFAULT_NPL, fileName_mcNPL))
                os.system("sed -i 's|_DEF_TEXT_|%s|g' %s"%(DEFAULT_mcNPL_txt, fileName_mcNPL))
                os.system("sed -i 's|_DEF_CUT_|%s|g' %s"%(DEFAULT_cut, fileName_mcNPL))
                # For fix bug
                os.system("sed -i 's|_DEF_CUT_|\&|g' TMVAClassificationApplication*")

                # Run the code
                os.system("root -l -q %s"%fileName_mcNPL)

                # Delete the code
                os.system("rm %s"%fileName_mcNPL)

                ##################################
                # Nonprompt MC = dataNPL - mcNPL #
                ##################################
                if (syst == "central"):
                    os.system("hadd %s_%s_orig.root %s_%s_dataNPL.root %s_%s_mcNPL.root"%(DEFAULT_ch,DEFAULT_NPL,DEFAULT_ch,DEFAULT_NPL,DEFAULT_ch,DEFAULT_NPL))
                    os.system("rm %s_%s_dataNPL.root %s_%s_mcNPL.root"%(DEFAULT_ch,DEFAULT_NPL,DEFAULT_ch,DEFAULT_NPL))

                    os.system("root -l -b -q 'getNewHistogram.C(\"%s_%s_orig.root\", \"%s_%s\", \"%s_%s.root\", \"%s_%s\")'"%(DEFAULT_ch,DEFAULT_NPL,DEFAULT_ch,DEFAULT_NPL,DEFAULT_ch,DEFAULT_NPL,DEFAULT_ch,DEFAULT_NPL))
#                    os.system("rm %s_%s_orig.root"%(DEFAULT_ch,DEFAULT_NPL))

                else:
                    os.system("hadd %s_%s_%s_orig.root %s_%s_%s_dataNPL.root %s_%s_%s_mcNPL.root"%(DEFAULT_ch,DEFAULT_NPL,DEFAULT_sys,DEFAULT_ch,DEFAULT_NPL,DEFAULT_sys,DEFAULT_ch,DEFAULT_NPL,DEFAULT_sys))
                    os.system("rm %s_%s_%s_dataNPL.root %s_%s_%s_mcNPL.root"%(DEFAULT_ch,DEFAULT_NPL,DEFAULT_sys,DEFAULT_ch,DEFAULT_NPL,DEFAULT_sys))

                    os.system("root -l -b -q 'getNewHistogram.C(\"%s_%s_%s_orig.root\", \"%s_%s_%s\", \"%s_%s_%s.root\", \"%s_%s_%s\")'"%(DEFAULT_ch,DEFAULT_NPL,DEFAULT_sys,DEFAULT_ch,DEFAULT_NPL,DEFAULT_sys,DEFAULT_ch,DEFAULT_NPL,DEFAULT_sys,DEFAULT_ch,DEFAULT_NPL,DEFAULT_sys))
                    os.system("rm %s_%s_%s_orig.root"%(DEFAULT_ch,DEFAULT_NPL,DEFAULT_sys))

            if (syst == "central") and (mc == "Nonprompt"):

                ###########################
                # Nonprompt MC: Get Error #
                ###########################



                ####################################
                # Nonprompt MC : dataNPL FRErrorUp #
                ####################################
                # The name of .txt file which is listing the .root files
#                DEFAULT_dataNPL_txt = "filelist/filelist_"+syst+"_"+channel+"_"+"dataNPL"+".txt"
                DEFAULT_dataNPL_txt = "filelist/filelist_"+channel+"_"+"dataNPL"+".txt"
                DEFAULT_data_NPL_FRErrorUp = DEFAULT_NPL+"_dataNPL_FRErrorUp"

                # Central
                fileName_dataNPL_FRErrorUp = "TMVAClassificationApplication_%s_%s.C"%(DEFAULT_ch, DEFAULT_data_NPL_FRErrorUp)
                os.system("cp ../../Default_ST/Default_central_dataNPL_FRErrorUp.C %s"%fileName_dataNPL_FRErrorUp)
                DEFAULT_sys = ""

                # Change appropriate strings in the copied TMVAClassApp file.
                for l, originvar in enumerate(originVARS):
                    os.system("sed -i 's|_DEF_VAR%i_|%s|g' %s"%(l, originvar, fileName_dataNPL_FRErrorUp))
                os.system("sed -i 's|_DEF_CH_|%s|g' %s"%(DEFAULT_ch, fileName_dataNPL_FRErrorUp))
                os.system("sed -i 's|_DEF_MC_|%s|g' %s"%(DEFAULT_NPL, fileName_dataNPL_FRErrorUp))
                os.system("sed -i 's|_DEF_TEXT_|%s|g' %s"%(DEFAULT_dataNPL_txt, fileName_dataNPL_FRErrorUp))
                os.system("sed -i 's|_DEF_CUT_|%s|g' %s"%(DEFAULT_cut, fileName_dataNPL_FRErrorUp))
                # For fix bug
                os.system("sed -i 's|_DEF_CUT_|\&|g' TMVAClassificationApplication*")

                # Run the code
                os.system("root -l -q %s"%fileName_dataNPL_FRErrorUp)

                # Delete the code
                os.system("rm %s"%fileName_dataNPL_FRErrorUp)

                ##################################
                # Nonprompt MC : mcNPL FRErrorUp #
                ##################################
                # The name of .txt file which is listing the .root files
#                DEFAULT_mcNPL_txt = "filelist/filelist_"+syst+"_"+channel+"_"+"mcNPL"+".txt"
                DEFAULT_mcNPL_txt = "filelist/filelist_"+channel+"_"+"mcNPL"+".txt"
                DEFAULT_mc_NPL_FRErrorUp = DEFAULT_NPL+"_mcNPL_FRErrorUp"

                # Central
                fileName_mcNPL_FRErrorUp = "TMVAClassificationApplication_%s_%s.C"%(DEFAULT_ch, DEFAULT_mc_NPL_FRErrorUp)
                os.system("cp ../../Default_ST/Default_central_mcNPL_FRErrorUp.C %s"%fileName_mcNPL_FRErrorUp)
                DEFAULT_sys = ""

                # Change appropriate strings in the copied TMVAClassApp file.
                for l, originvar in enumerate(originVARS):
                    os.system("sed -i 's|_DEF_VAR%i_|%s|g' %s"%(l, originvar, fileName_mcNPL_FRErrorUp))
                os.system("sed -i 's|_DEF_CH_|%s|g' %s"%(DEFAULT_ch, fileName_mcNPL_FRErrorUp))
                os.system("sed -i 's|_DEF_MC_|%s|g' %s"%(DEFAULT_NPL, fileName_mcNPL_FRErrorUp))
                os.system("sed -i 's|_DEF_TEXT_|%s|g' %s"%(DEFAULT_mcNPL_txt, fileName_mcNPL_FRErrorUp))
                os.system("sed -i 's|_DEF_CUT_|%s|g' %s"%(DEFAULT_cut, fileName_mcNPL_FRErrorUp))
                # For fix bug
                os.system("sed -i 's|_DEF_CUT_|\&|g' TMVAClassificationApplication*")

                # Run the code
                os.system("root -l -q %s"%fileName_mcNPL_FRErrorUp)

                # Delete the code
                os.system("rm %s"%fileName_mcNPL_FRErrorUp)

                ######################################################################
                # "Nonprompt MC FRErrorUp" = "dataNPL FRErrorUp" + "mcNPL FRErrorUp" #
                ######################################################################
                os.system("hadd %s_%s_FRErrorUp.root %s_%s_dataNPL_FRErrorUp.root %s_%s_mcNPL_FRErrorUp.root"%(DEFAULT_ch,DEFAULT_NPL,DEFAULT_ch,DEFAULT_NPL,DEFAULT_ch,DEFAULT_NPL))
                os.system("rm %s_%s_dataNPL_FRErrorUp.root %s_%s_mcNPL_FRErrorUp.root"%(DEFAULT_ch,DEFAULT_NPL,DEFAULT_ch,DEFAULT_NPL))



                ######################################
                # Nonprompt MC : dataNPL FRErrorDown #
                ######################################
                # The name of .txt file which is listing the .root files
#                DEFAULT_dataNPL_txt = "filelist/filelist_"+syst+"_"+channel+"_"+"dataNPL"+".txt"
                DEFAULT_dataNPL_txt = "filelist/filelist_"+channel+"_"+"dataNPL"+".txt"
                DEFAULT_data_NPL_FRErrorDown = DEFAULT_NPL+"_dataNPL_FRErrorDown"

                # Central
                fileName_dataNPL_FRErrorDown = "TMVAClassificationApplication_%s_%s.C"%(DEFAULT_ch, DEFAULT_data_NPL_FRErrorDown)
                os.system("cp ../../Default_ST/Default_central_dataNPL_FRErrorDown.C %s"%fileName_dataNPL_FRErrorDown)
                DEFAULT_sys = ""

                # Change appropriate strings in the copied TMVAClassApp file.
                for l, originvar in enumerate(originVARS):
                    os.system("sed -i 's|_DEF_VAR%i_|%s|g' %s"%(l, originvar, fileName_dataNPL_FRErrorDown))
                os.system("sed -i 's|_DEF_CH_|%s|g' %s"%(DEFAULT_ch, fileName_dataNPL_FRErrorDown))
                os.system("sed -i 's|_DEF_MC_|%s|g' %s"%(DEFAULT_NPL, fileName_dataNPL_FRErrorDown))
                os.system("sed -i 's|_DEF_TEXT_|%s|g' %s"%(DEFAULT_dataNPL_txt, fileName_dataNPL_FRErrorDown))
                os.system("sed -i 's|_DEF_CUT_|%s|g' %s"%(DEFAULT_cut, fileName_dataNPL_FRErrorDown))
                # For fix bug
                os.system("sed -i 's|_DEF_CUT_|\&|g' TMVAClassificationApplication*")

                # Run the code
                os.system("root -l -q %s"%fileName_dataNPL_FRErrorDown)

                # Delete the code
                os.system("rm %s"%fileName_dataNPL_FRErrorDown)

                ####################################
                # Nonprompt MC : mcNPL FRErrorDown #
                ####################################
                # The name of .txt file which is listing the .root files
#                DEFAULT_mcNPL_txt = "filelist/filelist_"+syst+"_"+channel+"_"+"mcNPL"+".txt"
                DEFAULT_mcNPL_txt = "filelist/filelist_"+channel+"_"+"mcNPL"+".txt"
                DEFAULT_mc_NPL_FRErrorDown = DEFAULT_NPL+"_mcNPL_FRErrorDown"

                # Central
                fileName_mcNPL_FRErrorDown = "TMVAClassificationApplication_%s_%s.C"%(DEFAULT_ch, DEFAULT_mc_NPL_FRErrorDown)
                os.system("cp ../../Default_ST/Default_central_mcNPL_FRErrorDown.C %s"%fileName_mcNPL_FRErrorDown)
                DEFAULT_sys = ""

                # Change appropriate strings in the copied TMVAClassApp file.
                for l, originvar in enumerate(originVARS):
                    os.system("sed -i 's|_DEF_VAR%i_|%s|g' %s"%(l, originvar, fileName_mcNPL_FRErrorDown))
                os.system("sed -i 's|_DEF_CH_|%s|g' %s"%(DEFAULT_ch, fileName_mcNPL_FRErrorDown))
                os.system("sed -i 's|_DEF_MC_|%s|g' %s"%(DEFAULT_NPL, fileName_mcNPL_FRErrorDown))
                os.system("sed -i 's|_DEF_TEXT_|%s|g' %s"%(DEFAULT_mcNPL_txt, fileName_mcNPL_FRErrorDown))
                os.system("sed -i 's|_DEF_CUT_|%s|g' %s"%(DEFAULT_cut, fileName_mcNPL_FRErrorDown))
                # For fix bug
                os.system("sed -i 's|_DEF_CUT_|\&|g' TMVAClassificationApplication*")

                # Run the code
                os.system("root -l -q %s"%fileName_mcNPL_FRErrorDown)

                # Delete the code
                os.system("rm %s"%fileName_mcNPL_FRErrorDown)

                ############################################################################
                # "Nonprompt MC FRErrorDown" = "dataNPL FRErrorDown" + "mcNPL FRErrorDown" #
                ############################################################################
                os.system("hadd %s_%s_FRErrorDown.root %s_%s_dataNPL_FRErrorDown.root %s_%s_mcNPL_FRErrorDown.root"%(DEFAULT_ch,DEFAULT_NPL,DEFAULT_ch,DEFAULT_NPL,DEFAULT_ch,DEFAULT_NPL))
                os.system("rm %s_%s_dataNPL_FRErrorDown.root %s_%s_mcNPL_FRErrorDown.root"%(DEFAULT_ch,DEFAULT_NPL,DEFAULT_ch,DEFAULT_NPL))



                ################################
                # Nonprompt MC : dataNPL NonFR #
                ################################
                # The name of .txt file which is listing the .root files
#                DEFAULT_dataNPL_txt = "filelist/filelist_"+syst+"_"+channel+"_"+"dataNPL"+".txt"
                DEFAULT_dataNPL_txt = "filelist/filelist_"+channel+"_"+"dataNPL"+".txt"
                DEFAULT_data_NPL_NonFR = DEFAULT_NPL+"_dataNPL_NonFR"

                # Central
                fileName_dataNPL_NonFR = "TMVAClassificationApplication_%s_%s.C"%(DEFAULT_ch, DEFAULT_data_NPL_NonFR)
                os.system("cp ../../Default_ST/Default_central_dataNPL_NonFR.C %s"%fileName_dataNPL_NonFR)
                DEFAULT_sys = ""

                # Change appropriate strings in the copied TMVAClassApp file.
                for l, originvar in enumerate(originVARS):
                    os.system("sed -i 's|_DEF_VAR%i_|%s|g' %s"%(l, originvar, fileName_dataNPL_NonFR))
                os.system("sed -i 's|_DEF_CH_|%s|g' %s"%(DEFAULT_ch, fileName_dataNPL_NonFR))
                os.system("sed -i 's|_DEF_MC_|%s|g' %s"%(DEFAULT_NPL, fileName_dataNPL_NonFR))
                os.system("sed -i 's|_DEF_TEXT_|%s|g' %s"%(DEFAULT_dataNPL_txt, fileName_dataNPL_NonFR))
                os.system("sed -i 's|_DEF_CUT_|%s|g' %s"%(DEFAULT_cut, fileName_dataNPL_NonFR))
                # For fix bug
                os.system("sed -i 's|_DEF_CUT_|\&|g' TMVAClassificationApplication*")

                # Run the code
                os.system("root -l -q %s"%fileName_dataNPL_NonFR)

                # Delete the code
                os.system("rm %s"%fileName_dataNPL_NonFR)

                ##############################
                # Nonprompt MC : mcNPL NonFR #
                ##############################
                # The name of .txt file which is listing the .root files
#                DEFAULT_mcNPL_txt = "filelist/filelist_"+syst+"_"+channel+"_"+"mcNPL"+".txt"
                DEFAULT_mcNPL_txt = "filelist/filelist_"+channel+"_"+"mcNPL"+".txt"
                DEFAULT_mc_NPL_NonFR = DEFAULT_NPL+"_mcNPL_NonFR"

                # Central
                fileName_mcNPL_NonFR = "TMVAClassificationApplication_%s_%s.C"%(DEFAULT_ch, DEFAULT_mc_NPL_NonFR)
                os.system("cp ../../Default_ST/Default_central_mcNPL_NonFR.C %s"%fileName_mcNPL_NonFR)
                DEFAULT_sys = ""

                # Change appropriate strings in the copied TMVAClassApp file.
                for l, originvar in enumerate(originVARS):
                    os.system("sed -i 's|_DEF_VAR%i_|%s|g' %s"%(l, originvar, fileName_mcNPL_NonFR))
                os.system("sed -i 's|_DEF_CH_|%s|g' %s"%(DEFAULT_ch, fileName_mcNPL_NonFR))
                os.system("sed -i 's|_DEF_MC_|%s|g' %s"%(DEFAULT_NPL, fileName_mcNPL_NonFR))
                os.system("sed -i 's|_DEF_TEXT_|%s|g' %s"%(DEFAULT_mcNPL_txt, fileName_mcNPL_NonFR))
                os.system("sed -i 's|_DEF_CUT_|%s|g' %s"%(DEFAULT_cut, fileName_mcNPL_NonFR))
                # For fix bug
                os.system("sed -i 's|_DEF_CUT_|\&|g' TMVAClassificationApplication*")

                # Run the code
                os.system("root -l -q %s"%fileName_mcNPL_NonFR)

                # Delete the code
                os.system("rm %s"%fileName_mcNPL_NonFR)

                ##########################################################
                # "Nonprompt MC NonFR" = "dataNPL NonFR" + "mcNPL NonFR" #
                ##########################################################
                os.system("hadd %s_%s_NonFR.root %s_%s_dataNPL_NonFR.root %s_%s_mcNPL_NonFR.root"%(DEFAULT_ch,DEFAULT_NPL,DEFAULT_ch,DEFAULT_NPL,DEFAULT_ch,DEFAULT_NPL))
                os.system("rm %s_%s_dataNPL_NonFR.root %s_%s_mcNPL_NonFR.root"%(DEFAULT_ch,DEFAULT_NPL,DEFAULT_ch,DEFAULT_NPL))



                name_ch_npl = DEFAULT_ch+"_"+DEFAULT_NPL
                name_ch_npl_up = name_ch_npl+"_NonpromptUp"
                name_ch_npl_down = name_ch_npl+"_NonpromptDown"

                # Get Square 0.30 Histogram
                name_ch_npl_square0p30 = name_ch_npl+"Square0p30"
                os.system("root -l -b -q 'getSquare0p30Histogram.C(\"%s_orig.root\", \"%s\", \"%s.root\", \"%s\")'"%(name_ch_npl,name_ch_npl,name_ch_npl_square0p30,name_ch_npl_square0p30))

                # Get Square Error Histogram ( Statistical Uncertainty from AR )
                name_ch_npl_nonfr_square_error = name_ch_npl+"_NonFR"
                name_ch_npl_square_error = name_ch_npl+"SquareError"
                os.system("root -l -b -q 'getSquareErrorHistogram.C(\"%s.root\", \"%s\", \"%s_orig.root\", \"%s\", \"%s.root\", \"%s\")'"%(name_ch_npl_nonfr_square_error,name_ch_npl_nonfr_square_error,name_ch_npl,name_ch_npl,name_ch_npl_square_error,name_ch_npl_square_error))

                # Get Square FRError Up Histogram
                name_ch_npl_FRErrorUp = name_ch_npl+"_FRErrorUp"
                name_ch_npl_FRErrorUpSquare = name_ch_npl+"FRErrorUpSquare"
                os.system("root -l -b -q 'getSquareFRErrorUpHistogram.C(\"%s_orig.root\", \"%s\", \"%s.root\", \"%s\", \"%s.root\", \"%s\")'"%(name_ch_npl,name_ch_npl,name_ch_npl_FRErrorUp,name_ch_npl_FRErrorUp,name_ch_npl_FRErrorUpSquare,name_ch_npl_FRErrorUpSquare))

                # Get Square FRError Down Histogram
                name_ch_npl_FRErrorDown = name_ch_npl+"_FRErrorDown"
                name_ch_npl_FRErrorDownSquare = name_ch_npl+"FRErrorDownSquare"
                os.system("root -l -b -q 'getSquareFRErrorDownHistogram.C(\"%s_orig.root\", \"%s\", \"%s.root\", \"%s\", \"%s.root\", \"%s\")'"%(name_ch_npl,name_ch_npl,name_ch_npl_FRErrorDown,name_ch_npl_FRErrorDown,name_ch_npl_FRErrorDownSquare,name_ch_npl_FRErrorDownSquare))

                # Get Nonprompt Error Up and Down
                os.system("root -l -b -q 'getUncertaintyUpHistogram.C(\"%s_orig.root\", \"%s\", \"%s.root\", \"%s\", \"%s.root\", \"%s\", \"%s.root\", \"%s\", \"%s_orig.root\", \"%s\")'"%(name_ch_npl,name_ch_npl,name_ch_npl_square0p30,name_ch_npl_square0p30,name_ch_npl_square_error,name_ch_npl_square_error,name_ch_npl_FRErrorUpSquare,name_ch_npl_FRErrorUpSquare,name_ch_npl_up,name_ch_npl_up))
                os.system("root -l -b -q 'getNewHistogram.C(\"%s_orig.root\", \"%s\", \"%s.root\", \"%s\")'"%(name_ch_npl_up,name_ch_npl_up,name_ch_npl_up,name_ch_npl_up))

                os.system("root -l -b -q 'getUncertaintyDownHistogram.C(\"%s_orig.root\", \"%s\", \"%s.root\", \"%s\", \"%s.root\", \"%s\", \"%s.root\", \"%s\", \"%s_orig.root\", \"%s\")'"%(name_ch_npl,name_ch_npl,name_ch_npl_square0p30,name_ch_npl_square0p30,name_ch_npl_square_error,name_ch_npl_square_error,name_ch_npl_FRErrorDownSquare,name_ch_npl_FRErrorDownSquare,name_ch_npl_down,name_ch_npl_down))
                os.system("root -l -b -q 'getNewHistogram.C(\"%s_orig.root\", \"%s\", \"%s.root\", \"%s\")'"%(name_ch_npl_down,name_ch_npl_down,name_ch_npl_down,name_ch_npl_down))

                # remove extra root files
                os.system("rm %s_orig.root %s_orig.root %s_orig.root"%(name_ch_npl,name_ch_npl_up,name_ch_npl_down))
                os.system("rm %s.root %s.root %s.root"%(name_ch_npl_square0p30,name_ch_npl_nonfr_square_error,name_ch_npl_square_error))
                os.system("rm %s.root %s.root %s.root %s.root"%(name_ch_npl_FRErrorUp,name_ch_npl_FRErrorUpSquare,name_ch_npl_FRErrorDown,name_ch_npl_FRErrorDownSquare))

            # Marker
            print("========================================")
            print("            Finished(%i/%i)             "%(i*len(SYS)*len(MC)+j*len(MC)+(k+1),len(CH)*len(SYS)*len(MC)))
            print("========================================")

    # Data
    print("========================================")
    print(" Process for channel : %s data "%(DEFAULT_ch))
    print("========================================")
    DEFAULT_ch = channel
#    DEFAULT_txt = "filelist/filelist_central_"+DEFAULT_ch+"_data.txt"
    DEFAULT_txt = "filelist/filelist_"+DEFAULT_ch+"_data.txt"

    if "st1" in sigchannel:
        DEFAULT_ch = "ST1"+channel
    elif "st2" in sigchannel:
        DEFAULT_ch = "ST2"+channel
    elif "tt" in sigchannel:
        DEFAULT_ch = "TT"+channel

    fileName = "TMVAClassificationApplication_%s_data.C"%DEFAULT_ch
    os.system("cp ../../Default_ST/Default_data.C %s"%fileName)
    for l, originvar in enumerate(originVARS):
        os.system("sed -i 's|_DEF_VAR%i_|%s|g' %s"%(l, originvar, fileName))
    os.system("sed -i 's|_DEF_CH_|%s|g' %s"%(DEFAULT_ch, fileName))
    os.system("sed -i 's|_DEF_TEXT_|%s|g' %s"%(DEFAULT_txt, fileName))
    os.system("sed -i 's|_DEF_CUT_|%s|g' %s"%(DEFAULT_cut, fileName))
    # For fix bug
    os.system("sed -i 's|_DEF_CUT_|\&|g' TMVAClassificationApplication*")

    # Run the code
    os.system("root -l -q %s"%fileName)

    # Delete the code
    os.system("rm %s"%fileName)

    # Marker
    print("========================================")
    print("             Finished(%i/%i)            "%(i+1,len(CH)))
    print("========================================")

# Merge into 1 file
#if "st" in sigchannel:
#    os.system("hadd shape_%s.root STEl*.root STMu*.root"%sigchannel)
#elif "tt" in sigchannel:
#    os.system("hadd shape_%s.root TTEl*.root TTMu*.root"%sigchannel)

# Remove other root files
#if "st" in sigchannel:
#    os.system("rm STEl*.root STMu*.root")
#elif "tt" in sigchannel:
#    os.system("rm TTEl*.root TTMu*.root")

# Remove sed*
