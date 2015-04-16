/**
 * @file   Timeline.h
 * @Author Bacpfsec Rick
 * @date   20150416
 * @brief  Interface of Timeline
 *
 * Timeline Interface is used for timeline feature
 */
#ifndef _TIMELINE_H_
#define _TIMELINE_H_
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include "Date.h"
#include "Task.h"

/**
 * @brief  Timeline interface is used for timeline feature
 * 
 * Timeline feature performs illustration on tasks
 *
 */
class TimelineInterface {
public:
  /** Abstract method for timeline
   *
   * @param os ostream as either cout or ofstream
   * @param
   */
  virtual void timeline(std::ostream& os, std::vector<Task>& ts, 
			Date s, Date e, Date st, Date en) = 0;


};
typedef TimelineInterface* Timeline;
#endif
