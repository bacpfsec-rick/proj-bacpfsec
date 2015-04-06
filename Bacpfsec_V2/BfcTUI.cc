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
