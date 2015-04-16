/**
 * @file   SetupI.h
 * @Author Bacpfsec Rick
 * @date   20150416
 * @brief  Concrete factory to setup Bfc
 *
 * SetupI is the first varibility as concrete factory
 */
#ifndef _SETUPI_H_
#define _SETUPI_H_
#include "TimelineVer.h"
#include "Setup.h"
/**
 * @brief  SetupI is a concrete factory
 * 
 * SetupI is a concrete factory to setup timeline with vertical style
 *
 */
class SetupI: public SetupInterface {
public:
  /** Abstract setup for timeline
   *
   */
  Timeline createTimeline() {
    return new TimelineVer;
  }


};

#endif
