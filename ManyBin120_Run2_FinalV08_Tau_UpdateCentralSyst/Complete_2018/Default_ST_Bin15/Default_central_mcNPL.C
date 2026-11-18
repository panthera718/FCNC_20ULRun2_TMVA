#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>

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

int TMVAClassificationApplication__DEF_CH___DEF_MC__mcNPL()
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

   UInt_t nbin = 15;

   TH1F *_DEF_CH___DEF_MC_(0);

   _DEF_CH___DEF_MC_ = new TH1F("_DEF_CH___DEF_MC_", "_DEF_CH___DEF_MC_", nbin, 0.0, 1.0);

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
   Float_t Electron_RecoSF;
   Float_t Muon_SF;
   Float_t xsecNorm;
   Float_t JetPUID_SF;
   Float_t L1PreFiringWeight_Nom;
   Float_t L1PreFiringWeight_ECAL_Nom;
   Float_t L1PreFiringWeight_Muon_Nom;
   Float_t TauIDSF;
   Float_t TauTriggerWeight;

//   theTree->SetBranchAddress( "LHEScaleWeight", &LHEScaleWeight);
   theTree->SetBranchAddress( "PSWeight", &PSWeight);
   theTree->SetBranchAddress( "genWeight", &genWeight);
   theTree->SetBranchAddress( "puWeight", &puWeight);
   theTree->SetBranchAddress( "BtagWeight", &BtagWeight);
   theTree->SetBranchAddress( "Electron_SF", &Electron_SF);
   theTree->SetBranchAddress( "Electron_RecoSF", &Electron_RecoSF);
   theTree->SetBranchAddress( "Muon_SF", &Muon_SF);
   theTree->SetBranchAddress( "xsecNorm", &xsecNorm);
   theTree->SetBranchAddress( "JetPUID_SF", &JetPUID_SF);
   theTree->SetBranchAddress( "L1PreFiringWeight_Nom", &L1PreFiringWeight_Nom);
   theTree->SetBranchAddress( "L1PreFiringWeight_ECAL_Nom", &L1PreFiringWeight_ECAL_Nom);
   theTree->SetBranchAddress( "L1PreFiringWeight_Muon_Nom", &L1PreFiringWeight_Muon_Nom);
   theTree->SetBranchAddress( "TauIDSF", &TauIDSF);
   theTree->SetBranchAddress( "TauTriggerWeight", &TauTriggerWeight);

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
   Float_t FakeRateWeight;
   Float_t FakeRateWeightError;
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
   theTree->SetBranchAddress( "FakeRateWeight", &FakeRateWeight);
   theTree->SetBranchAddress( "FakeRateWeightError", &FakeRateWeightError);
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

      _DEF_CH___DEF_MC_ -> Fill( MVAscore, -(abs(genWeight)/genWeight)*puWeight*JetPUID_SF*Electron_RecoSF*Electron_SF*Muon_SF*TauIDSF*TauTriggerWeight*LHEScale*BtagWeight*L1PreFiringWeight_Nom*xsecNorm*FakeRateWeight );
   }

   theTree->ResetBranchAddresses();
   delete theTree;

   TFile *target  = new TFile( "_DEF_CH___DEF_MC__mcNPL.root", "RECREATE" );

   _DEF_CH___DEF_MC_ -> Write();

   target->Close();
   std::cout << "--- Created root file: \"_DEF_CH___DEF_MC__mcNPL.root\" containing the MVA output histograms" << std::endl;

   delete target;
   std::cout << "==> TMVAClassificationApplication is done!" << std::endl << std::endl;

   delete reader;

   return 0;
}

int main(int argc, char **argv)
{
   TMVAClassificationApplication__DEF_CH___DEF_MC__mcNPL();
}
