/**
 * @file   Task.h
 * @Author Bacpfsec Rick
 * @date   20150405
 * @brief  Header file of Task Class
 *
 * Task Class for actual recording of one task
 */
#ifndef _TASK_H_
#define _TASK_H_
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "Date.h"
#include "State.h"

/**
 * @brief  Task Class for actual recording of tasks
 * 
 * Task Class records several states on different dates for a single task.
 * Task Class also provides some basic operations related with a task.
 *
 */
class Task {
public:
  /**    Default constructor
   *     
   */ 
  Task();

  /**    Parameterized constructor
   *     @param s    string content for a progress
   *     @param dt   a Date object
   */ 
  Task(std::string tn, const std::vector<State>& st, bool s);

  /**    Copy constructor
   *     
   */ 
  Task(const Task& t);

  /**    Destructor
   *
   */ 
  ~Task();

  /**    Setter for states
   *     @param dt    A vector of states
   */ 
  void setStates(const std::vector<State>& sts);

  /**    Getter for states
   *     @return      A reference to vector of recorded states
   */ 
  std::vector<State>& getStates();

  /**    Setter for task name
   *     @param s    A string for task name
   */ 
  void setTaskName(std::string s);

  /**    Getter for task name
   *     @return      A string with task name
   */ 
  std::string getTaskName();

  /**    Setter for task status
   *     @param s     An integer stands for status
   */ 
  void setStatus(int f);

  /**    Getter for task status
   *     @return      An integer stands for status
   */ 
  int getStatus();

private:
  /** Storage of task name */ 
  std::string taskName;

  /** Storage of states in vector*/
  std::vector<State> states;

  /*  Storage of current task status
   *  0 : In progress
   *  1 : Finished
   *  2 : Cancelled
   *  3 : Temporately locked
   */
  int status;
};
#endif
