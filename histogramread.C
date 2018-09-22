#include "TH1.h"
#include "TRandom.h"
#include "TCanvas.h"
#include "TLine.h"
#include <iostream>

void histogramread(){
		TFile* f = TFile::Open("filestore.root");
		TH1D* h=0;
		f->GetObject("h1",h);
		h->Draw("Hist");
		//delete f;
		}

