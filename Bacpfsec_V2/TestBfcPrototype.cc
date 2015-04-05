/**
 * @file   TestTask.cc
 * @Author Bacpfsec Rick
 * @date   20150405
 * @brief  Test program for BfcPrototype Class
 *
 * TestBfcPrototype applies CppUnit test towards BfcPrototype Class
 */

#include "FixtureBfcPrototype.h"

int main() {
  CppUnit::TextUi::TestRunner runner;
  runner.addTest(FixtureBfcPrototype::suite());
  runner.run();

  return 0;
}
