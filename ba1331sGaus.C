{
  c1 = new TCanvas("c1", "Ba-133 1 second Data Gaussian Fit", 800, 600);

  h = new TH1F("h","Number of Decay Distribution(1 second)-Gaussian Fit",7,0,14);

  fgaus = new TF1("gaus",0,14);
  fgaus->SetParameters(2,6,2);

  float data[100] = {4,9,6,7,7,4,6,2,10,8,3,8,10,11,7,10,4,4,9,7,7,10,10,5,4,6,6,5,5,7,4,9,3,7,10,3,8,1,6,6,7,4,8,4,13,7,10,7,8,9,9,6,3,7,4,3,4,7,10,2,7,3,10,7,8,2,6,5,8,6,6,7,3,5,10,5,9,4,8,8,4,8,8,9,9,6,8,5,6,8,8,11,4,4,3,8,7,4,10,10};

  for(int i = 0; i<100; i++){
    h->Fill(data[i]);
  }

  h->SetXTitle("Number of decays");
  h->SetYTitle("Counts");

  h->Fit("fgaus","E");
  h->Draw("E");

  gStyle->SetOptStat(111111);
  gStyle->SetOptFit(1111);

  c1->Draw();

}
