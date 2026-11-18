#include <TH1.h>
#include <TFile.h>
#include "TAxis.h"

void createErrorHistogram(const TH1* originalHist0, const TH1* originalHist1, const TH1* originalHist2, const TH1* originalHist3, const char* outputFileName, const char* outputHistPath) {
    const TAxis *axis0 = originalHist0->GetXaxis();
    const TAxis *axis1 = originalHist1->GetXaxis();
    const TAxis *axis2 = originalHist2->GetXaxis();
    const TAxis *axis3 = originalHist3->GetXaxis();
    if (axis1->GetNbins() == axis2->GetNbins() && 
        axis1->GetXmin() == axis2->GetXmin() && 
        axis1->GetXmax() == axis2->GetXmax() &&
        axis1->GetNbins() == axis3->GetNbins() && 
        axis1->GetXmin() == axis3->GetXmin() && 
        axis1->GetXmax() == axis3->GetXmax() &&
        axis1->GetNbins() == axis0->GetNbins() && 
        axis1->GetXmin() == axis0->GetXmin() && 
        axis1->GetXmax() == axis0->GetXmax())
    {
        cout << "The format of four histograms is equal." << endl;
    } else {
        cout << "The format of four histograms is different." << endl;
        return;
    }

    TH1* copiedHist = static_cast<TH1*>(originalHist0->Clone(outputHistPath));
    copiedHist->SetTitle(outputHistPath);
    TH1* errorHist = new TH1D("Histogram_with_Errors", "Histogram with Errors", axis1->GetNbins(), axis1->GetXmin(), axis1->GetXmax());
    for (Int_t i = 0; i < axis1->GetNbins(); ++i) {
        Double_t content1 = TMath::Abs( originalHist1->GetBinContent(i+1) );
        Double_t content2 = TMath::Abs( originalHist2->GetBinContent(i+1) );
        Double_t content3 = TMath::Abs( originalHist3->GetBinContent(i+1) );
        Double_t sqrt_content = TMath::Sqrt(content1+content2+content3);
        errorHist->SetBinContent(i+1, sqrt_content);
    }
    copiedHist->Add(errorHist);

    TFile outputFile(outputFileName, "RECREATE");
    copiedHist->Write();
    delete copiedHist;
    delete errorHist;
    outputFile.Close();
}

void getUncertaintyUpHistogram(const char* inputFileName0, const char* histPath0, const char* inputFileName1, const char* histPath1, const char* inputFileName2, const char* histPath2, const char* inputFileName3, const char* histPath3, const char* outputFileName, const char* outputHistPath) {
    TFile inputFile0(inputFileName0);
    if (!inputFile0.IsOpen()) {
        std::cerr << "Error: Failed to open input file " << inputFileName0 << std::endl;
        return;
    }
    TH1* originalHist0 = dynamic_cast<TH1*>(inputFile0.Get(histPath0));
    if (!originalHist0) {
        std::cerr << "Error: Failed to retrieve histogram from " << histPath0 << " in file " << inputFileName0 << std::endl;
        return;
    }
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
    TFile inputFile3(inputFileName3);
    if (!inputFile3.IsOpen()) {
        std::cerr << "Error: Failed to open input file " << inputFileName3 << std::endl;
        return;
    }
    TH1* originalHist3 = dynamic_cast<TH1*>(inputFile3.Get(histPath3));
    if (!originalHist3) {
        std::cerr << "Error: Failed to retrieve histogram from " << histPath3 << " in file " << inputFileName3 << std::endl;
        return;
    }
    createErrorHistogram(originalHist0, originalHist1, originalHist2, originalHist3, outputFileName, outputHistPath);
    inputFile0.Close();
    inputFile1.Close();
    inputFile2.Close();
    inputFile3.Close();
}
