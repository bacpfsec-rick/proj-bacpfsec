/**
 * @file   BfcPrototype.cc
 * @Author Bacpfsec Rick
 * @date   20150405
 * @brief  Implementation for BfcPrototype Class
 *
 * BfcPrototype is the base class for TUI and GUI
 */
#include "BfcPrototype.h"

BfcPrototype::BfcPrototype() {
  init();
}

BfcPrototype::~BfcPrototype() {
  init();
}

void BfcPrototype::setRecordLoaded(bool rl) {
  recordLoaded = rl;
}

bool BfcPrototype::getRecordLoaded() {
  return recordLoaded;
}

void BfcPrototype::setStartDate(const Date& sd) {
  startDate = sd;
}

Date BfcPrototype::getStartDate() {
  return startDate;
}

void BfcPrototype::setEndDate(const Date& ed) {
  endDate = ed;
}

Date BfcPrototype::getEndDate() {
  return endDate;
}

void BfcPrototype::setNumOfTaskUncomplete(int ntu) {
  numOfTaskUncomplete = ntu;
}

int BfcPrototype::getNumOfTaskUncomplete() {
  return numOfTaskUncomplete;
}

void BfcPrototype::setNumOfTaskCancelled(int ntc) {
  numOfTaskCancelled = ntc;
}

int BfcPrototype::getNumOfTaskCancelled() {
  return numOfTaskCancelled;
}

std::vector<Task>& BfcPrototype::getTasks() {
  return tasks;
}

void BfcPrototype::init() {
  recordLoaded = false;
  startDate = Date(20991231);
  endDate = Date(19700101);
  numOfTaskUncomplete = 0;
  numOfTaskCancelled = 0;
  if( !tasks.empty() ) {
    tasks.clear();
  }
}

void BfcPrototype::readStates(std::istream& is, Task& bk) {
  std::string s;
  if (is>>s) {
    if ( s=="1" ) {          // task completed
      bk.setStatus(1);
    } else if ( s=="0" ) {   // task in progress
      bk.setStatus(0);
      ++numOfTaskUncomplete;
    } else if ( s=="2" ) {   // task cancelled
      bk.setStatus(2);
      ++numOfTaskCancelled;
    } else {                 // s=="["
      is>>s;
      std::string content = "";
      while( s!="]" ) {
	content += (s+" ");
	is>>s;
      }
      State newState;
      int date;
      newState.setContent(content);
      is>>date;
      // set up the start date and end date
      if ( startDate.getValue() > date ) {
	startDate.setValue(date);
      }
      if ( endDate.getValue() < date ) {
	endDate.setValue(date);
      }
      newState.setDate(Date(date));
      bk.getStates().push_back(newState);
      // recursively read next state
      readStates(is,bk);
    }
  }
};

void BfcPrototype::readTasks(std::istream& is, std::vector<Task>& ts) {
  std::string s;
  if (is>>s) {
    Task newTask;
    newTask.setTaskName(s);
    readStates(is,newTask);
    ts.push_back(newTask);
    // recursively read next task
    readTasks(is,ts);
  }
  recordLoaded = true;
}
