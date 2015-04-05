/**
 * @file   FixtureTask.h
 * @Author Bacpfsec Rick
 * @date   20150405
 * @brief  CppUnit Fixture setup for Task class
 *
 * FixtureTask is used in TestDate for Task Class
 */

#ifndef FIXTURETASK_H
#define FIXTURETASK_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Task.h"
#include <vector>

class FixtureTask : public CppUnit::TestFixture {
 public:
  CPPUNIT_TEST_SUITE(FixtureTask);
  CPPUNIT_TEST(testTaskNameGetter);
  CPPUNIT_TEST(testTaskNameSetter);
  CPPUNIT_TEST(testStatusGetter);
  CPPUNIT_TEST(testStatusSetter);
  CPPUNIT_TEST(testStateGetter);
  CPPUNIT_TEST(testStateSetter);
  CPPUNIT_TEST(testParaConstructor);
  CPPUNIT_TEST(testCopyConstructor);
  CPPUNIT_TEST_SUITE_END();

 private:
  Task* t;

 public:
  void setUp() {
    t = new Task();
  }

  void tearDown() {
    delete t;
  }

  /**    Test for Task::getTaskName()
   *
   */ 
  void testTaskNameGetter() {
    CPPUNIT_ASSERT("Empty Task" == t->getTaskName());
  }

  /**    Test for Task::setTaskName(string)
   *
   */ 
  void testTaskNameSetter() {
    t->setTaskName("New Task");
    CPPUNIT_ASSERT("New Task" == t->getTaskName());
  }

  /**    Test for Task::testStatusGetter()
   *
   */ 
  void testStatusGetter() {
    CPPUNIT_ASSERT(0 == t->getStatus());
  }

  /**    Test for Task::testStatusSetter(int)
   *
   */ 
  void testStatusSetter() {
    t->setStatus(2);
    CPPUNIT_ASSERT(2 == t->getStatus());
  }

  /**    Test for Task::testStatusGetter()
   *
   */ 
  void testStateGetter() {
    std::vector<State> sts;
    CPPUNIT_ASSERT(sts.size() == t->getStates().size());
  }

  /**    Test for Task::testStatusSetter(const& vector<state>)
   *
   */ 
  void testStateSetter() {
    std::vector<State> nsts;
    nsts.push_back(State("St1",Date(20150601)));
    nsts.push_back(State("St2",Date(20150602)));
    t->setStates(nsts);
    CPPUNIT_ASSERT(nsts.size() == t->getStates().size());
    CPPUNIT_ASSERT(nsts[0].getDate() == (t->getStates())[0].getDate());
    CPPUNIT_ASSERT(nsts[0].getContent() == (t->getStates())[0].getContent());
    CPPUNIT_ASSERT(nsts[1].getDate() == (t->getStates())[1].getDate());
    CPPUNIT_ASSERT(nsts[1].getContent() == (t->getStates())[1].getContent());
  }

 

  /**    Test for Task::testParaConstructor
   *
   */ 
  void testParaConstructor() {
    std::vector<State> nsts;
    nsts.push_back(State("St1",Date(20150601)));
    nsts.push_back(State("St2",Date(20150602)));
    delete t;
    t = new Task("Test",nsts,1);
    CPPUNIT_ASSERT("Test" == t->getTaskName());
    CPPUNIT_ASSERT(nsts.size() == t->getStates().size());
    CPPUNIT_ASSERT(nsts[0].getDate() == (t->getStates())[0].getDate());
    CPPUNIT_ASSERT(nsts[0].getContent() == (t->getStates())[0].getContent());
    CPPUNIT_ASSERT(nsts[1].getDate() == (t->getStates())[1].getDate());
    CPPUNIT_ASSERT(nsts[1].getContent() == (t->getStates())[1].getContent());
    CPPUNIT_ASSERT(1 == t->getStatus());
  }

  /**    Test for Task::testCopyConstructor(const Task&)
   *
   */ 
  void testCopyConstructor() {
    std::vector<State> nsts;
    nsts.push_back(State("St1",Date(20150601)));
    nsts.push_back(State("St2",Date(20150602)));
    Task tt("Test",nsts,1);
    delete t;
    t = new Task(tt);
    CPPUNIT_ASSERT("Test" == t->getTaskName());
    CPPUNIT_ASSERT(nsts.size() == t->getStates().size());
    CPPUNIT_ASSERT(nsts[0].getDate() == (t->getStates())[0].getDate());
    CPPUNIT_ASSERT(nsts[0].getContent() == (t->getStates())[0].getContent());
    CPPUNIT_ASSERT(nsts[1].getDate() == (t->getStates())[1].getDate());
    CPPUNIT_ASSERT(nsts[1].getContent() == (t->getStates())[1].getContent());
    CPPUNIT_ASSERT(1 == t->getStatus());
  }
};

#endif
