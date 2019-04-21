{
  c1 = new TCanvas("c1", "Cs-137 11 second Data Poisson Fit", 800, 600);

  h = new TH1F("h","Number of Decay Distribution(1 second)-Poisson Fit",6,2,20);

  fpoisson = new TF1("fpoisson","[0]*TMath::Poisson(x,[1])",2,20);
  fpoisson->SetParameters(2,13);

  float data[100] = {8,8,11,11,14,17,12,11,11,7,15,6,12,9,13,17,10,5,10,12,10,10,13,13,14,8,7,11,10,10,13,12,13,10,16,16,8,10,12,9,10,11,10,11,15,6,14,12,11,10,8,7,13,6,9,10,10,5,11,10,14,12,6,11,14,6,14,14,14,12,11,6,7,8,11,12,11,9,5,14,11,4,14,10,13,6,14,6,12,12,10,10,3,9,3,12,15,12,10,9};

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
