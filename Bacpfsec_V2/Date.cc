/**
 * @file   Date.cc
 * @Author Bacpfsec Rick
 * @date   20150324
 * @brief  Implementation of Date Class
 *
 * Date Class is used for State Class
 */
#include "Date.h"
Date::Date() {
  date = 20150301;
}

Date::Date(int d) : date(d) {

}

Date::~Date() {

}

void Date::setDate(int d) {
  date = d;
}

int Date::getDate() {
  return date;
}

void Date::nextDate() {
  int year = date/10000, mon = date/100%100, day = date%100;
  int beforeNextDate;
  switch(mon) { 
  case 1 :case 3 :case 5 :case 7 :case 8 :case 10:
    {
      if (day!=31) {
	beforeNextDate = date;
      } else {
	beforeNextDate=year*10000+(mon+1)*100+0;
      }
    break;
    }
  case 4 :case 6 :case 9 :case 11 :
    {
      if (day!=30) {
	beforeNextDate = date;
      } else {
	beforeNextDate = year*10000+(mon+1)*100+0;
      }
      break;
    }
  case 2:
    {
      if (day<28) {
	beforeNextDate = date;
      } else if (day==29) {
	beforeNextDate = year*10000+(mon+1)*100+0;
      } else {
	// Case: leap year
	if((year%400==0) || ((year%4==0)&&(year%100!=0))) { 
	  beforeNextDate = date;
	} else {
	  beforeNextDate = year*10000+(mon+1)*100+0;
	}
      }
      break;    
    }
  case 12: 
    {
      if (day!=31) {
	beforeNextDate = date;
      } else {
	beforeNextDate = (year+1)*10000+1*100+0;
      }
      break;
    }
  default:
    break;
  }
  ++beforeNextDate;
  date = beforeNextDate;
}
