/**
 * @file   BfcTerminal.h
 * @Author Bacpfsec Rick
 * @date   20150406
 * @brief  Header file of BfcTerminal inherited from BfcTUI
 *
 * BfcTerminal Class used the terminal for user-interface
 */

#ifndef _BFCTERMINAL_H_
#define _BFCTERMINAL_H_
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Date.h"
#include "Task.h"
#include "BfcPrototype.h"
#include "BfcTUI.h"
#include <vector>

class BfcTerminal : public BfcTUI {
 public:
  /**    instruct to dictate instructions
   *     @return          boolean as valid instruction
   *
   *     This function based on
   *
   */
  bool instruct();

  /**    run as the runner of BfcTUI
   *
   */
  void run();
};
#endif
