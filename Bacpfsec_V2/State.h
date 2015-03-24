/**
 * @file   State.h
 * @Author Bacpfsec Rick
 * @date   20150324
 * @brief  Header file of State Class
 *
 * State Class is used for Task Class
 */
#ifndef STATE_H
#define STAET_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Date.h"

/**
 * @brief  State Class is used to record a progress of a task
 * 
 * State Class records both progress detail and performing date.
 * State Class also provides some basic operations related with a progress.
 *
 */
class State {
public:
  /**    Default constructor
   *     
   */ 
  State();

  /**    Parameterized constructor
   *     @param s    string content for a progress
   *     @param dt   a Date object
   */ 
  State(std::string s, const Date& dt);

  /**    Copy constructor
   *     
   */ 
  State(const State& st);

  /**    Destructor
   *
   */ 
  ~State();

  /**    Setter for date
   *     @param dt    A Date object
   */ 
  void setDate(const Date& dt);

  /**    Getter for date
   *     @return      A Date object with details from private date
   */ 
  Date getDate();

  /**    Setter for content
   *     @param s    A string for progress detail
   */ 
  void setContent(std::string s);

  /**    Getter for content
   *     @return      A string with details from private content
   */ 
  std::string getContent();

  /**    Merge another content to this state
   *     @param s    A string for another progress detail
   */ 
  void merge(std::string s);


private:
  /** Storage of progress detail */ 
  std::string content;

  /** Storage of date value */ 
  Date date;
};
#endif
