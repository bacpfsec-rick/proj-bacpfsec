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
#include "Setup.h"
#include "TimelineHor.h"
#include "MenuSimple.h"

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
  
  Menu createMenu() {
    return new MenuSimple;
  }
};

#endif
