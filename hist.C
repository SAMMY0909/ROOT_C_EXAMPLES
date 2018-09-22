#include "TH1.h"
#include "TRandom.h"
#include "TStyle.h"

void hist() { 

   TH1D * h1 = new TH1D("h1","h1",50,0,10);

   for (int i = 0; i < 1000; ++i) {
      double x = gRandom->Gaus(6,1);
      h1->Fill(x); 
   }


   // h1->ResetStats(); 


   h1->Draw();

   gStyle->SetOptStat(100110110);

}
