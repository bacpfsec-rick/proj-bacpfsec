/**
 * @file   Setup.h
 * @Author Bacpfsec Rick
 * @date   20150416
 * @brief  Abstract factory to setup Bfc
 *
 * Setup is the abstract factory
 */
#ifndef _SETUP_H_
#define _SETUP_H_
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include "Date.h"
#include "Task.h"
#include "Timeline.h"
#include "Menu.h"

/**
 * @brief  Setup interface is the abstract factory
 * 
 * Setup factory setup features like timeline for Bfc
 *
 */
class SetupInterface {
public:
  /** Abstract setup for timeline
   *
   */
  virtual Timeline createTimeline() = 0;

  /** Abstract setup for menu
   *
   */
  virtual Menu createMenu() = 0;
};
typedef SetupInterface* Setup;
#endif
