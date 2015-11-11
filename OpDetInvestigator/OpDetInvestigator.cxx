#ifndef TEST_USERANALYSIS_CXX
#define TEST_USERANALYSIS_CXX

#include "OpDetInvestigator.hh"
#include <iostream>

opana::OpDetInvestigator::OpDetInvestigator()
  : fAlgName("OpDetInvestigator")
{}

void opana::OpDetInvestigator::SetupOutputTree(TTree* tfs_tree){
  fTree = tfs_tree;

  std::string title = fAlgName + " Tree";
  fTree->SetObject(fTree->GetName(),title.c_str());
}

void opana::OpDetInvestigator::RunAnalysis(){
  PrintInfo();
}

void opana::OpDetInvestigator::PrintInfo(){
  std::cout << "\n================================== OpDetInvestigator ==========================" << std::endl;
  std::cout << "This is a ub_OpDetInvestigator class called " << fAlgName << std::endl;
  std::cout << "\tThere is an output tree called "
	    << fTree->GetName() << " (" << fTree->GetTitle() << ")" << std::endl;
  std::cout << "==========================================================================\n" << std::endl;
}

#endif
