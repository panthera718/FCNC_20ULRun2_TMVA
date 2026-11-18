#include <TH1.h>
#include <TFile.h>

void createErrorHistogram(const TH1* originalHist1, const TH1* originalHist2, const char* outputFileName, const char* outputHistPath) {
    const TAxis *axis1 = originalHist1->GetXaxis();
    const TAxis *axis2 = originalHist2->GetXaxis();
    if (axis1->GetNbins() == axis2->GetNbins() && 
        axis1->GetXmin() == axis2->GetXmin() && 
        axis1->GetXmax() == axis2->GetXmax())
    {
        cout << "The format of two histograms is equal." << endl;
    } else {
        cout << "The format of two histograms is different." << endl;
        return;
    }

    TH1* errorHist = new TH1D(outputHistPath, "Histogram with Errors", originalHist1->GetNbinsX(), originalHist1->GetXaxis()->GetXmin(), originalHist1->GetXaxis()->GetXmax());
    for (Int_t i = 0; i < originalHist1->GetNbinsX(); ++i) {
        Double_t NonFRErrorHist = originalHist1->GetBinError(i+1);
        Double_t NonFRHist = originalHist1->GetBinContent(i+1);
        Double_t FRHist = originalHist2->GetBinContent(i+1);
        Double_t error;
        if ( abs(NonFRHist) < 0.00001 ) {
            error = (NonFRErrorHist/(abs(NonFRHist)+0.00001))*FRHist;
        } else {
            error = (NonFRErrorHist/abs(NonFRHist))*FRHist;
        }
        Double_t square_error = error * error;
        errorHist->SetBinContent(i+1, square_error);
    }
    TFile outputFile(outputFileName, "RECREATE");
    errorHist->Write();
    delete errorHist;
    outputFile.Close();
}

void getSquareErrorHistogram(const char* inputFileName1, const char* histPath1, const char* inputFileName2, const char* histPath2, const char* outputFileName, const char* outputHistPath) {
    TFile inputFile1(inputFileName1);
    if (!inputFile1.IsOpen()) {
        std::cerr << "Error: Failed to open input file " << inputFileName1 << std::endl;
        return;
    }
    TH1* originalHist1 = dynamic_cast<TH1*>(inputFile1.Get(histPath1));
    if (!originalHist1) {
        std::cerr << "Error: Failed to retrieve histogram from " << histPath1 << " in file " << inputFileName1 << std::endl;
        return;
    }
    TFile inputFile2(inputFileName2);
    if (!inputFile2.IsOpen()) {
        std::cerr << "Error: Failed to open input file " << inputFileName2 << std::endl;
        return;
    }
    TH1* originalHist2 = dynamic_cast<TH1*>(inputFile2.Get(histPath2));
    if (!originalHist2) {
        std::cerr << "Error: Failed to retrieve histogram from " << histPath2 << " in file " << inputFileName2 << std::endl;
        return;
    }
    createErrorHistogram(originalHist1, originalHist2, outputFileName, outputHistPath);
    inputFile1.Close();
    inputFile2.Close();
}
