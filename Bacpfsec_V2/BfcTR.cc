/**
 * @file   BfcTR.cc
 * @Author Bacpfsec Rick
 * @date   20150406
 * @brief  Executable for BacpFesC in terminal
 *
 * This is the program to run the terminal version of BacpFesC project
 */
#include "BfcPrototype.h"
#include "BfcTUI.h"
#include "BfcTerminal.h"

int main() {
  BfcPrototype* bfc;
  bfc = new BfcTerminal();
  bfc->run();
  delete bfc;
}; 

