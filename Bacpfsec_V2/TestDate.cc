/**
 * @file   TestDate.cc
 * @Author Bacpfsec Rick
 * @date   20150324
 * @brief  Test program for Date Class
 *
 * TestDate applies CppUnit test towards Date Class
 */

#include "FixtureDate.h"
#include "Date.h"

int main() {
  CppUnit::TextUi::TestRunner runner;
  runner.addTest(FixtureDate::suite());
  runner.run();

  return 0;
}
