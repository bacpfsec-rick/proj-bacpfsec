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

class FixtureBfcPrototype : public CppUnit::TestFixture {
 public:
  CPPUNIT_TEST_SUITE(FixtureBfcPrototype);
  CPPUNIT_TEST(testInitAndGetters);
  CPPUNIT_TEST(testSetters);
  CPPUNIT_TEST(testTasksGetter);
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

};

#endif
