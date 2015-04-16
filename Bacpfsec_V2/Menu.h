/**
 * @file   Menu.h
 * @Author Bacpfsec Rick
 * @date   20150416
 * @brief  Interface of Menu
 *
 * Menu Interface is used as the introduction for user
 */
#ifndef _MENU_H_
#define _MENU_H_
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

/**
 * @brief  Menu interface is used as the introduction to user
 * 
 * Menu interface should be inherited to a simple concrete class
 * and a detailed concrete class
 *
 */
class MenuInterface {
public:
  /** Abstract method for menu
   *
   * @param os ostream as either cout or ofstream
   * @param
   */
  virtual void welcome(std::ostream& os) = 0;

};
typedef MenuInterface* Menu;
#endif
