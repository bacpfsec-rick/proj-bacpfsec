/**
 * @file   Date.h
 * @Author Bacpfsec Rick
 * @date   20150324
 * @brief  Date Class is used for State Class
 *
 */
#ifndef DATE_H
#define DATE_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

/**
 * @brief  Date Class is used for time recording
 * 
 * Date Class provides supplementary operations based on the <time> library
 *
 */
class Date {
public:
  /**    Default constructor
   *
   */ 
  Date();

  /**    Parameterized constructor
   *     @param d    value stands for a date
   */ 
  Date(int d);

  /**    Setter
   *     @param d    value stands for a date
   */ 
  void setDate(int d);

  /**    Getter
   *     @return     value of the date
   */ 
  int getDate();

  /**    Change date value to next valid date
   *
   */ 
  void nextDate();

private:
  int date;
};
#endif
