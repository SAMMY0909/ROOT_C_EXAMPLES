#include "TH1.h"
#include "TRandom.h"
#include "TCanvas.h"
#include "TLine.h"
#include <iostream>

void hist2() {
              TH1D * h2=new TH1D("h2","gauss",100,0.,10.);
              for(int i=0;i<10000;i++){
              double x=gRandom->Gaus(5,1);
              h2->Fill(x);
              }
              h2->Draw();
              
              TH1D * h3=new TH1D("h3","flat",100,0.,10.);
              for(int i=0;i<10000;i++){
              double x=gRandom->Uniform(0,10);
              h3->Fill(x);
              }
              new TCanvas("c2","c2");
              h3->Draw();
              
              TH1D * h4=new TH1D("h4","add flat n gauss",100,0.,10.);
              h4->Add(h2,h3);
              new TCanvas("c3","c3");
              h4->SetLineColor(2);
              h4->Draw("HIST");
              
              TH1D * h5=new TH1D("h5","second flat",100,0.,10.);
              h5->Scale(10000/100000);
              for(int i=0;i<100000;i++){
              double x=gRandom->Uniform(0,10);
              h5->Fill(x);
              }
              new TCanvas("c4","c4");
              h5->Draw();
              
              h5->Sumw2();
              h4->Sumw2();
              
              TH1D * h6=new TH1D("h6","subtract sum n flat",100,0.,10.);
              h6->Add(h4,h5,1,-1);
              new TCanvas("c5","c5");
			  h6->SetMarkerColor(6);
			  h6->SetMarkerStyle(20);
			  h6->SetMarkerSize(.6);              h6->Draw("E");
              TLine * line = new TLine(0,0,10,0);
				line->Draw();
   
              
              }
              
