{
  c1 = new TCanvas("c1", "Ba-133 10 second Data Gaussian Fit", 800, 600);

  h = new TH1F("h","Number of Decay Distribution(10 seconds)-Gaussian Fit",10,45,85);

  fgaus = new TF1("fgaus","gaus",50,80);
  fgaus->SetParameters(6,60,3);

  float data[100] = {60,52,59,69,68,70,65,69,65,54,56,63,72,51,67,55,63,66,67,56,58,57,72,65,55,55,71,66,58,73,60,56,70,62,64,66,49,60,66,60,88,52,55,49,46,66,56,62,65,60,67,51,68,54,49,47,76,68,69,62,55,82,74,73,58,73,74,60,56,63,72,58,49,63,56,55,63,65,61,65,63,58,46,60,60,48,60,62,69,62,75,57,57,79,59,56,59,76,68,67};

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
