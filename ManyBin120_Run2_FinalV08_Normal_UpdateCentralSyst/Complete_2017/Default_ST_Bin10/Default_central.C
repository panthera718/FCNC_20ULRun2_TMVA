#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>

#include <cmath>
#include <utility>

#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TObjString.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TStopwatch.h"

#include "TMVA/Factory.h"
#include "TMVA/DataLoader.h"
#include "TMVA/Tools.h"
#include "TMVA/TMVAGui.h"
#include "TMVA/Reader.h"
#include "TMVA/MethodCuts.h"

int TMVAClassificationApplication__DEF_CH___DEF_MC_()
{
   (TMVA::gConfig().GetVariablePlotting()).fMaxNumOfAllowedVariablesForScatterPlots = 37;

   TMVA::Tools::Instance();

   std::cout << std::endl;
   std::cout << "==> Start TMVAClassificationApplication" << std::endl;

   TMVA::Reader *reader = new TMVA::Reader("!Color:!Silent:!V");

   Float_t _DEF_VAR0_;
   Float_t _DEF_VAR1_;
   Float_t _DEF_VAR2_;
   Float_t _DEF_VAR3_;
   Float_t _DEF_VAR4_;
   Float_t _DEF_VAR5_;
   Float_t _DEF_VAR6_;
   Float_t _DEF_VAR7_;
   Float_t _DEF_VAR8_;
   Float_t _DEF_VAR9_;
   Float_t _DEF_VAR10_;
   Float_t _DEF_VAR11_;
   Float_t _DEF_VAR12_;
   Float_t _DEF_VAR13_;
   Float_t _DEF_VAR14_;
   Float_t _DEF_VAR15_;
   Float_t _DEF_VAR16_;
   Float_t _DEF_VAR17_;
   Float_t _DEF_VAR18_;
   Float_t _DEF_VAR19_;
   Float_t _DEF_VAR20_;
   Float_t _DEF_VAR21_;
   Float_t _DEF_VAR22_;
   Float_t _DEF_VAR23_;
   Float_t _DEF_VAR24_;
   Float_t _DEF_VAR25_;
   Float_t _DEF_VAR26_;
   Float_t _DEF_VAR27_;
   Float_t _DEF_VAR28_;
   Float_t _DEF_VAR29_;
   Float_t _DEF_VAR30_;
   Float_t _DEF_VAR31_;
   Float_t _DEF_VAR32_;
   Float_t _DEF_VAR33_;
   Float_t _DEF_VAR34_;
   Float_t _DEF_VAR35_;
   Float_t _DEF_VAR36_;

//   Int_t eventID;

   reader->AddVariable( "_DEF_VAR0_", &_DEF_VAR0_ );
   reader->AddVariable( "_DEF_VAR1_", &_DEF_VAR1_ );
   reader->AddVariable( "_DEF_VAR2_", &_DEF_VAR2_ );
   reader->AddVariable( "_DEF_VAR3_", &_DEF_VAR3_ );
   reader->AddVariable( "_DEF_VAR4_", &_DEF_VAR4_ );
   reader->AddVariable( "_DEF_VAR5_", &_DEF_VAR5_ );
   reader->AddVariable( "_DEF_VAR6_", &_DEF_VAR6_ );
   reader->AddVariable( "_DEF_VAR7_", &_DEF_VAR7_ );
   reader->AddVariable( "_DEF_VAR8_", &_DEF_VAR8_ );
   reader->AddVariable( "_DEF_VAR9_", &_DEF_VAR9_ );
   reader->AddVariable( "_DEF_VAR10_", &_DEF_VAR10_ );
   reader->AddVariable( "_DEF_VAR11_", &_DEF_VAR11_ );
   reader->AddVariable( "_DEF_VAR12_", &_DEF_VAR12_ );
   reader->AddVariable( "_DEF_VAR13_", &_DEF_VAR13_ );
   reader->AddVariable( "_DEF_VAR14_", &_DEF_VAR14_ );
   reader->AddVariable( "_DEF_VAR15_", &_DEF_VAR15_ );
   reader->AddVariable( "_DEF_VAR16_", &_DEF_VAR16_ );
   reader->AddVariable( "_DEF_VAR17_", &_DEF_VAR17_ );
   reader->AddVariable( "_DEF_VAR18_", &_DEF_VAR18_ );
   reader->AddVariable( "_DEF_VAR19_", &_DEF_VAR19_ );
   reader->AddVariable( "_DEF_VAR20_", &_DEF_VAR20_ );
   reader->AddVariable( "_DEF_VAR21_", &_DEF_VAR21_ );
   reader->AddVariable( "_DEF_VAR22_", &_DEF_VAR22_ );
   reader->AddVariable( "_DEF_VAR23_", &_DEF_VAR23_ );
   reader->AddVariable( "_DEF_VAR24_", &_DEF_VAR24_ );
   reader->AddVariable( "_DEF_VAR25_", &_DEF_VAR25_ );
   reader->AddVariable( "_DEF_VAR26_", &_DEF_VAR26_ );
   reader->AddVariable( "_DEF_VAR27_", &_DEF_VAR27_ );
   reader->AddVariable( "_DEF_VAR28_", &_DEF_VAR28_ );
   reader->AddVariable( "_DEF_VAR29_", &_DEF_VAR29_ );
   reader->AddVariable( "_DEF_VAR30_", &_DEF_VAR30_ );
   reader->AddVariable( "_DEF_VAR31_", &_DEF_VAR31_ );
   reader->AddVariable( "_DEF_VAR32_", &_DEF_VAR32_ );
   reader->AddVariable( "_DEF_VAR33_", &_DEF_VAR33_ );
   reader->AddVariable( "_DEF_VAR34_", &_DEF_VAR34_ );
   reader->AddVariable( "_DEF_VAR35_", &_DEF_VAR35_ );
   reader->AddVariable( "_DEF_VAR36_", &_DEF_VAR36_ );

//   reader->AddSpectator("eventID", &eventID);

   TString jobname("TMVAClassification");
   TString methodName = "DNN_CPU";
   TString weightfile = TString("../dataset/weights/") + jobname + "_" + methodName + TString(".weights.xml");

   Bool_t weightfileExists = (gSystem->AccessPathName(weightfile) == kFALSE);
   if (weightfileExists) {
      reader->BookMVA(methodName, weightfile);
   } else {
      std::cout << "Weightfile for method " << methodName << " not found."
                   " Did you run TMVACrossValidation with a specified"
                   " splitExpr?" << std::endl;
      exit(0);
   }

   UInt_t nbin = 10;

   TH1F *_DEF_CH___DEF_MC_(0);
   TH1F *_DEF_CH___DEF_MC__PUUp(0);
   TH1F *_DEF_CH___DEF_MC__PUDown(0);
   TH1F *_DEF_CH___DEF_MC__ElSFUp(0);
   TH1F *_DEF_CH___DEF_MC__ElSFDown(0);
   TH1F *_DEF_CH___DEF_MC__ElSFStatUp(0);
   TH1F *_DEF_CH___DEF_MC__ElSFStatDown(0);
   TH1F *_DEF_CH___DEF_MC__ElSFSystUp(0);
   TH1F *_DEF_CH___DEF_MC__ElSFSystDown(0);
   TH1F *_DEF_CH___DEF_MC__ElRecoSFUp(0);
   TH1F *_DEF_CH___DEF_MC__ElRecoSFDown(0);
   TH1F *_DEF_CH___DEF_MC__MuSFUp(0);
   TH1F *_DEF_CH___DEF_MC__MuSFDown(0);
   TH1F *_DEF_CH___DEF_MC__MuSFStatUp(0);
   TH1F *_DEF_CH___DEF_MC__MuSFStatDown(0);
   TH1F *_DEF_CH___DEF_MC__MuSFSystUp(0);
   TH1F *_DEF_CH___DEF_MC__MuSFSystDown(0);
   TH1F *_DEF_CH___DEF_MC__MuRUp(0);
   TH1F *_DEF_CH___DEF_MC__MuRDown(0);
   TH1F *_DEF_CH___DEF_MC__MuFUp(0);
   TH1F *_DEF_CH___DEF_MC__MuFDown(0);
   TH1F *_DEF_CH___DEF_MC__PSWeightISRUp(0);
   TH1F *_DEF_CH___DEF_MC__PSWeightISRDown(0);
   TH1F *_DEF_CH___DEF_MC__PSWeightFSRUp(0);
   TH1F *_DEF_CH___DEF_MC__PSWeightFSRDown(0);
   TH1F *_DEF_CH___DEF_MC__JetPUIDUp(0);
   TH1F *_DEF_CH___DEF_MC__JetPUIDDown(0);
   TH1F *_DEF_CH___DEF_MC__BtagJESUp(0);
   TH1F *_DEF_CH___DEF_MC__BtagJESDown(0);
   TH1F *_DEF_CH___DEF_MC__BtagLFUp(0);
   TH1F *_DEF_CH___DEF_MC__BtagLFDown(0);
   TH1F *_DEF_CH___DEF_MC__BtagHFUp(0);
   TH1F *_DEF_CH___DEF_MC__BtagHFDown(0);
   TH1F *_DEF_CH___DEF_MC__BtagHFStats1Up(0);
   TH1F *_DEF_CH___DEF_MC__BtagHFStats1Down(0);
   TH1F *_DEF_CH___DEF_MC__BtagHFStats2Up(0);
   TH1F *_DEF_CH___DEF_MC__BtagHFStats2Down(0);
   TH1F *_DEF_CH___DEF_MC__BtagLFStats1Up(0);
   TH1F *_DEF_CH___DEF_MC__BtagLFStats1Down(0);
   TH1F *_DEF_CH___DEF_MC__BtagLFStats2Up(0);
   TH1F *_DEF_CH___DEF_MC__BtagLFStats2Down(0);
   TH1F *_DEF_CH___DEF_MC__BtagCFErr1Up(0);  
   TH1F *_DEF_CH___DEF_MC__BtagCFErr1Down(0);  
   TH1F *_DEF_CH___DEF_MC__BtagCFErr2Up(0);  
   TH1F *_DEF_CH___DEF_MC__BtagCFErr2Down(0);
   TH1F *_DEF_CH___DEF_MC__L1PreFiringWeightUp(0);
   TH1F *_DEF_CH___DEF_MC__L1PreFiringWeightDown(0);
   TH1F *_DEF_CH___DEF_MC__L1PreFiringWeightECALUp(0);
   TH1F *_DEF_CH___DEF_MC__L1PreFiringWeightECALDown(0);
   TH1F *_DEF_CH___DEF_MC__L1PreFiringWeightMuonStatUp(0);
   TH1F *_DEF_CH___DEF_MC__L1PreFiringWeightMuonStatDown(0);
   TH1F *_DEF_CH___DEF_MC__L1PreFiringWeightMuonSystUp(0);
   TH1F *_DEF_CH___DEF_MC__L1PreFiringWeightMuonSystDown(0);
   TH1F *_DEF_CH___DEF_MC__TauIDSFUp(0);
   TH1F *_DEF_CH___DEF_MC__TauIDSFDown(0);
   TH1F *_DEF_CH___DEF_MC__TauIDSF_genuineTauUp(0);
   TH1F *_DEF_CH___DEF_MC__TauIDSF_genuineTauDown(0);
   TH1F *_DEF_CH___DEF_MC__TauIDSF_eToTauUp(0);
   TH1F *_DEF_CH___DEF_MC__TauIDSF_eToTauDown(0);
   TH1F *_DEF_CH___DEF_MC__TauIDSF_muToTauUp(0);
   TH1F *_DEF_CH___DEF_MC__TauIDSF_muToTauDown(0);
   TH1F *_DEF_CH___DEF_MC__TauIDSF_otherVSlepWPUp(0);
   TH1F *_DEF_CH___DEF_MC__TauIDSF_otherVSlepWPDown(0);
   TH1F *_DEF_CH___DEF_MC__TauTriggerWeightUp(0);
   TH1F *_DEF_CH___DEF_MC__TauTriggerWeightDown(0);

   _DEF_CH___DEF_MC_ = new TH1F("_DEF_CH___DEF_MC_", "_DEF_CH___DEF_MC_", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__PUUp = new TH1F("_DEF_CH___DEF_MC__PUUp", "_DEF_CH___DEF_MC__PUUp", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__PUDown = new TH1F("_DEF_CH___DEF_MC__PUDown", "_DEF_CH___DEF_MC__PUDown", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__ElSFUp = new TH1F("_DEF_CH___DEF_MC__ElSFUp", "_DEF_CH___DEF_MC__ElSFUp", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__ElSFDown = new TH1F("_DEF_CH___DEF_MC__ElSFDown", "_DEF_CH___DEF_MC__ElSFDown", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__ElSFStatUp = new TH1F("_DEF_CH___DEF_MC__ElSFStatUp", "_DEF_CH___DEF_MC__ElSFStatUp", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__ElSFStatDown = new TH1F("_DEF_CH___DEF_MC__ElSFStatDown", "_DEF_CH___DEF_MC__ElSFStatDown", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__ElSFSystUp = new TH1F("_DEF_CH___DEF_MC__ElSFSystUp", "_DEF_CH___DEF_MC__ElSFSystUp", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__ElSFSystDown = new TH1F("_DEF_CH___DEF_MC__ElSFSystDown", "_DEF_CH___DEF_MC__ElSFSystDown", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__ElRecoSFUp = new TH1F("_DEF_CH___DEF_MC__ElRecoSFUp", "_DEF_CH___DEF_MC__ElRecoSFUp", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__ElRecoSFDown = new TH1F("_DEF_CH___DEF_MC__ElRecoSFDown", "_DEF_CH___DEF_MC__ElRecoSFDown", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__MuSFUp = new TH1F("_DEF_CH___DEF_MC__MuSFUp", "_DEF_CH___DEF_MC__MuSFUp", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__MuSFDown = new TH1F("_DEF_CH___DEF_MC__MuSFDown", "_DEF_CH___DEF_MC__MuSFDown", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__MuSFStatUp = new TH1F("_DEF_CH___DEF_MC__MuSFStatUp", "_DEF_CH___DEF_MC__MuSFStatUp", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__MuSFStatDown = new TH1F("_DEF_CH___DEF_MC__MuSFStatDown", "_DEF_CH___DEF_MC__MuSFStatDown", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__MuSFSystUp = new TH1F("_DEF_CH___DEF_MC__MuSFSystUp", "_DEF_CH___DEF_MC__MuSFSystUp", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__MuSFSystDown = new TH1F("_DEF_CH___DEF_MC__MuSFSystDown", "_DEF_CH___DEF_MC__MuSFSystDown", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__MuRUp = new TH1F("_DEF_CH___DEF_MC__MuRUp", "_DEF_CH___DEF_MC__MuRUp", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__MuRDown = new TH1F("_DEF_CH___DEF_MC__MuRDown", "_DEF_CH___DEF_MC__MuRDown", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__MuFUp = new TH1F("_DEF_CH___DEF_MC__MuFUp", "_DEF_CH___DEF_MC__MuFUp", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__MuFDown = new TH1F("_DEF_CH___DEF_MC__MuFDown", "_DEF_CH___DEF_MC__MuFDown", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__PSWeightISRUp = new TH1F("_DEF_CH___DEF_MC__PSWeightISRUp", "_DEF_CH___DEF_MC__PSWeightISRUp", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__PSWeightISRDown = new TH1F("_DEF_CH___DEF_MC__PSWeightISRDown", "_DEF_CH___DEF_MC__PSWeightISRDown", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__PSWeightFSRUp = new TH1F("_DEF_CH___DEF_MC__PSWeightFSRUp", "_DEF_CH___DEF_MC__PSWeightFSRUp", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__PSWeightFSRDown = new TH1F("_DEF_CH___DEF_MC__PSWeightFSRDown", "_DEF_CH___DEF_MC__PSWeightFSRDown", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__JetPUIDUp = new TH1F("_DEF_CH___DEF_MC__JetPUIDUp", "_DEF_CH___DEF_MC__JetPUIDUp", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__JetPUIDDown = new TH1F("_DEF_CH___DEF_MC__JetPUIDDown", "_DEF_CH___DEF_MC__JetPUIDDown", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__BtagJESUp = new TH1F("_DEF_CH___DEF_MC__BtagJESUp", "_DEF_CH___DEF_MC__BtagJESUp", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__BtagJESDown = new TH1F("_DEF_CH___DEF_MC__BtagJESDown", "_DEF_CH___DEF_MC__BtagJESDown", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__BtagLFUp = new TH1F("_DEF_CH___DEF_MC__BtagLFUp", "_DEF_CH___DEF_MC__BtagLFUp", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__BtagLFDown = new TH1F("_DEF_CH___DEF_MC__BtagLFDown", "_DEF_CH___DEF_MC__BtagLFDown", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__BtagHFUp = new TH1F("_DEF_CH___DEF_MC__BtagHFUp", "_DEF_CH___DEF_MC__BtagHFUp", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__BtagHFDown = new TH1F("_DEF_CH___DEF_MC__BtagHFDown", "_DEF_CH___DEF_MC__BtagHFDown", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__BtagHFStats1Up = new TH1F("_DEF_CH___DEF_MC__BtagHFStats1Up", "_DEF_CH___DEF_MC__BtagHFStats1Up", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__BtagHFStats1Down = new TH1F("_DEF_CH___DEF_MC__BtagHFStats1Down", "_DEF_CH___DEF_MC__BtagHFStats1Down", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__BtagHFStats2Up = new TH1F("_DEF_CH___DEF_MC__BtagHFStats2Up", "_DEF_CH___DEF_MC__BtagHFStats2Up", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__BtagHFStats2Down = new TH1F("_DEF_CH___DEF_MC__BtagHFStats2Down", "_DEF_CH___DEF_MC__BtagHFStats2Down", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__BtagLFStats1Up = new TH1F("_DEF_CH___DEF_MC__BtagLFStats1Up", "_DEF_CH___DEF_MC__BtagLFStats1Up", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__BtagLFStats1Down = new TH1F("_DEF_CH___DEF_MC__BtagLFStats1Down", "_DEF_CH___DEF_MC__BtagLFStats1Down", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__BtagLFStats2Up = new TH1F("_DEF_CH___DEF_MC__BtagLFStats2Up", "_DEF_CH___DEF_MC__BtagLFStats2Up", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__BtagLFStats2Down = new TH1F("_DEF_CH___DEF_MC__BtagLFStats2Down", "_DEF_CH___DEF_MC__BtagLFStats2Down", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__BtagCFErr1Up = new TH1F("_DEF_CH___DEF_MC__BtagCFErr1Up", "_DEF_CH___DEF_MC__BtagCFErr1Up", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__BtagCFErr1Down = new TH1F("_DEF_CH___DEF_MC__BtagCFErr1Down", "_DEF_CH___DEF_MC__BtagCFErr1Down", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__BtagCFErr2Up = new TH1F("_DEF_CH___DEF_MC__BtagCFErr2Up", "_DEF_CH___DEF_MC__BtagCFErr2Up", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__BtagCFErr2Down = new TH1F("_DEF_CH___DEF_MC__BtagCFErr2Down", "_DEF_CH___DEF_MC__BtagCFErr2Down", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__L1PreFiringWeightUp = new TH1F("_DEF_CH___DEF_MC__L1PreFiringWeightUp", "_DEF_CH___DEF_MC__L1PreFiringWeightUp", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__L1PreFiringWeightDown = new TH1F("_DEF_CH___DEF_MC__L1PreFiringWeightDown", "_DEF_CH___DEF_MC__L1PreFiringWeightDown", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__L1PreFiringWeightECALUp = new TH1F("_DEF_CH___DEF_MC__L1PreFiringWeightECALUp", "_DEF_CH___DEF_MC__L1PreFiringWeightECALUp", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__L1PreFiringWeightECALDown = new TH1F("_DEF_CH___DEF_MC__L1PreFiringWeightECALDown", "_DEF_CH___DEF_MC__L1PreFiringWeightECALDown", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__L1PreFiringWeightMuonStatUp = new TH1F("_DEF_CH___DEF_MC__L1PreFiringWeightMuonStatUp", "_DEF_CH___DEF_MC__L1PreFiringWeightMuonStatUp", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__L1PreFiringWeightMuonStatDown = new TH1F("_DEF_CH___DEF_MC__L1PreFiringWeightMuonStatDown", "_DEF_CH___DEF_MC__L1PreFiringWeightMuonStatDown", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__L1PreFiringWeightMuonSystUp = new TH1F("_DEF_CH___DEF_MC__L1PreFiringWeightMuonSystUp", "_DEF_CH___DEF_MC__L1PreFiringWeightMuonSystUp", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__L1PreFiringWeightMuonSystDown = new TH1F("_DEF_CH___DEF_MC__L1PreFiringWeightMuonSystDown", "_DEF_CH___DEF_MC__L1PreFiringWeightMuonSystDown", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__TauIDSFUp = new TH1F("_DEF_CH___DEF_MC__TauIDSFUp", "_DEF_CH___DEF_MC__TauIDSFUp", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__TauIDSFDown = new TH1F("_DEF_CH___DEF_MC__TauIDSFDown", "_DEF_CH___DEF_MC__TauIDSFDown", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__TauIDSF_genuineTauUp = new TH1F("_DEF_CH___DEF_MC__TauIDSF_genuineTauUp", "_DEF_CH___DEF_MC__TauIDSF_genuineTauUp", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__TauIDSF_genuineTauDown = new TH1F("_DEF_CH___DEF_MC__TauIDSF_genuineTauDown", "_DEF_CH___DEF_MC__TauIDSF_genuineTauDown", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__TauIDSF_eToTauUp = new TH1F("_DEF_CH___DEF_MC__TauIDSF_eToTauUp", "_DEF_CH___DEF_MC__TauIDSF_eToTauUp", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__TauIDSF_eToTauDown = new TH1F("_DEF_CH___DEF_MC__TauIDSF_eToTauDown", "_DEF_CH___DEF_MC__TauIDSF_eToTauDown", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__TauIDSF_muToTauUp = new TH1F("_DEF_CH___DEF_MC__TauIDSF_muToTauUp", "_DEF_CH___DEF_MC__TauIDSF_muToTauUp", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__TauIDSF_muToTauDown = new TH1F("_DEF_CH___DEF_MC__TauIDSF_muToTauDown", "_DEF_CH___DEF_MC__TauIDSF_muToTauDown", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__TauIDSF_otherVSlepWPUp = new TH1F("_DEF_CH___DEF_MC__TauIDSF_otherVSlepWPUp", "_DEF_CH___DEF_MC__TauIDSF_otherVSlepWPUp", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__TauIDSF_otherVSlepWPDown = new TH1F("_DEF_CH___DEF_MC__TauIDSF_otherVSlepWPDown", "_DEF_CH___DEF_MC__TauIDSF_otherVSlepWPDown", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__TauTriggerWeightUp = new TH1F("_DEF_CH___DEF_MC__TauTriggerWeightUp", "_DEF_CH___DEF_MC__TauTriggerWeightUp", nbin, 0.0, 1.0);
   _DEF_CH___DEF_MC__TauTriggerWeightDown = new TH1F("_DEF_CH___DEF_MC__TauTriggerWeightDown", "_DEF_CH___DEF_MC__TauTriggerWeightDown", nbin, 0.0, 1.0);

   TChain *theTree = new TChain("Events");

   std::string file_in_line;
   ifstream file_in("_DEF_TEXT_");
   while (std::getline(file_in, file_in_line)){
      TString file_in_line_R = file_in_line;
      theTree->Add(file_in_line_R);
   }

   std::cout << "--- Select signal sample" << std::endl;

   theTree->SetBranchAddress( "_DEF_VAR0_", &_DEF_VAR0_ );
   theTree->SetBranchAddress( "_DEF_VAR1_", &_DEF_VAR1_ );
   theTree->SetBranchAddress( "_DEF_VAR2_", &_DEF_VAR2_ );
   theTree->SetBranchAddress( "_DEF_VAR3_", &_DEF_VAR3_ );
   theTree->SetBranchAddress( "_DEF_VAR4_", &_DEF_VAR4_ );
   theTree->SetBranchAddress( "_DEF_VAR5_", &_DEF_VAR5_ );
   theTree->SetBranchAddress( "_DEF_VAR6_", &_DEF_VAR6_ );
   theTree->SetBranchAddress( "_DEF_VAR7_", &_DEF_VAR7_ );
   theTree->SetBranchAddress( "_DEF_VAR8_", &_DEF_VAR8_ );
   theTree->SetBranchAddress( "_DEF_VAR9_", &_DEF_VAR9_ );
   theTree->SetBranchAddress( "_DEF_VAR10_", &_DEF_VAR10_ );
   theTree->SetBranchAddress( "_DEF_VAR11_", &_DEF_VAR11_ );
   theTree->SetBranchAddress( "_DEF_VAR12_", &_DEF_VAR12_ );
   theTree->SetBranchAddress( "_DEF_VAR13_", &_DEF_VAR13_ );
   theTree->SetBranchAddress( "_DEF_VAR14_", &_DEF_VAR14_ );
   theTree->SetBranchAddress( "_DEF_VAR15_", &_DEF_VAR15_ );
   theTree->SetBranchAddress( "_DEF_VAR16_", &_DEF_VAR16_ );
   theTree->SetBranchAddress( "_DEF_VAR17_", &_DEF_VAR17_ );
   theTree->SetBranchAddress( "_DEF_VAR18_", &_DEF_VAR18_ );
   theTree->SetBranchAddress( "_DEF_VAR19_", &_DEF_VAR19_ );
   theTree->SetBranchAddress( "_DEF_VAR20_", &_DEF_VAR20_ );
   theTree->SetBranchAddress( "_DEF_VAR21_", &_DEF_VAR21_ );
   theTree->SetBranchAddress( "_DEF_VAR22_", &_DEF_VAR22_ );
   theTree->SetBranchAddress( "_DEF_VAR23_", &_DEF_VAR23_ );
   theTree->SetBranchAddress( "_DEF_VAR24_", &_DEF_VAR24_ );
   theTree->SetBranchAddress( "_DEF_VAR25_", &_DEF_VAR25_ );
   theTree->SetBranchAddress( "_DEF_VAR26_", &_DEF_VAR26_ );
   theTree->SetBranchAddress( "_DEF_VAR27_", &_DEF_VAR27_ );
   theTree->SetBranchAddress( "_DEF_VAR28_", &_DEF_VAR28_ );
   theTree->SetBranchAddress( "_DEF_VAR29_", &_DEF_VAR29_ );
   theTree->SetBranchAddress( "_DEF_VAR30_", &_DEF_VAR30_ );
   theTree->SetBranchAddress( "_DEF_VAR31_", &_DEF_VAR31_ );
   theTree->SetBranchAddress( "_DEF_VAR32_", &_DEF_VAR32_ );
   theTree->SetBranchAddress( "_DEF_VAR33_", &_DEF_VAR33_ );
   theTree->SetBranchAddress( "_DEF_VAR34_", &_DEF_VAR34_ );
   theTree->SetBranchAddress( "_DEF_VAR35_", &_DEF_VAR35_ );
   theTree->SetBranchAddress( "_DEF_VAR36_", &_DEF_VAR36_ );

//   theTree->SetBranchAddress("eventID", &eventID);

//   const Int_t LHEindex = 9;
//   Float_t LHEScaleWeight[LHEindex];
   Float_t PSWeight[4];
   Float_t genWeight;
   Float_t puWeight;
   Float_t BtagWeight;
   Float_t Electron_SF;
   Float_t Electron_SFerr;
   Float_t Electron_SFerrStat;
   Float_t Electron_SFerrSyst;
   Float_t Electron_RecoSF;
   Float_t Electron_RecoSFerr;
   Float_t Muon_SF;
   Float_t Muon_SFerr;
   Float_t Muon_SFerrStat;
   Float_t Muon_SFerrSyst;
   Float_t xsecNorm;
   Float_t puWeightUp;
   Float_t puWeightDown;
   Float_t JetPUID_SF;
   Float_t JetPUID_SFerr;
   Float_t BtagWeight_up_jes;
   Float_t BtagWeight_down_jes;
   Float_t BtagWeight_up_lf;
   Float_t BtagWeight_down_lf;
   Float_t BtagWeight_up_hf;
   Float_t BtagWeight_down_hf;
   Float_t BtagWeight_up_hfstats1;
   Float_t BtagWeight_down_hfstats1;
   Float_t BtagWeight_up_hfstats2;
   Float_t BtagWeight_down_hfstats2;
   Float_t BtagWeight_up_lfstats1;
   Float_t BtagWeight_down_lfstats1;
   Float_t BtagWeight_up_lfstats2;
   Float_t BtagWeight_down_lfstats2;
   Float_t BtagWeight_up_cferr1;
   Float_t BtagWeight_down_cferr1;
   Float_t BtagWeight_up_cferr2;
   Float_t BtagWeight_down_cferr2;
   Float_t L1PreFiringWeight_Nom;
   Float_t L1PreFiringWeight_Up;
   Float_t L1PreFiringWeight_Dn;
   Float_t L1PreFiringWeight_ECAL_Nom;
   Float_t L1PreFiringWeight_ECAL_Up;
   Float_t L1PreFiringWeight_ECAL_Dn;
   Float_t L1PreFiringWeight_Muon_Nom;
   Float_t L1PreFiringWeight_Muon_StatUp;
   Float_t L1PreFiringWeight_Muon_StatDn;
   Float_t L1PreFiringWeight_Muon_SystUp;
   Float_t L1PreFiringWeight_Muon_SystDn;
   Float_t TauIDSF;
   Float_t TauIDSF_up;
   Float_t TauIDSF_down;
   Float_t TauIDSF_genuineTau_up;
   Float_t TauIDSF_genuineTau_down;
   Float_t TauIDSF_eToTau_up;
   Float_t TauIDSF_eToTau_down;
   Float_t TauIDSF_muToTau_up;
   Float_t TauIDSF_muToTau_down;
   Float_t TauIDSF_otherVSlepWP_up;
   Float_t TauIDSF_otherVSlepWP_down;
   Float_t TauTriggerWeight;
   Float_t TauTriggerWeight_up;
   Float_t TauTriggerWeight_down;

//   theTree->SetBranchAddress( "LHEScaleWeight", &LHEScaleWeight);
   theTree->SetBranchAddress( "PSWeight", &PSWeight);
   theTree->SetBranchAddress( "genWeight", &genWeight);
   theTree->SetBranchAddress( "puWeight", &puWeight);
   theTree->SetBranchAddress( "BtagWeight", &BtagWeight);
   theTree->SetBranchAddress( "Electron_SF", &Electron_SF);
   theTree->SetBranchAddress( "Electron_SFerr", &Electron_SFerr);
   theTree->SetBranchAddress( "Electron_SFerrStat", &Electron_SFerrStat);
   theTree->SetBranchAddress( "Electron_SFerrSyst", &Electron_SFerrSyst);
   theTree->SetBranchAddress( "Electron_RecoSF", &Electron_RecoSF);
   theTree->SetBranchAddress( "Electron_RecoSFerr", &Electron_RecoSFerr);
   theTree->SetBranchAddress( "Muon_SF", &Muon_SF);
   theTree->SetBranchAddress( "Muon_SFerr", &Muon_SFerr);
   theTree->SetBranchAddress( "Muon_SFerrStat", &Muon_SFerrStat);
   theTree->SetBranchAddress( "Muon_SFerrSyst", &Muon_SFerrSyst);
   theTree->SetBranchAddress( "xsecNorm", &xsecNorm);
   theTree->SetBranchAddress( "puWeightUp", &puWeightUp);
   theTree->SetBranchAddress( "puWeightDown", &puWeightDown);
   theTree->SetBranchAddress( "JetPUID_SF", &JetPUID_SF);
   theTree->SetBranchAddress( "JetPUID_SFerr", &JetPUID_SFerr);
   theTree->SetBranchAddress( "BtagWeight_up_jes", &BtagWeight_up_jes);
   theTree->SetBranchAddress( "BtagWeight_down_jes", &BtagWeight_down_jes);
   theTree->SetBranchAddress( "BtagWeight_up_lf", &BtagWeight_up_lf);
   theTree->SetBranchAddress( "BtagWeight_down_lf", &BtagWeight_down_lf);
   theTree->SetBranchAddress( "BtagWeight_up_hf", &BtagWeight_up_hf);
   theTree->SetBranchAddress( "BtagWeight_down_hf", &BtagWeight_down_hf);
   theTree->SetBranchAddress( "BtagWeight_up_hfstats1", &BtagWeight_up_hfstats1);
   theTree->SetBranchAddress( "BtagWeight_down_hfstats1", &BtagWeight_down_hfstats1);
   theTree->SetBranchAddress( "BtagWeight_up_hfstats2", &BtagWeight_up_hfstats2);
   theTree->SetBranchAddress( "BtagWeight_down_hfstats2", &BtagWeight_down_hfstats2);
   theTree->SetBranchAddress( "BtagWeight_up_lfstats1", &BtagWeight_up_lfstats1);
   theTree->SetBranchAddress( "BtagWeight_down_lfstats1", &BtagWeight_down_lfstats1);
   theTree->SetBranchAddress( "BtagWeight_up_lfstats2", &BtagWeight_up_lfstats2);
   theTree->SetBranchAddress( "BtagWeight_down_lfstats2", &BtagWeight_down_lfstats2);
   theTree->SetBranchAddress( "BtagWeight_up_cferr1", &BtagWeight_up_cferr1);
   theTree->SetBranchAddress( "BtagWeight_down_cferr1", &BtagWeight_down_cferr1);
   theTree->SetBranchAddress( "BtagWeight_up_cferr2", &BtagWeight_up_cferr2);
   theTree->SetBranchAddress( "BtagWeight_down_cferr2", &BtagWeight_down_cferr2);
   theTree->SetBranchAddress( "L1PreFiringWeight_Nom", &L1PreFiringWeight_Nom);
   theTree->SetBranchAddress( "L1PreFiringWeight_Up", &L1PreFiringWeight_Up);
   theTree->SetBranchAddress( "L1PreFiringWeight_Dn", &L1PreFiringWeight_Dn);
   theTree->SetBranchAddress( "L1PreFiringWeight_ECAL_Nom", &L1PreFiringWeight_ECAL_Nom);
   theTree->SetBranchAddress( "L1PreFiringWeight_ECAL_Up", &L1PreFiringWeight_ECAL_Up);
   theTree->SetBranchAddress( "L1PreFiringWeight_ECAL_Dn", &L1PreFiringWeight_ECAL_Dn);
   theTree->SetBranchAddress( "L1PreFiringWeight_Muon_Nom", &L1PreFiringWeight_Muon_Nom);
   theTree->SetBranchAddress( "L1PreFiringWeight_Muon_StatUp", &L1PreFiringWeight_Muon_StatUp);
   theTree->SetBranchAddress( "L1PreFiringWeight_Muon_StatDn", &L1PreFiringWeight_Muon_StatDn);
   theTree->SetBranchAddress( "L1PreFiringWeight_Muon_SystUp", &L1PreFiringWeight_Muon_SystUp);
   theTree->SetBranchAddress( "L1PreFiringWeight_Muon_SystDn", &L1PreFiringWeight_Muon_SystDn);
   theTree->SetBranchAddress( "TauIDSF", &TauIDSF);
   theTree->SetBranchAddress( "TauIDSF_up", &TauIDSF_up);
   theTree->SetBranchAddress( "TauIDSF_down", &TauIDSF_down);
   theTree->SetBranchAddress( "TauIDSF_genuineTau_up", &TauIDSF_genuineTau_up);
   theTree->SetBranchAddress( "TauIDSF_genuineTau_down", &TauIDSF_genuineTau_down);
   theTree->SetBranchAddress( "TauIDSF_eToTau_up", &TauIDSF_eToTau_up);
   theTree->SetBranchAddress( "TauIDSF_eToTau_down", &TauIDSF_eToTau_down);
   theTree->SetBranchAddress( "TauIDSF_muToTau_up", &TauIDSF_muToTau_up);
   theTree->SetBranchAddress( "TauIDSF_muToTau_down", &TauIDSF_muToTau_down);
   theTree->SetBranchAddress( "TauIDSF_otherVSlepWP_up", &TauIDSF_otherVSlepWP_up);
   theTree->SetBranchAddress( "TauIDSF_otherVSlepWP_down", &TauIDSF_otherVSlepWP_down);
   theTree->SetBranchAddress( "TauTriggerWeight", &TauTriggerWeight);
   theTree->SetBranchAddress( "TauTriggerWeight_up", &TauTriggerWeight_up);
   theTree->SetBranchAddress( "TauTriggerWeight_down", &TauTriggerWeight_down);

   UInt_t CutStep;
   //Float_t W_MT;
   //Float_t Z_mass;
   UInt_t nGoodJet;
   UInt_t nBjet;
   Float_t LeadingLepton_pt;
   Int_t Z_charge;
   Bool_t HLT;
   Float_t ptsortLepton1_pt;
   Float_t ptsortLepton2_pt;
   Float_t ptsortLepton3_pt;
   Float_t JetVetoSum;
   Float_t KinTopZq_mass;
   theTree->SetBranchAddress( "CutStep", &CutStep);
   //theTree->SetBranchAddress( "W_MT", &W_MT);
   //theTree->SetBranchAddress( "Z_mass", &Z_mass);
   theTree->SetBranchAddress( "nGoodJet", &nGoodJet);
   theTree->SetBranchAddress( "nBjet", &nBjet);
   theTree->SetBranchAddress( "LeadingLepton_pt", &LeadingLepton_pt);
   theTree->SetBranchAddress( "Z_charge", &Z_charge);
   theTree->SetBranchAddress( "HLT", &HLT);
   theTree->SetBranchAddress( "ptsortLepton1_pt", &ptsortLepton1_pt);
   theTree->SetBranchAddress( "ptsortLepton2_pt", &ptsortLepton2_pt);
   theTree->SetBranchAddress( "ptsortLepton3_pt", &ptsortLepton3_pt);
   theTree->SetBranchAddress( "JetVetoSum", &JetVetoSum);
   theTree->SetBranchAddress( "KinTopZq_mass", &KinTopZq_mass);

   std::cout << "--- Processing: " << theTree->GetEntries() << " events" << std::endl;

   for (Long64_t ievt=0; ievt<theTree->GetEntries();ievt++) {

      if (ievt%1000 == 0) std::cout << "--- ... Processing event: " << ievt << std::endl;

      theTree->GetEntry(ievt);

      if  ( _DEF_CUT_ ) continue;

      Float_t MVAscore = reader->EvaluateMVA( "DNN_CPU" );

      Float_t LHEScale;
      Float_t LHEScale_MuRUp;
      Float_t LHEScale_MuRDown;
      Float_t LHEScale_MuFUp;
      Float_t LHEScale_MuFDown;
      Float_t PSScale;
      Float_t PSWeightISRUp;
      Float_t PSWeightISRDown;
      Float_t PSWeightFSRUp;
      Float_t PSWeightFSRDown;
//      for ( Int_t n=0;n<LHEindex;n++) {
//         if ( n==4 ) LHEScale = LHEScaleWeight[n];
//         else if ( n==7 ) LHEScale_MuRUp = LHEScaleWeight[n];
//         else if ( n==1 ) LHEScale_MuRDown = LHEScaleWeight[n];
//         else if ( n==5 ) LHEScale_MuFUp = LHEScaleWeight[n];
//         else if ( n==3 ) LHEScale_MuFDown = LHEScaleWeight[n];
//      }
      LHEScale = 1.;
      LHEScale_MuRUp = 1.;
      LHEScale_MuRDown = 1.;
      LHEScale_MuFUp = 1.;
      LHEScale_MuFDown = 1.;
      PSScale = 1.;
      PSWeightISRUp = PSWeight[0];
      PSWeightISRDown = PSWeight[2];
      PSWeightFSRUp = PSWeight[1];
      PSWeightFSRDown = PSWeight[3];
      Float_t ElSFUp;
      Float_t ElSFDown;
      Float_t ElSFStatUp;
      Float_t ElSFStatDown;
      Float_t ElSFSystUp;
      Float_t ElSFSystDown;
      Float_t ElRecoSFUp;
      Float_t ElRecoSFDown;
      Float_t MuSFUp;
      Float_t MuSFDown;
      Float_t MuSFStatUp;
      Float_t MuSFStatDown;
      Float_t MuSFSystUp;
      Float_t MuSFSystDown;
      Float_t JetPUIDUp;
      Float_t JetPUIDDown;
      ElSFUp = Electron_SF + Electron_SFerr;
      ElSFDown = Electron_SF - Electron_SFerr;
      ElSFStatUp = Electron_SF + Electron_SFerrStat;
      ElSFStatDown = Electron_SF - Electron_SFerrStat;
      ElSFSystUp = Electron_SF + Electron_SFerrSyst;
      ElSFSystDown = Electron_SF - Electron_SFerrSyst;
      ElRecoSFUp = Electron_RecoSF + Electron_RecoSFerr;
      ElRecoSFDown = Electron_RecoSF - Electron_RecoSFerr;
      MuSFUp = Muon_SF + Muon_SFerr;
      MuSFDown = Muon_SF - Muon_SFerr;
      MuSFStatUp = Muon_SF + Muon_SFerrStat;
      MuSFStatDown = Muon_SF - Muon_SFerrStat;
      MuSFSystUp = Muon_SF + Muon_SFerrSyst;
      MuSFSystDown = Muon_SF - Muon_SFerrSyst;
      JetPUIDUp = JetPUID_SF + JetPUID_SFerr;
      JetPUIDDown = JetPUID_SF - JetPUID_SFerr;

      auto isBadFactor = [](const double x) {
         return (std::isnan(x) || std::isinf(x) || std::fabs(x) > 100.);
      };
      
      bool hasBadSF = false;
      
      std::vector<std::pair<std::string, double> > sfFactors = {
         {"PSWeightISRUp", PSWeightISRUp},
         {"PSWeightISRDown", PSWeightISRDown},
         {"PSWeightFSRUp", PSWeightFSRUp},
         {"PSWeightFSRDown", PSWeightFSRDown},
      
         {"puWeight", puWeight},
         {"puWeightUp", puWeightUp},
         {"puWeightDown", puWeightDown},
      
         {"BtagWeight", BtagWeight},
         {"BtagWeight_up_jes", BtagWeight_up_jes},
         {"BtagWeight_down_jes", BtagWeight_down_jes},
         {"BtagWeight_up_lf", BtagWeight_up_lf},
         {"BtagWeight_down_lf", BtagWeight_down_lf},
         {"BtagWeight_up_hf", BtagWeight_up_hf},
         {"BtagWeight_down_hf", BtagWeight_down_hf},
         {"BtagWeight_up_hfstats1", BtagWeight_up_hfstats1},
         {"BtagWeight_down_hfstats1", BtagWeight_down_hfstats1},
         {"BtagWeight_up_hfstats2", BtagWeight_up_hfstats2},
         {"BtagWeight_down_hfstats2", BtagWeight_down_hfstats2},
         {"BtagWeight_up_lfstats1", BtagWeight_up_lfstats1},
         {"BtagWeight_down_lfstats1", BtagWeight_down_lfstats1},
         {"BtagWeight_up_lfstats2", BtagWeight_up_lfstats2},
         {"BtagWeight_down_lfstats2", BtagWeight_down_lfstats2},
         {"BtagWeight_up_cferr1", BtagWeight_up_cferr1},
         {"BtagWeight_down_cferr1", BtagWeight_down_cferr1},
         {"BtagWeight_up_cferr2", BtagWeight_up_cferr2},
         {"BtagWeight_down_cferr2", BtagWeight_down_cferr2},
      
         {"Electron_SF", Electron_SF},
         {"Electron_RecoSF", Electron_RecoSF},
         {"ElSFUp", ElSFUp},
         {"ElSFDown", ElSFDown},
         {"ElSFStatUp", ElSFStatUp},
         {"ElSFStatDown", ElSFStatDown},
         {"ElSFSystUp", ElSFSystUp},
         {"ElSFSystDown", ElSFSystDown},
         {"ElRecoSFUp", ElRecoSFUp},
         {"ElRecoSFDown", ElRecoSFDown},
      
         {"Muon_SF", Muon_SF},
         {"MuSFUp", MuSFUp},
         {"MuSFDown", MuSFDown},
         {"MuSFStatUp", MuSFStatUp},
         {"MuSFStatDown", MuSFStatDown},
         {"MuSFSystUp", MuSFSystUp},
         {"MuSFSystDown", MuSFSystDown},
      
         {"xsecNorm", xsecNorm},
      
         {"JetPUID_SF", JetPUID_SF},
         {"JetPUIDUp", JetPUIDUp},
         {"JetPUIDDown", JetPUIDDown},
      
         {"L1PreFiringWeight_Nom", L1PreFiringWeight_Nom},
         {"L1PreFiringWeight_Up", L1PreFiringWeight_Up},
         {"L1PreFiringWeight_Dn", L1PreFiringWeight_Dn},
         {"L1PreFiringWeight_ECAL_Nom", L1PreFiringWeight_ECAL_Nom},
         {"L1PreFiringWeight_ECAL_Up", L1PreFiringWeight_ECAL_Up},
         {"L1PreFiringWeight_ECAL_Dn", L1PreFiringWeight_ECAL_Dn},
         {"L1PreFiringWeight_Muon_Nom", L1PreFiringWeight_Muon_Nom},
         {"L1PreFiringWeight_Muon_StatUp", L1PreFiringWeight_Muon_StatUp},
         {"L1PreFiringWeight_Muon_StatDn", L1PreFiringWeight_Muon_StatDn},
         {"L1PreFiringWeight_Muon_SystUp", L1PreFiringWeight_Muon_SystUp},
         {"L1PreFiringWeight_Muon_SystDn", L1PreFiringWeight_Muon_SystDn},
      
         {"TauIDSF", TauIDSF},
         {"TauIDSF_up", TauIDSF_up},
         {"TauIDSF_down", TauIDSF_down},
         {"TauIDSF_genuineTau_up", TauIDSF_genuineTau_up},
         {"TauIDSF_genuineTau_down", TauIDSF_genuineTau_down},
         {"TauIDSF_eToTau_up", TauIDSF_eToTau_up},
         {"TauIDSF_eToTau_down", TauIDSF_eToTau_down},
         {"TauIDSF_muToTau_up", TauIDSF_muToTau_up},
         {"TauIDSF_muToTau_down", TauIDSF_muToTau_down},
         {"TauIDSF_otherVSlepWP_up", TauIDSF_otherVSlepWP_up},
         {"TauIDSF_otherVSlepWP_down", TauIDSF_otherVSlepWP_down},
      
         {"TauTriggerWeight", TauTriggerWeight},
         {"TauTriggerWeight_up", TauTriggerWeight_up},
         {"TauTriggerWeight_down", TauTriggerWeight_down}
      };
      
      for (const auto &sf : sfFactors) {
         const std::string &name = sf.first;
         const double value = sf.second;
      
         if (isBadFactor(value)) {
            std::cout << std::endl;
            std::cout << "ISSUE!" << std::endl;
            std::cout << "Event: " << ievt << std::endl;
            std::cout << "MVAscore: " << MVAscore << std::endl;
            std::cout << "Bad factor: " << name << " = " << value << std::endl;
            std::cout << std::endl;
      
            hasBadSF = true;
            break;
         }
      }
      
      if (
         std::isnan(genWeight) ||
         std::isinf(genWeight) ||
         genWeight == 0.
      ) {
         std::cout << std::endl;
         std::cout << "ISSUE!" << std::endl;
         std::cout << "Event: " << ievt << std::endl;
         std::cout << "MVAscore: " << MVAscore << std::endl;
         std::cout << "Bad genWeight: " << genWeight << std::endl;
         std::cout << "Reason: genWeight is used as abs(genWeight)/genWeight in histogram weights." << std::endl;
         std::cout << std::endl;
      
         hasBadSF = true;
      }
      
      if (hasBadSF) continue;

      _DEF_CH___DEF_MC_ -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__PUUp -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeightUp*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__PUDown -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeightDown*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__ElSFUp -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*ElSFUp*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__ElSFDown -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*ElSFDown*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__ElSFStatUp -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*ElSFStatUp*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__ElSFStatDown -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*ElSFStatDown*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__ElSFSystUp -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*ElSFSystUp*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__ElSFSystDown -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*ElSFSystDown*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__ElRecoSFUp -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*ElRecoSFUp*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__ElRecoSFDown -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*ElRecoSFDown*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__MuSFUp -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*MuSFUp*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__MuSFDown -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*MuSFDown*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__MuSFStatUp -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*MuSFStatUp*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__MuSFStatDown -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*MuSFStatDown*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__MuSFSystUp -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*MuSFSystUp*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__MuSFSystDown -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*MuSFSystDown*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__MuRUp -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale_MuRUp*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__MuRDown -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale_MuRDown*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__MuFUp -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale_MuFUp*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__MuFDown -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale_MuFDown*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__PSWeightISRUp -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2.*PSWeightISRUp );
      _DEF_CH___DEF_MC__PSWeightISRDown -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2.*PSWeightISRDown );
      _DEF_CH___DEF_MC__PSWeightFSRUp -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2.*PSWeightFSRUp );
      _DEF_CH___DEF_MC__PSWeightFSRDown -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2.*PSWeightFSRDown );
      _DEF_CH___DEF_MC__JetPUIDUp -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUIDUp*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__JetPUIDDown -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUIDDown*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__BtagJESUp -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight_up_jes*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__BtagJESDown -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight_down_jes*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__BtagLFUp -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight_up_lf*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__BtagLFDown -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight_down_lf*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__BtagHFUp -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight_up_hf*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__BtagHFDown -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight_down_hf*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__BtagHFStats1Up -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight_up_hfstats1*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__BtagHFStats1Down -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight_down_hfstats1*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__BtagHFStats2Up -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight_up_hfstats2*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__BtagHFStats2Down -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight_down_hfstats2*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__BtagLFStats1Up -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight_up_lfstats1*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__BtagLFStats1Down -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight_down_lfstats1*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__BtagLFStats2Up -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight_up_lfstats2*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__BtagLFStats2Down -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight_down_lfstats2*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__BtagCFErr1Up -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight_up_cferr1*L1PreFiringWeight_Nom*xsecNorm*2. ); 
      _DEF_CH___DEF_MC__BtagCFErr1Down -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight_down_cferr1*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__BtagCFErr2Up -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight_up_cferr2*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__BtagCFErr2Down -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight_down_cferr2*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__L1PreFiringWeightUp -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_Up*xsecNorm*2. );
      _DEF_CH___DEF_MC__L1PreFiringWeightDown -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_Dn*xsecNorm*2. );
      _DEF_CH___DEF_MC__L1PreFiringWeightECALUp -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_ECAL_Up*L1PreFiringWeight_Muon_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__L1PreFiringWeightECALDown -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_ECAL_Dn*L1PreFiringWeight_Muon_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__L1PreFiringWeightMuonStatUp -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_ECAL_Nom*L1PreFiringWeight_Muon_StatUp*xsecNorm*2. );
      _DEF_CH___DEF_MC__L1PreFiringWeightMuonStatDown -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_ECAL_Nom*L1PreFiringWeight_Muon_StatDn*xsecNorm*2. );
      _DEF_CH___DEF_MC__L1PreFiringWeightMuonSystUp -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_ECAL_Nom*L1PreFiringWeight_Muon_SystUp*xsecNorm*2. );
      _DEF_CH___DEF_MC__L1PreFiringWeightMuonSystDown -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_ECAL_Nom*L1PreFiringWeight_Muon_SystDn*xsecNorm*2. );
      _DEF_CH___DEF_MC__TauIDSFUp -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF_up*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__TauIDSFDown -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF_down*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__TauIDSF_genuineTauUp -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF_genuineTau_up*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__TauIDSF_genuineTauDown -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF_genuineTau_down*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__TauIDSF_eToTauUp -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF_eToTau_up*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__TauIDSF_eToTauDown -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF_eToTau_down*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__TauIDSF_muToTauUp -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF_muToTau_up*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__TauIDSF_muToTauDown -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF_muToTau_down*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__TauIDSF_otherVSlepWPUp -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF_otherVSlepWP_up*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__TauIDSF_otherVSlepWPDown -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF_otherVSlepWP_down*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__TauTriggerWeightUp -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight_up*LHEScale*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2. );
      _DEF_CH___DEF_MC__TauTriggerWeightDown -> Fill( MVAscore, (abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight_down*LHEScale*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*2. );

   }

   theTree->ResetBranchAddresses();
   delete theTree;

   TFile *target  = new TFile( "_DEF_CH___DEF_MC_.root", "RECREATE" );

   _DEF_CH___DEF_MC_ -> Write();
   _DEF_CH___DEF_MC__PUUp -> Write();
   _DEF_CH___DEF_MC__PUDown -> Write();
   _DEF_CH___DEF_MC__ElSFUp -> Write();
   _DEF_CH___DEF_MC__ElSFDown -> Write();
   _DEF_CH___DEF_MC__ElSFStatUp -> Write();
   _DEF_CH___DEF_MC__ElSFStatDown -> Write();
   _DEF_CH___DEF_MC__ElSFSystUp -> Write();
   _DEF_CH___DEF_MC__ElSFSystDown -> Write();
   _DEF_CH___DEF_MC__ElRecoSFUp -> Write();
   _DEF_CH___DEF_MC__ElRecoSFDown -> Write();
   _DEF_CH___DEF_MC__MuSFUp -> Write();
   _DEF_CH___DEF_MC__MuSFDown -> Write();
   _DEF_CH___DEF_MC__MuSFStatUp -> Write();
   _DEF_CH___DEF_MC__MuSFStatDown -> Write();
   _DEF_CH___DEF_MC__MuSFSystUp -> Write();
   _DEF_CH___DEF_MC__MuSFSystDown -> Write();
   _DEF_CH___DEF_MC__MuRUp -> Write();
   _DEF_CH___DEF_MC__MuRDown -> Write();
   _DEF_CH___DEF_MC__MuFUp -> Write();
   _DEF_CH___DEF_MC__MuFDown -> Write();
   _DEF_CH___DEF_MC__PSWeightISRUp -> Write();
   _DEF_CH___DEF_MC__PSWeightISRDown -> Write();
   _DEF_CH___DEF_MC__PSWeightFSRUp -> Write();
   _DEF_CH___DEF_MC__PSWeightFSRDown -> Write();
   _DEF_CH___DEF_MC__JetPUIDUp -> Write();
   _DEF_CH___DEF_MC__JetPUIDDown -> Write();
   _DEF_CH___DEF_MC__BtagJESUp -> Write();
   _DEF_CH___DEF_MC__BtagJESDown -> Write();
   _DEF_CH___DEF_MC__BtagLFUp -> Write();
   _DEF_CH___DEF_MC__BtagLFDown -> Write();
   _DEF_CH___DEF_MC__BtagHFUp -> Write();
   _DEF_CH___DEF_MC__BtagHFDown -> Write();
   _DEF_CH___DEF_MC__BtagHFStats1Up -> Write();
   _DEF_CH___DEF_MC__BtagHFStats1Down -> Write();
   _DEF_CH___DEF_MC__BtagHFStats2Up -> Write();
   _DEF_CH___DEF_MC__BtagHFStats2Down -> Write();
   _DEF_CH___DEF_MC__BtagLFStats1Up -> Write();
   _DEF_CH___DEF_MC__BtagLFStats1Down -> Write();
   _DEF_CH___DEF_MC__BtagLFStats2Up -> Write();
   _DEF_CH___DEF_MC__BtagLFStats2Down -> Write();
   _DEF_CH___DEF_MC__BtagCFErr1Up -> Write();
   _DEF_CH___DEF_MC__BtagCFErr1Down -> Write();
   _DEF_CH___DEF_MC__BtagCFErr2Up -> Write();
   _DEF_CH___DEF_MC__BtagCFErr2Down -> Write();
   _DEF_CH___DEF_MC__L1PreFiringWeightUp -> Write();
   _DEF_CH___DEF_MC__L1PreFiringWeightDown -> Write();
   _DEF_CH___DEF_MC__L1PreFiringWeightECALUp -> Write();
   _DEF_CH___DEF_MC__L1PreFiringWeightECALDown -> Write();
   _DEF_CH___DEF_MC__L1PreFiringWeightMuonStatUp -> Write();
   _DEF_CH___DEF_MC__L1PreFiringWeightMuonStatDown -> Write();
   _DEF_CH___DEF_MC__L1PreFiringWeightMuonSystUp -> Write();
   _DEF_CH___DEF_MC__L1PreFiringWeightMuonSystDown -> Write();
   _DEF_CH___DEF_MC__TauIDSFUp -> Write();
   _DEF_CH___DEF_MC__TauIDSFDown -> Write();
   _DEF_CH___DEF_MC__TauIDSF_genuineTauUp -> Write();
   _DEF_CH___DEF_MC__TauIDSF_genuineTauDown -> Write();
   _DEF_CH___DEF_MC__TauIDSF_eToTauUp -> Write();
   _DEF_CH___DEF_MC__TauIDSF_eToTauDown -> Write();
   _DEF_CH___DEF_MC__TauIDSF_muToTauUp -> Write();
   _DEF_CH___DEF_MC__TauIDSF_muToTauDown -> Write();
   _DEF_CH___DEF_MC__TauIDSF_otherVSlepWPUp -> Write();
   _DEF_CH___DEF_MC__TauIDSF_otherVSlepWPDown -> Write();
   _DEF_CH___DEF_MC__TauTriggerWeightUp -> Write();
   _DEF_CH___DEF_MC__TauTriggerWeightDown -> Write();

   target->Close();
   std::cout << "--- Created root file: \"_DEF_CH___DEF_MC_.root\" containing the MVA output histograms" << std::endl;

   delete target;
   std::cout << "==> TMVAClassificationApplication is done!" << std::endl << std::endl;

   delete reader;

   return 0;
}

int main(int argc, char **argv)
{
   TMVAClassificationApplication__DEF_CH___DEF_MC_();
}
