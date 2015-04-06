/**
 * @file   TestBcfPrototype.cc
 * @Author Bacpfsec Rick
 * @date   20150405
 * @brief  Test program for BcfPrototype Class
 *
 * TestBcfPrototype applies CppUnit test towards BcfPrototype Class
 */

#include "FixtureBfcPrototype.h"

int main() {
  CppUnit::TextUi::TestRunner runner;
  runner.addTest(FixtureBfcPrototype::suite());
  runner.run();

  return 0;
}
