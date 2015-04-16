/**
 * @file   MenuDetail.h
 * @Author Bacpfsec Rick
 * @date   20150416
 * @brief  Concrete class of Menu
 *
 * MenuDetail is the second varability for Menu Interface
 */
#ifndef _MENUDETAIL_H_
#define _MENUDETAIL_H_
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
class MenuDetail: public MenuInterface {
public:
  /** Concrete method for menu
   *
   * @param os ostream as either cout or ofstream
   */
  void welcome(std::ostream& os);

};

#endif
