#include <TH1.h>
#include <TFile.h>
#include <TAxis.h>
#include <TMath.h>
#include <iostream>

void createErrorHistogram(const TH1* originalHist0,
                          const TH1* originalHist1,
                          const TH1* originalHist2,
                          const TH1* originalHist3,
                          const char* outputFileName,
                          const char* outputHistPath) {
    const TAxis *axis0 = originalHist0->GetXaxis();
    const TAxis *axis1 = originalHist1->GetXaxis();
    const TAxis *axis2 = originalHist2->GetXaxis();
    const TAxis *axis3 = originalHist3->GetXaxis();
    if (axis0->GetNbins() == axis1->GetNbins() &&
        axis0->GetXmin()   == axis1->GetXmin() &&
        axis0->GetXmax()   == axis1->GetXmax() &&
        axis0->GetNbins() == axis2->GetNbins() &&
        axis0->GetXmin()   == axis2->GetXmin() &&
        axis0->GetXmax()   == axis2->GetXmax() &&
        axis0->GetNbins() == axis3->GetNbins() &&
        axis0->GetXmin()   == axis3->GetXmin() &&
        axis0->GetXmax()   == axis3->GetXmax()) {
        std::cout << "The format of four histograms is equal." << std::endl;
    } else {
        std::cout << "The format of four histograms is different." << std::endl;
        return;
    }

    Bool_t oldAddDir = TH1::AddDirectoryStatus();
    TH1::AddDirectory(kFALSE);
    TH1* copiedHist = static_cast<TH1*>(originalHist0->Clone(outputHistPath));
    TH1::AddDirectory(oldAddDir);
    copiedHist->SetTitle(outputHistPath);
    copiedHist->SetDirectory(0);

    TH1* errorHist = static_cast<TH1*>(originalHist0->Clone("Histogram_with_Errors"));
    errorHist->Reset();
    errorHist->SetTitle("Histogram with Errors");
    errorHist->SetDirectory(0);

    Int_t nbin = axis0->GetNbins();
    for (Int_t i = 1; i <= nbin; ++i) {
        Double_t v1 = TMath::Abs(originalHist1->GetBinContent(i));
        Double_t v2 = TMath::Abs(originalHist2->GetBinContent(i));
        Double_t v3 = TMath::Abs(originalHist3->GetBinContent(i));
        Double_t val = TMath::Sqrt(v1 + v2 + v3);
        errorHist->SetBinContent(i, val);
    }

    copiedHist->Add(errorHist, -1.0);

    TFile outputFile(outputFileName, "RECREATE");
    if (!outputFile.IsOpen()) {
        std::cerr << "Error: Failed to open output file "
                  << outputFileName << std::endl;
        delete copiedHist;
        delete errorHist;
        return;
    }
    copiedHist->Write("", TObject::kOverwrite);
    delete copiedHist;
    delete errorHist;
    outputFile.Close();
}

void getUncertaintyDownHistogram(const char* inputFileName0,
                                 const char* histPath0,
                                 const char* inputFileName1,
                                 const char* histPath1,
                                 const char* inputFileName2,
                                 const char* histPath2,
                                 const char* inputFileName3,
                                 const char* histPath3,
                                 const char* outputFileName,
                                 const char* outputHistPath) {
    TFile f0(inputFileName0);
    if (!f0.IsOpen()) {
        std::cerr << "Error: Failed to open input file " << inputFileName0 << std::endl;
        return;
    }
    TH1* h0 = dynamic_cast<TH1*>(f0.Get(histPath0));

    TFile f1(inputFileName1);
    TH1* h1 = dynamic_cast<TH1*>(f1.Get(histPath1));

    TFile f2(inputFileName2);
    TH1* h2 = dynamic_cast<TH1*>(f2.Get(histPath2));

    TFile f3(inputFileName3);
    TH1* h3 = dynamic_cast<TH1*>(f3.Get(histPath3));

    if (!h0 || !h1 || !h2 || !h3) {
        std::cerr << "Error: Failed to retrieve one or more histograms." << std::endl;
        return;
    }

    createErrorHistogram(h0, h1, h2, h3, outputFileName, outputHistPath);

    f0.Close();
    f1.Close();
    f2.Close();
    f3.Close();
}
