/**
 * @file   FixtureTask.h
 * @Author Bacpfsec Rick
 * @date   20150405
 * @brief  CppUnit Fixture setup for BfcPrototype class
 *
 * FixtureBfcPrototype is used in TestBfcPrototype for BfcPrototype Class
 */

#ifndef _FIXTUREBfcPrototype_H_
#define _FIXTUREBfcPrototype_H_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include "BfcPrototype.h"
#include <vector>
#include <iostream>

class FixtureBfcPrototype : public CppUnit::TestFixture {
 public:
  CPPUNIT_TEST_SUITE(FixtureBfcPrototype);
  CPPUNIT_TEST(testInitAndGetters);
  CPPUNIT_TEST(testSetters);
  CPPUNIT_TEST(testTasksGetter);
  CPPUNIT_TEST(testReadStates);
  CPPUNIT_TEST(testReadTasks);
  CPPUNIT_TEST_SUITE_END();

 private:
  BfcPrototype* bfc;

 public:
  void setUp() {
    bfc = new BfcPrototype();
  }

  void tearDown() {
    delete bfc;
  }

  /**    Tests for Getters and init
   *     
   *     Test1: getRecordLoaded()
   *     Test2: getStartDate()
   *     Test3: getEndDate()
   *     Test4: getNumOfTaskUncomplete()
   *     Test5: getNumOfTaskCancelled()
   *
   */ 
  void testInitAndGetters() {
    CPPUNIT_ASSERT(bfc->getRecordLoaded() == false);
    CPPUNIT_ASSERT(bfc->getStartDate() == Date(20991231));
    CPPUNIT_ASSERT(bfc->getEndDate() == Date(19700101));
    CPPUNIT_ASSERT(bfc->getNumOfTaskUncomplete() == 0);
    CPPUNIT_ASSERT(bfc->getNumOfTaskCancelled() == 0);
  }

  /**    Tests for Setters
   *
   *     Test1: setRecordLoaded()
   *     Test2: setStartDate()
   *     Test3: setEndDate()
   *     Test4: setNumOfTaskUncomplete()
   *     Test5: setNumOfTaskCancelled()
   *
   */ 
  void testSetters() {
    bfc->setRecordLoaded(true);
    CPPUNIT_ASSERT(bfc->getRecordLoaded() == true);
    bfc->setStartDate(Date(20150102));
    CPPUNIT_ASSERT(bfc->getStartDate() == Date(20150102));
    bfc->setEndDate(Date(19910102));
    CPPUNIT_ASSERT(bfc->getEndDate() == Date(19910102));
    bfc->setNumOfTaskUncomplete(5);
    CPPUNIT_ASSERT(bfc->getNumOfTaskUncomplete() == 5);
    bfc->setNumOfTaskCancelled(15);
    CPPUNIT_ASSERT(bfc->getNumOfTaskCancelled() == 15);
  }

  /**    Test for BfcPrototype::getTasks()
   *
   */ 
  void testTasksGetter() {
    std::vector<State> st;
    st.push_back(State("Today",Date(20150405)));
    Task nt("Trial",st,2);
    std::vector<Task>& ref = bfc->getTasks();
    ref.push_back(nt);
    CPPUNIT_ASSERT(ref[0].getTaskName() == "Trial");
    CPPUNIT_ASSERT(ref[0].getStatus() == 2);
    CPPUNIT_ASSERT((ref[0].getStates())[0].getContent() == "Today");
    CPPUNIT_ASSERT((ref[0].getStates())[0].getDate() == Date(20150405));
  }

  /**    Test for BfcPrototype::readStates(istream, Task&)
   *
   */ 
  void testReadStates() {
    Task t("New",std::vector<State>(),2);
    bfc->readStates(std::cin,t); // Input "[ ~P2 ] 20150302 [ ~P3 + ~P5 ] 20150304 1" to test
    std::vector<State>& ref = t.getStates();
    CPPUNIT_ASSERT(ref[0].getDate() == Date(20150302));
    CPPUNIT_ASSERT(ref[0].getContent() == "~P2 ");
    CPPUNIT_ASSERT(ref[1].getDate() == Date(20150304));
    CPPUNIT_ASSERT(ref[1].getContent() == "~P3 + ~P5 ");
    CPPUNIT_ASSERT(t.getStatus() == 1);
  }

  /**    Test for BfcPrototype::readStates(istream, vector<Task>&)
   *
   */ 
  void testReadTasks() {
    std::vector<Task> ts;
    bfc->readTasks(std::cin,ts);
    // Input: "Book1 [ ~P2 ] 20150302 [ ~P3 + ~P5 ] 20150304 1"
    //        "Book2 [ ~C1 ] 20150101 [ ~C3 ] 20150502 0"
    std::vector<Task>& ref = ts;
    std::vector<State>& ref0 = ts[0].getStates();
    std::vector<State>& ref1 = ts[1].getStates();
    CPPUNIT_ASSERT(ref[0].getTaskName() == "Book1");
    CPPUNIT_ASSERT(ref0[0].getDate() == Date(20150302));
    CPPUNIT_ASSERT(ref0[0].getContent() == "~P2 ");
    CPPUNIT_ASSERT(ref0[1].getDate() == Date(20150304));
    CPPUNIT_ASSERT(ref0[1].getContent() == "~P3 + ~P5 ");
    CPPUNIT_ASSERT(ref[0].getStatus() == 1);
    CPPUNIT_ASSERT(ref[1].getTaskName() == "Book2");
    CPPUNIT_ASSERT(ref1[0].getDate() == Date(20150101));
    CPPUNIT_ASSERT(ref1[0].getContent() == "~C1 ");
    CPPUNIT_ASSERT(ref1[1].getDate() == Date(20150502));
    CPPUNIT_ASSERT(ref1[1].getContent() == "~C3 ");
    CPPUNIT_ASSERT(ref[1].getStatus() == 0);
    CPPUNIT_ASSERT(bfc->getStartDate() == Date(20150101));
    CPPUNIT_ASSERT(bfc->getEndDate() == Date(20150502));
  }

};

#endif
