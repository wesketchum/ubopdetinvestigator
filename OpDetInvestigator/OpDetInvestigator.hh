/**
 * \file OpDetInvestigator.h
 *
 * 
 * \brief Little sample program for establishing a user analysis space.
 *
 * @author wketchum
*/

#ifndef TEST_USERANALYSIS_H
#define TEST_USERANALYSIS_H

#include <string>

#include "TTree.h"

#include "RawData/OpDetWaveform.h"

namespace opana{
  class OpDetInvestigator;
}

class opana::OpDetInvestigator{
  
public:
  
  /// Default constructor
  OpDetInvestigator();

  /// Default destructor
  virtual ~OpDetInvestigator(){};

  void RunAnalysis(std::vector<raw::OpDetWaveform> const&);
  void SetupOutputTree(TTree*);
  
 private:

  std::string fAlgName;

  //this is gonna be a per Waveform Tree
  TTree*      fWaveformTree;
  Double_t  waveform_start_time;
  UInt_t    waveform_channel;
  UInt_t    waveform_size;
  Double_t  waveform_peak_time;
  Short_t   waveform_peak_value;
  
  void PrintInfo();
  void AnalyzeWaveform(raw::OpDetWaveform const&);
  
};

#endif
