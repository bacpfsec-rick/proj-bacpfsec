/**
 * @file   MenuSimple.cc
 * @Author Bacpfsec Rick
 * @date   20150416
 * @brief  Implementation of MenuSimple Class
 *
 * MenuSimple is literally a simple hello to the user
 */
#include "MenuSimple.h"

void MenuSimple::welcome(std::ostream& os) {
  os<<"-------------------------"<<std::endl;
  os<<"|  Welcome to BacpFseC  |"<<std::endl;
  os<<"-------------------------"<<std::endl;
}
