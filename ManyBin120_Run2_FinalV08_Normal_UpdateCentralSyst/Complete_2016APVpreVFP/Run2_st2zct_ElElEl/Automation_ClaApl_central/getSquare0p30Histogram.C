#include <TH1.h>
#include <TFile.h>
#include <iostream>

void createErrorHistogram(const TH1* originalHist,
                          const char* outputFileName,
                          const char* outputHistPath) {
    Bool_t oldAddDir = TH1::AddDirectoryStatus();
    TH1::AddDirectory(kFALSE);

    TH1* errorHist = static_cast<TH1*>(originalHist->Clone(outputHistPath));

    TH1::AddDirectory(oldAddDir);

    errorHist->Reset();
    errorHist->SetDirectory(0);

    Int_t nbin = errorHist->GetNbinsX();
    for (Int_t i = 1; i <= nbin; ++i) {
        Double_t content = originalHist->GetBinContent(i);
        Double_t sqerr   = content * content * 0.3 * 0.3;
        errorHist->SetBinContent(i, sqerr);
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

void getSquare0p30Histogram(const char* inputFileName,
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

    createErrorHistogram(originalHist, outputFileName, outputHistPath);
    inputFile.Close();
}
