/**
 * @file   MenuSimple.h
 * @Author Bacpfsec Rick
 * @date   20150416
 * @brief  Concrete class of Menu
 *
 * MenuSimple is the first varability for Menu Interface
 */
#ifndef _MENUSIMPLE_H_
#define _MENUSIMPLE_H_
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include "Menu.h"

/**
 * @brief  Menu interface is used as the introduction to user
 * 
 * Menu interface should be inherited to a simple concrete class
 * and a detailed concrete class
 *
 */
class MenuSimple: public MenuInterface {
public:
  /** Concrete method for menu
   *
   * @param os ostream as either cout or ofstream
   */
  void welcome(std::ostream& os);

};

#endif
