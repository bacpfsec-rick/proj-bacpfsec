/**
 * @file   Date.h
 * @Author Bacpfsec Rick
 * @date   20150324
 * @brief  Header file of Date Class
 *
 * Date Class is used for State Class
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
   *     @note Default value is 150301 (i.e. 2015/03/01)
   */ 
  Date();

  /**    Parameterized constructor
   *     @param d    Value stands for a date
   */ 
  Date(int d);

  /**    Destructor
   *
   */ 
  ~Date();

  /**    Setter
   *     @param d    Value stands for a date
   */ 
  void setDate(int d);

  /**    Getter
   *     @return     Value of the private date
   */ 
  int getDate();

  /**    Proceed date to next valid date
   *
   */ 
  void nextDate();

private:
  /** Storage of date value */ 
  int date;

  /**    Check if a date is valid
   *
   */ 
  bool isValid();
};
#endif
