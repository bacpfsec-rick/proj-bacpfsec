/**
 * @file   BfcPrototype.cc
 * @Author Bacpfsec Rick
 * @date   20150405
 * @brief  Implementation for BfcPrototype Class
 *
 * Task Class for actual recording of one task
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
