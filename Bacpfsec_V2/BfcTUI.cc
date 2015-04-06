/**
 * @file   BfcTUI.cc
 * @Author Bacpfsec Rick
 * @date   20150405
 * @brief  Implementation for BfcTUI Class
 *
 * BfcTUI is the TUI version of program
 */
#include "BfcTUI.h"
#include <sstream>
#include <iomanip>

BfcTUI::BfcTUI() {
  BfcPrototype::init();
}

BfcTUI::~BfcTUI() {
  BfcPrototype::init();
}

void BfcTUI::printDay(std::ostream& os, Date d, int width) {
  std::stringstream ss;
  int time = d.getValue();
  ss<<(time/10000)<<"-"<<(time/100%100)<<"-"<<(time%100);
  std::string t;
  ss>>t;
  os<<std::left<<std::setw(width)<<t;
}

void BfcTUI::showRecord(std::ostream& os, std::vector<Task>& ts, int s) {
  for(int i=0; i<ts.size(); ++i) {
    if (ts[i].getStatus()==s) { 
      os<<"    Task name : "<<ts[i].getTaskName()<<std::endl;
      os<<"     Details  : ";
      for(int j=0; j<ts[i].getStates().size(); ++j) {
	os<<"[";
	std::string content = ts[i].getStates()[j].getContent();
	os<<content<<"]";
	Date date = ts[i].getStates()[j].getDate();
	int  width = 8;
	if (date.getValue()/1000%10==0) { // XX0XXX
	  --width;
	}
	if (date.getValue()/10%10==0) {   // XXXX0X
	  --width;
	}
	printDay(os,date,width);
	os<<std::left<<std::setw(18-content.size()-2-width);
      }
      os<<std::endl;
    }
  }
}

void BfcTUI::writeRecord(std::ostream& os, std::vector<Task>& ts) {
  for(int i=0; i<ts.size(); ++i) {
    os<<ts[i].getTaskName()<<" ";
    for(int j=0; j<ts[i].getStates().size(); ++j) {
      os<<"[ "<<ts[i].getStates()[j].getContent()<<" ] "
	 <<ts[i].getStates()[j].getDate().getValue()<<" ";
    }
    os<<ts[i].getStatus()<<std::endl;
  }
  setRecordLoaded(false);
}

void BfcTUI::briefReport(std::ostream& os, std::vector<Task>& ts) {
  os<<"   First date of the recording : "<<
    getStartDate().getValue()<<std::endl;
  os<<"   Last date of data updating  : "<<
    getEndDate().getValue()<<std::endl;
  os<<"   Number of tasks in progress : "<<
    getNumOfTaskUncomplete()<<std::endl;
  os<<"   Number of tasks completed   : "<<
    (ts.size()-getNumOfTaskUncomplete()-getNumOfTaskCancelled())<<std::endl;
  os<<"   Number of tasks cancalled   : "<<
    getNumOfTaskCancelled()<<std::endl;
}
