/**
 * @file   BfcTRI.cc
 * @Author Bacpfsec Rick
 * @date   20150406
 * @brief  Executable for BacpFesC in terminal with SetupI
 *
 * This is the program to run the terminal version of BacpFesC project
 * with the SetupI factory
 */
#include "BfcPrototype.h"
#include "BfcTUI.h"
#include "BfcTerminal.h"
#include "SetupII.h"

int main() {
  BfcTerminal bfc(new SetupII);
  bfc.run();

  return 0;
}; 

