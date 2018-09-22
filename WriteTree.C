#include "TH2.h"
#include "TProfile.h"
#include "TRandom.h"
#include "TCanvas.h"
#include <iostream>

void WriteTree()
{
 Event *myEvent = new Event();
 TFile f("AFile.root", "RECREATE");
 TTree *t = new TTree("myTree","A Tree");
 t->Branch("EventBranch", &myEvent);
 for (int e=0;e<100000;++e) {
 myEvent->Generate(); // hypothetical
 t->Fill();
 }
 t->Draw();
 t->Write();
}
