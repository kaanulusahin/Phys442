{
  c1 = new TCanvas("c1", "Cs-137 10 second Data Poisson Fit", 800, 600);

  h = new TH1F("h","Number of Decay Distribution(10 seconds)-Poisson Fit",12,80,140);

  fpoisson = new TF1("fpoisson","[0]*TMath::Poisson(x,[1])",80,140);
  fpoisson->SetParameters(10,100);

  float data[100] = {101,120,100,121,106,92,97,102,96,110,113,117,103,95,92,119,124,106,98,112,102,109,89,107,119,106,115,106,112,95,119,118,108,109,101,98,119,108,122,110,102,114,100,111,131,114,111,105,133,125,113,126,104,93,122,104,89,118,115,123,118,136,95,105,105,104,107,115,120,116,125,95,89,98,113,127,92,93,93,119,121,116,101,106,94,94,113,124,132,112,101,84,105,111,102,122,130,115,99,105};

  for(int i = 0; i<100; i++){
    h->Fill(data[i]);
  }

  h->SetXTitle("Number of decays");
  h->SetYTitle("Counts");

  h->Fit("fpoisson","E");
  h->Draw("E");

  gStyle->SetOptStat(111111);
  gStyle->SetOptFit(1111);
  
  c1->Draw();

}
