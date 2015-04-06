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
#include "Task.h"
#include <vector>
#include <iostream>

class FixtureBfcTUI : public CppUnit::TestFixture {
 public:
  CPPUNIT_TEST_SUITE(FixtureBfcTUI);
  CPPUNIT_TEST(testPrintDay);
  CPPUNIT_TEST(testShowRecord);
  CPPUNIT_TEST(testWriteRecord);
  CPPUNIT_TEST(testBriefReport);
  CPPUNIT_TEST(testTimelineVer);
  CPPUNIT_TEST(testTimelineHor);
  CPPUNIT_TEST(testSelectTask);
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
   */ 
  void testPrintDay() {
    std::stringstream ss;
    tui->printDay(ss,Date(20150302),10);
    std::string s;
    ss>>s;
    CPPUNIT_ASSERT("2015-3-2" == s);
  }

  /**    Tests for BfcTUI::showRecord(std::ostream&,std::vector<Task>&,int);
   *      
   */ 
  void testShowRecord() {
    std::vector<Task> ts;
    ts.push_back(Task("Test",std::vector<State>(),1));
    ts[0].getStates().push_back(State("S1",Date(20150301)));
    std::stringstream ss;
    tui->showRecord(ss,ts,1);
    std::string s, result="";
    while (ss>>s) {
      result += s;
    }
    CPPUNIT_ASSERT("Taskname:TestDetails:[S1]2015-3-1" == result);
  }

  /**    Tests for BfcTUI::writeRecord(std::ostream&,std::vector<Task>&);
   *      
   */ 
  void testWriteRecord() {
    std::vector<Task> ts;
    ts.push_back(Task("Test",std::vector<State>(),1));
    ts[0].getStates().push_back(State("S1 + S2 + S3",Date(20150301)));
    std::stringstream ss;
    tui->writeRecord(ss,ts);
    std::string s, result="";
    while (ss>>s) {
      result += s;
    }
    CPPUNIT_ASSERT("Test[S1+S2+S3]201503011" == result);
  }

  /**    Tests for BfcTUI::briefReport(std::ostream&,std::vector<Task>&);
   *      
   */ 
  void testBriefReport() {
    std::vector<Task> ts;
    ts.push_back(Task("1",std::vector<State>(),0));
    ts.push_back(Task("2",std::vector<State>(),2));
    ts.push_back(Task("3",std::vector<State>(),0));
    ts.push_back(Task("4",std::vector<State>(),1));
    ts.push_back(Task("5",std::vector<State>(),1));
    tui->setNumOfTaskUncomplete(2);
    tui->setNumOfTaskCancelled(1);
    std::stringstream ss;
    tui->briefReport(ss,ts);
    std::string s, result="";
    while (ss>>s) {
      result += s;
    }
    CPPUNIT_ASSERT("Firstdateoftherecording:20991231Lastdateofdataupdating:19700101Numberoftasksinprogress:2Numberoftaskscompleted:2Numberoftaskscancalled:1" == result);
  }

 /**    Tests for vertical timeline
   *      
   */ 
  void testTimelineVer () {
    tui->setStartDate(Date(20150225));
    tui->setEndDate(Date(20150308));
    std::vector<Task> ts;
    ts.push_back(Task("Test1",std::vector<State>(),1));
    ts[0].getStates().push_back(State("XXXX",Date(20150301)));
    ts.push_back(Task("Test2",std::vector<State>(),0));
    ts[1].getStates().push_back(State("YYY",Date(20150302)));
    std::stringstream ss;
    tui->timeline(ss,ts,Date(20150228),Date(20150303),1);
    std::string s, result="";
    while (ss>>s) {
      result += s;
    }
    CPPUNIT_ASSERT("Date\\TaskTest1Test22015-2-282015-3-1XXXX2015-3-2YYY2015-3-3" == result);
  }

 /**    Tests for horizontal timeline
   *      
   */ 
  void testTimelineHor () {
    tui->setStartDate(Date(20150225));
    tui->setEndDate(Date(20150308));
    std::vector<Task> ts;
    ts.push_back(Task("Test1",std::vector<State>(),1));
    ts[0].getStates().push_back(State("XXXX",Date(20150301)));
    ts.push_back(Task("Test2",std::vector<State>(),0));
    ts[1].getStates().push_back(State("YYY",Date(20150302)));
    std::stringstream ss;
    tui->timeline(ss,ts,Date(20150228),Date(20150303),0);
    std::string s, result="";
    while (ss>>s) {
      result += s;
    }
    CPPUNIT_ASSERT("Task\\Date2015-2-282015-3-12015-3-22015-3-3Test1XXXXTest2YYY" == result);
  }

 /**    Tests for selectTask()
   *     
   *    Test 1: select a uncompleted task would return correct number
   *    Test 2: the prompt information should exclude finished tasks
   */ 
  void testSelectTask() {
    std::vector<Task> ts;
    ts.push_back(Task("Test1",std::vector<State>(),1));
    ts.push_back(Task("Test2",std::vector<State>(),0));
    std::stringstream sin,sout;
    sin<<2;
    CPPUNIT_ASSERT(tui->selectTask(sout,sin,ts) == 1);
    std::string result="", s;
    while (sout>>s) {
      result += s;
    }
    std::cout<<result<<std::endl;
    CPPUNIT_ASSERT("(0-Random)(2-Test2)>>>" == result);
  }

};
#endif
