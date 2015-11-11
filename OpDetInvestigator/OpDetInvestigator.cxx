#ifndef TEST_USERANALYSIS_CXX
#define TEST_USERANALYSIS_CXX

#include "OpDetInvestigator.hh"
#include <iostream>

opana::OpDetInvestigator::OpDetInvestigator()
  : fAlgName("OpDetInvestigator")
{}

void opana::OpDetInvestigator::SetupOutputTree(TTree* tfs_tree){
  fWaveformTree = tfs_tree;

  std::string title = fAlgName + ", Waveform Tree";
  fWaveformTree->SetObject(fWaveformTree->GetName(),title.c_str());

  fWaveformTree->Branch("waveform_start_time",&waveform_start_time,"waveform_start_time/D");
  fWaveformTree->Branch("waveform_channel",&waveform_channel,"waveform_channel/i");
  fWaveformTree->Branch("waveform_size",&waveform_size,"waveform_size/i");
  fWaveformTree->Branch("waveform_peak_time",&waveform_peak_time,"waveform_peak_time/D");
  fWaveformTree->Branch("waveform_peak_value",&waveform_peak_value,"waveform_peak_value/S");
}

void opana::OpDetInvestigator::RunAnalysis(std::vector<raw::OpDetWaveform> const& waveform_vec){
  PrintInfo();

  for( auto const& waveform : waveform_vec)
    AnalyzeWaveform(waveform);
}

void opana::OpDetInvestigator::AnalyzeWaveform(raw::OpDetWaveform const& waveform){

  waveform_peak_time = 0;
  waveform_peak_value = -999;

  for(size_t i_w=0; i_w<waveform.size(); i_w++){
    if(waveform[i_w]>waveform_peak_value){
      waveform_peak_value = waveform[i_w];
      waveform_peak_time = (Double_t)i_w;
    }
  }
  waveform_size = waveform.size();
  waveform_start_time = waveform.TimeStamp();
  waveform_channel = waveform.ChannelNumber();

  fWaveformTree->Fill();
  
}

void opana::OpDetInvestigator::PrintInfo(){
  std::cout << "\n================================== OpDetInvestigator ==========================" << std::endl;
  std::cout << "This is a ub_OpDetInvestigator class called " << fAlgName << std::endl;
  std::cout << "\tThere is an output tree called "
	    << fWaveformTree->GetName() << " (" << fWaveformTree->GetTitle() << ")" << std::endl;
  std::cout << "==========================================================================\n" << std::endl;
}

#endif
