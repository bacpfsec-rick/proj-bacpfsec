/**
 * @file   TestTask.cc
 * @Author Bacpfsec Rick
 * @date   20150405
 * @brief  Test program for Task Class
 *
 * TestTask applies CppUnit test towards Task Class
 */

#include "FixtureTask.h"

int main() {
  CppUnit::TextUi::TestRunner runner;
  runner.addTest(FixtureTask::suite());
  runner.run();

  return 0;
}
