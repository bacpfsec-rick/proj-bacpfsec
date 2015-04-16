/**
 * @file   BfcTUI.h
 * @Author Bacpfsec Rick
 * @date   20150405
 * @brief  Header file of BfcTUI inherited from BfcPrototype
 *
 * BfcTUI Class is used to build the text-based user interface
 */
#ifndef _BFCTUI_H_
#define _BFCTUI_H_
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Date.h"
#include "Task.h"
#include "BfcPrototype.h"
#include "Timeline.h"
#include "Setup.h"
#include "Menu.h"
#include <vector>

/**
 * @brief  BfcTUI Class is inherited from BfcPrototype
 * 
 * BfcTUI provides some interesting functions to build the text-based UI
 * This is one main variant of the Bacpfsec Project main
 *
 */
class BfcTUI : public BfcPrototype {
 public:
  /**    Constructor with factory 
   *
   */
  BfcTUI(Setup f);

  /**    Destructor
   *
   */ 
  ~BfcTUI();

  /**    showRecord to ostream
   *     @param os        ostream
   *     @param ts        reference to a task vector
   *     @param s         status integer
   *
   */
  void showRecord(std::ostream& os, std::vector<Task>& ts, int s);

  /**    writeRecord to ostream
   *     @param os        ostream
   *     @param ts        reference to a task vector
   *
   */
  void writeRecord(std::ostream& os, std::vector<Task>& ts);

  /**    briefReport to ostream
   *     @param os        ostream
   *     @param ts        reference to a task vector
   *
   */
  void briefReport(std::ostream& os, std::vector<Task>& ts);

  /**    timeline function with variant
   *     @param os        ostream
   *     @param ts        reference to a task vector
   *     @param s         start Date input from user
   *     @param e         end Date input from user
   *     @param m         boolean selector, 0:horizontal, 1:vertical
   *
   */
  void timeline(std::ostream& os, std::vector<Task>& ts, 
		Date s, Date e);

  /**    selectTask function select uncompleted task
   *     @param os        ostream
   *     @param is        istream
   *     @param ts        reference to a task vector
   *     @return          integer index for a task
   *
   */
  int selectTask(std::ostream& os, std::istream& is, std::vector<Task>& ts);


  /**    selectAction to select proper action basd on a task status
   *     @param os        ostream
   *     @param is        istream
   *     @param ts        reference to a task vector
   *
   */
  void selectAction(std::ostream& os, std::istream& is, std::vector<Task>& ts);


  /**    working to perform proper action on a task
   *     @param os        ostream
   *     @param is        istream
   *     @param t         reference to a task
   *
   */
  void working(std::ostream& os, std::istream& is, Task& t);

  /**    welcome the user
   *     @param os        ostream
   */
  void welcome(std::ostream&os);

  /**    Virtual run()
   *
   *     Implemented through inheritence
   */
  virtual void run();

 private:
  /** Private pointer to timeline interface */
  Timeline tl;

  /** Private pointer to menu interface */
  Menu menu;

  /** Private pointer to the setup factory */
  Setup factory;
};
#endif
