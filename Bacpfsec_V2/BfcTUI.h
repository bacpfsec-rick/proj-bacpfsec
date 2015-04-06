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
  /**    Default constructor
   *     
   */ 
  BfcTUI();
  
  /**    Destructor
   *
   */ 
  ~BfcTUI();

  /**    Print given date with given width
   *
   */
  void printDay(std::ostream& os, Date d, int width);

private:
};
#endif
