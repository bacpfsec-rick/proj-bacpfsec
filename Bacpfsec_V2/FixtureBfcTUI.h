/**
 * @file   FixtureBfcTUI.h
 * @Author Bacpfsec Rick
 * @date   20150405
 * @brief  CppUnit Fixture setup for BfcTUI class
 *
 * FixtureBfcTUI is used in TestBfcTUI for BfcTUI Class
 */

#ifndef _FIXTUREBFCTUI_H_
#define _FIXTUREBFCTUI_H_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include "BfcTUI.h"
#include <vector>
#include <iostream>

class FixtureBfcTUI : public CppUnit::TestFixture {
 public:
  CPPUNIT_TEST_SUITE(FixtureBfcTUI);
  CPPUNIT_TEST(testPrintDay);
  CPPUNIT_TEST_SUITE_END();

 private:
  BfcTUI* tui;

 public:
  void setUp() {
    tui = new BfcTUI();
  }

  void tearDown() {
    delete tui;
  }

  /**    Tests for BfcTUI::printDay(ostream&, Date, int);
   *     
   *
   */ 
  void testPrintDay() {
    std::stringstream ss;
    tui->printDay(ss,Date(20150302),15);
  }

};
#endif
