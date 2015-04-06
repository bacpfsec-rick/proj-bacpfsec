/**
 * @file   TestBcfTUI.cc
 * @Author Bacpfsec Rick
 * @date   20150405
 * @brief  Test program for BcfTUI Class
 *
 * TestBcfTUI applies CppUnit test towards BcfTUI Class
 */

#include "FixtureBfcTUI.h"

int main() {
  CppUnit::TextUi::TestRunner runner;
  runner.addTest(FixtureBfcTUI::suite());
  runner.run();

  return 0;
}
