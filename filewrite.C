#include "TH1.h"
#include "TRandom.h"
#include "TCanvas.h"
#include "TLine.h"
#include <iostream>

void filewrite(){
		TFile* f = TFile::Open("filestore.root","RECREATE");
		TH1D* h1 = new TH1D("h1","h1",100,-5.,5.);
		h1->SetDirectory(0); 
		for (int i = 0; i < 10000; ++i){ 
		h1->Fill(gRandom->Exp(5));
		}
		h1->Fit("expo");
		h1->Draw("Hist");
		h1->Write();
		delete f;
		}

