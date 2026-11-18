#include <TH1.h>
#include <TFile.h>
#include <iostream>

void createErrorHistogram(const TH1* originalHist1,
                          const TH1* originalHist2,
                          const char* outputFileName,
                          const char* outputHistPath) {
    const TAxis *axis1 = originalHist1->GetXaxis();
    const TAxis *axis2 = originalHist2->GetXaxis();
    if (axis1->GetNbins() == axis2->GetNbins() &&
        axis1->GetXmin()   == axis2->GetXmin() &&
        axis1->GetXmax()   == axis2->GetXmax()) {
        std::cout << "The format of two histograms is equal." << std::endl;
    } else {
        std::cout << "The format of two histograms is different." << std::endl;
        return;
    }

    Bool_t oldAddDir = TH1::AddDirectoryStatus();
    TH1::AddDirectory(kFALSE);
    TH1* errorHist = static_cast<TH1*>(originalHist1->Clone(outputHistPath));
    TH1::AddDirectory(oldAddDir);

    errorHist->Reset();
    errorHist->SetDirectory(0);

    Int_t nbin = errorHist->GetNbinsX();
    for (Int_t i = 1; i <= nbin; ++i) {
        Double_t FROriginal = originalHist1->GetBinContent(i);
        Double_t FRError    = originalHist2->GetBinContent(i);
        Double_t error      = FRError - FROriginal;
        Double_t square_err = error * error;
        errorHist->SetBinContent(i, square_err);
    }

    TFile outputFile(outputFileName, "RECREATE");
    if (!outputFile.IsOpen()) {
        std::cerr << "Error: Failed to open output file "
                  << outputFileName << std::endl;
        delete errorHist;
        return;
    }
    errorHist->Write("", TObject::kOverwrite);
    delete errorHist;
    outputFile.Close();
}

void getSquareFRErrorDownHistogram(const char* inputFileName1,
                                   const char* histPath1,
                                   const char* inputFileName2,
                                   const char* histPath2,
                                   const char* outputFileName,
                                   const char* outputHistPath) {
    TFile inputFile1(inputFileName1);
    if (!inputFile1.IsOpen()) {
        std::cerr << "Error: Failed to open input file "
                  << inputFileName1 << std::endl;
        return;
    }
    TH1* originalHist1 = dynamic_cast<TH1*>(inputFile1.Get(histPath1));
    if (!originalHist1) {
        std::cerr << "Error: Failed to retrieve histogram from "
                  << histPath1 << std::endl;
        inputFile1.Close();
        return;
    }

    TFile inputFile2(inputFileName2);
    if (!inputFile2.IsOpen()) {
        std::cerr << "Error: Failed to open input file "
                  << inputFileName2 << std::endl;
        inputFile1.Close();
        return;
    }
    TH1* originalHist2 = dynamic_cast<TH1*>(inputFile2.Get(histPath2));
    if (!originalHist2) {
        std::cerr << "Error: Failed to retrieve histogram from "
                  << histPath2 << std::endl;
        inputFile1.Close();
        inputFile2.Close();
        return;
    }

    createErrorHistogram(originalHist1, originalHist2,
                         outputFileName, outputHistPath);

    inputFile1.Close();
    inputFile2.Close();
}
