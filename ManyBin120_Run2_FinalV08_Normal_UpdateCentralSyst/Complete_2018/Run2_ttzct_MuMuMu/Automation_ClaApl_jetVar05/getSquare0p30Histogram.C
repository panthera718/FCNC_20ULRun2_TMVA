#include <TH1.h>
#include <TFile.h>

void createErrorHistogram(const TH1* originalHist, const char* outputFileName, const char* outputHistPath) {
    TH1* errorHist = new TH1D(outputHistPath, "Histogram with Errors", originalHist->GetNbinsX(), originalHist->GetXaxis()->GetXmin(), originalHist->GetXaxis()->GetXmax());
    for (Int_t i = 0; i < originalHist->GetNbinsX(); ++i) {
        Double_t content = originalHist->GetBinContent(i+1);
        Double_t square_content_0p30 = (0.3 * content) * (0.3 * content);
        errorHist->SetBinContent(i+1, square_content_0p30);
    }
    TFile outputFile(outputFileName, "RECREATE");
    errorHist->Write();
    delete errorHist;
    outputFile.Close();
}

void getSquare0p30Histogram(const char* inputFileName, const char* histPath, const char* outputFileName, const char* outputHistPath) {
    TFile inputFile(inputFileName);
    if (!inputFile.IsOpen()) {
        std::cerr << "Error: Failed to open input file " << inputFileName << std::endl;
        return;
    }
    TH1* originalHist = dynamic_cast<TH1*>(inputFile.Get(histPath));
    if (!originalHist) {
        std::cerr << "Error: Failed to retrieve histogram from " << histPath << " in file " << inputFileName << std::endl;
        return;
    }
    createErrorHistogram(originalHist, outputFileName, outputHistPath);
    inputFile.Close();
}
