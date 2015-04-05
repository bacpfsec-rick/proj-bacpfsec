/**
 * @file   FixtureState.h
 * @Author Bacpfsec Rick
 * @date   20150324
 * @brief  CppUnit Fixture setup for State class
 *
 * FixtureSate is used in TestSate for State Class
 */

#ifndef FIXTURESTATE_H
#define FIXTURESTATE_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include "State.h"

class FixtureState : public CppUnit::TestFixture {
 public:
  CPPUNIT_TEST_SUITE(FixtureState);
  CPPUNIT_TEST(testDateGetter);
  CPPUNIT_TEST(testDateSetter);
  CPPUNIT_TEST(testContentGetter);
  CPPUNIT_TEST(testContentSetter);
  CPPUNIT_TEST(testParaConstructor);
  CPPUNIT_TEST(testCopyConstructor);
  CPPUNIT_TEST(testContentMerge);
  CPPUNIT_TEST_SUITE_END();

 private:
  State* st;

 public:
  void setUp() {
    st = new State();
  }

  void tearDown() {
    delete st;
  }

  /**    Test for Sate::setDate(const Date& dt)
   *     
   */ 
  void testDateSetter() {
    st->setDate(Date(20150322));
    CPPUNIT_ASSERT(20150322 == (st->getDate()).getValue());
  }

  /**    Test for State::getDate()
   *
   */ 
  void testDateGetter() {
    CPPUNIT_ASSERT(20150301 == (st->getDate()).getValue());
  }

   /**    Test for State::setContent(std::string s)
   *     
   */ 
  void testContentSetter() {
    st->setContent("Test content 1");
    CPPUNIT_ASSERT("Test content 1" == st->getContent());
  }

  /**    Test for State::getContent()
   *
   */ 
  void testContentGetter() {
    st->setContent("Test content 2");
    CPPUNIT_ASSERT("Test content 2" == st->getContent());
  }

  /**    Test for State::State(std::string s, const Date& dt)
   *
   */ 
  void testParaConstructor() {
    delete st;
    st = new State("Test content 3",Date(20111111));
    CPPUNIT_ASSERT(20111111 == (st->getDate()).getValue());
    CPPUNIT_ASSERT("Test content 3" == st->getContent());
  }

  /**    Test for State::State(const State& st)
   *
   */ 
  void testCopyConstructor() {
    delete st;
    st = new State(State("Test content 4",Date(20221122)));
    CPPUNIT_ASSERT("Test content 4" == st->getContent());
    CPPUNIT_ASSERT(20221122 == (st->getDate()).getValue());
  }

  /**    Test for State::merge(std::string s)
   *
   */ 
  void testContentMerge() {
    st->setContent("Part 1");
    st->merge("Part 2");
    CPPUNIT_ASSERT("Part 1 + Part 2" == st->getContent());
  }
};

#endif
