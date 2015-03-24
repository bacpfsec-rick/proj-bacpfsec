/**
 * @file   TestState.cc
 * @Author Bacpfsec Rick
 * @date   20150324
 * @brief  Test program for State Class
 *
 * TestDate applies CppUnit test towards Date Class
 */

#include "FixtureState.h"

int main() {
  CppUnit::TextUi::TestRunner runner;
  runner.addTest(FixtureState::suite());
  runner.run();

  return 0;
}
