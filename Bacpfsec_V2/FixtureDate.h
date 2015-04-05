/**
 * @file   FixtureDate.h
 * @Author Bacpfsec Rick
 * @date   20150324
 * @brief  CppUnit Fixture setup for Date class
 *
 * FixtureDate is used in TestDate for Date Class
 */

#ifndef FIXTUREDATE_H
#define FIXTUREDATE_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Date.h"

class FixtureDate : public CppUnit::TestFixture {
 public:
  CPPUNIT_TEST_SUITE(FixtureDate);
  CPPUNIT_TEST(testGetter);
  CPPUNIT_TEST(testSetter);
  CPPUNIT_TEST(testParaConstructor);
  CPPUNIT_TEST(testCopyConstructor);
  CPPUNIT_TEST(testNextDate);
  CPPUNIT_TEST(testIsValid);
  CPPUNIT_TEST(testEquivalent);
  CPPUNIT_TEST_SUITE_END();

 private:
  Date* dt;

 public:
  void setUp() {
    dt = new Date();
  }

  void tearDown() {
    delete dt;
  }

  /**    Test for Date::getDate()
   *
   *     Default date is 20150301
   */ 
  void testGetter() {
    CPPUNIT_ASSERT(20150301 == dt->getValue());
  }

  /**    Test for Date::setDate(int d)
   *     
   */ 
  void testSetter() {
    dt->setValue(20150322);
    CPPUNIT_ASSERT(20150322 == dt->getValue());
  }

  /**    Test for Date::Date(int d)
   *     
   */ 
  void testParaConstructor() {
    delete dt;
    dt = new Date(20150427);
    CPPUNIT_ASSERT(20150427 == dt->getValue());
  }

  /**    Test for Date::Date(const Date& dt)
   *     
   */ 
  void testCopyConstructor() {
    dt->setValue(20150427);
    Date cpDate(*dt);
    CPPUNIT_ASSERT(20150427 == cpDate.getValue());
  }

  /**    Test for Date::nextDate()
   *
   *     Test case 1: 20150228->20150301
   *     Test case 2: 20160228->20160229
   *     Test case 3: 20150930->20151001
   *     Test case 4: 20151215->20151216
   */ 
  void testNextDate() {
    dt->setValue(20150228);
    dt->nextDate();
    CPPUNIT_ASSERT(20150301 == dt->getValue());
    dt->setValue(20160228);
    dt->nextDate();
    CPPUNIT_ASSERT(20160229 == dt->getValue());
    dt->setValue(20150930);
    dt->nextDate();
    CPPUNIT_ASSERT(20151001 == dt->getValue());
    dt->setValue(20151215);
    dt->nextDate();
    CPPUNIT_ASSERT(20151216 == dt->getValue());
  }

  /**    Test for Date::isValid()
   *
   *     Test case 1: 20150229(invalid)->20150301
   *     Test case 2: 20160229(valid)->20160229
   *     Test case 3: 20151930(invalid)->20150301
   */ 
  void testIsValid() {
    dt->setValue(20150229);
    CPPUNIT_ASSERT(20150301 == dt->getValue());
    dt->setValue(20160229);
    CPPUNIT_ASSERT(20160229 == dt->getValue());
    dt->setValue(20151930);
    CPPUNIT_ASSERT(20150301 == dt->getValue());
   }

  /**    Test for equivalent check
   *
   *     Test case 1: 20150201==20150201
   *     Test case 2: 20150202!=20150201
   */
  void testEquivalent() {
    Date d1(20150201), d2(20150201),  d3(20150202);
    CPPUNIT_ASSERT(d1 == d2);
    CPPUNIT_ASSERT(d2 != d3);
  }
};

#endif
