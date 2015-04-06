/**
 * @file   BfcPrototype.h
 * @Author Bacpfsec Rick
 * @date   20150405
 * @brief  Header file of BfcPrototype Class
 *
 * BfcPrototype Class is used as abstract base class
 */
#ifndef _BFCPROTOTYPE_H_
#define _BFCPROTOTYPE_H_
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Date.h"
#include "Task.h"
#include <vector>

/**
 * @brief  BfcPrototype Class is abstract base class
 * 
 * BfcPrototype Class serves as the abstract base class for variety
 * BacpfsecTUI and BacpfsecGUI would inherited from BfcPrototype
 */
class BfcPrototype {
 public:
  /**    Default constructor
   *     
   */ 
  BfcPrototype();

  /**    Destructor
   *
   */ 
  ~BfcPrototype();

  /**    Getter for maxTaskInProgress
   *
   */
  const int getMaxTaskInProgress();

  /**    Setter for recordLoaded
   *
   */
  void setRecordLoaded(bool rl);

  /**    Getter for recordLoaded
   *
   */
  bool getRecordLoaded();

  /**    Setter for startDate
   *
   */
  void setStartDate(const Date& sd);

  /**    Getter for startDate
   *
   */
  Date getStartDate();

  /**    Setter for endDate
   *
   */
  void setEndDate(const Date& ed);

  /**    Getter for endDate
   *
   */
  Date getEndDate();

  /**    Setter for numOfTaskUncomplete
   *
   */
  void setNumOfTaskUncomplete(int ntu);

  /**    Getter for numOfTaskUncomplete
   *
   */
  int getNumOfTaskUncomplete();

  /**    Setter for numOfTaskCancelled
   *
   */
  void setNumOfTaskCancelled(int ntc);

  /**    Getter for numOfTaskCancelled
   *
   */
  int getNumOfTaskCancelled();

  /**    Reference getter for vector tasks
   *
   */
  std::vector<Task>& getTasks();


  /**    Virtual readStates()
   *
   *     Get the record from stream and update the task and private members
   */
  virtual void readStates(std::istream& is, Task& bk);

  /**    Virtual readTasks()
   *
   *     Get the record from stream and update the tasks and private members
   */
  virtual void readTasks(std::istream& is, std::vector<Task>& ts);

 private:
  /** Const limit of tasks in progress */
  const int maxTaskInProgress = 15;

  /** Boolean indicate if record is loaded */
  bool recordLoaded;

  /** The first date of recorded readed*/
  Date startDate;

  /** The last date of recorded readed*/
  Date endDate;

  /** The number of tasks in progress */
  int numOfTaskUncomplete;

  /** The number of tasks cancelled */
  int numOfTaskCancelled;

  /** Storage of the tasks as a vector */
  std::vector<Task> tasks;

 protected:
  /** Protected initializer
   *
   * Helper to initialize all the private member
   *
   */
  void init();
};
#endif
