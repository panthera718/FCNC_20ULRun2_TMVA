#include <TH1.h>
#include <TFile.h>
#include <TAxis.h>
#include <TMath.h>										  
#include <iostream>

void createNewHistogram(const TH1* originalHist,
                        const char* outputFileName,
                        const char* outputHistPath) {

    Bool_t oldStatus = TH1::AddDirectoryStatus();
    TH1::AddDirectory(kFALSE);
    TH1* newHist = static_cast<TH1*>(originalHist->Clone(outputHistPath));
    TH1::AddDirectory(oldStatus);

    newHist->Reset();  
    newHist->SetDirectory(0);

    for (Int_t i = 0; i < newHist->GetNbinsX(); ++i) {
        Double_t orig = TMath::Abs(originalHist->GetBinContent(i+1));
        newHist->SetBinContent(i+1, TMath::Max(0., orig));
    }

    TFile outputFile(outputFileName, "RECREATE");
    if (!outputFile.IsOpen()) {
        std::cerr << "Error: Failed to open output file "
                  << outputFileName << std::endl;
        delete newHist;
        return;
    }
    newHist->Write("", TObject::kOverwrite);
    delete newHist;
    outputFile.Close();
}

void getNewHistogram(const char* inputFileName,
                     const char* histPath,
                     const char* outputFileName,
                     const char* outputHistPath) {
    TFile inputFile(inputFileName);
    if (!inputFile.IsOpen()) {
        std::cerr << "Error: Failed to open input file "
                  << inputFileName << std::endl;
        return;
    }
    TH1* originalHist = dynamic_cast<TH1*>(inputFile.Get(histPath));
    if (!originalHist) {
        std::cerr << "Error: Failed to retrieve histogram from "
                  << histPath << std::endl;
        inputFile.Close();
        return;
    }
    createNewHistogram(originalHist, outputFileName, outputHistPath);
    inputFile.Close();
}
