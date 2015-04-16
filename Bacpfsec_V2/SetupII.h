/**
 * @file   SetupII.h
 * @Author Bacpfsec Rick
 * @date   20150416
 * @brief  Concrete factory to setup Bfc
 *
 * SetupII is the second varibility as concrete factory
 */
#ifndef _SETUPII_H_
#define _SETUPII_H_
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include "Date.h"
#include "Task.h"
#include "TimelineHor.h"
#include "Setup.h"
/**
 * @brief  SetupII is a concrete factory
 * 
 * SetupII is a concrete factory to setup timeline with horizontal style
 *
 */
class SetupII: public SetupInterface {
public:
  /** Abstract setup for timeline
   *
   */
  Timeline createTimeline() {
    return new TimelineHor;
  }


};

#endif
