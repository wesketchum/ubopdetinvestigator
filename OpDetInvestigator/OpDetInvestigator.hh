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

namespace opana{
  class OpDetInvestigator;
}

class opana::OpDetInvestigator{
  
public:
  
  /// Default constructor
  OpDetInvestigator();

  /// Default destructor
  virtual ~OpDetInvestigator(){};

  void RunAnalysis();
  void SetupOutputTree(TTree*);
  
 private:

  std::string fAlgName;
  TTree*      fTree;
  
  void PrintInfo();

  
};

#endif
