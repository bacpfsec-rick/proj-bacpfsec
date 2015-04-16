/**
 * @file   TimelineHor.h
 * @Author Bacpfsec Rick
 * @date   20150416
 * @brief  Concrete class of Timeline
 *
 * TimelineHor stands for concrete class with hortical timeline
 */
#ifndef _TIMELINEHOR_H_
#define _TIMELINEHOR_H_
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Timeline.h"

/**
 * @brief  TimelineHor is concrecte class for timeline interface
 * 
 * TimelineHor illustrate timeline in horizontal style
 *
 */
class TimelineHor : public TimelineInterface {
 public:
  /** Concrete method for timeline
   *
   *     @param os        ostream
   *     @param ts        reference to a task vector
   *     @param s         start Date input from user
   *     @param e         end Date input from user
   */
  void timeline(std::ostream& os, std::vector<Task>& ts, 
			Date s, Date e, Date st, Date en);

 private:
 /**    Private helper to build horizontal timeline
   *     @param os        ostream
   *     @param ts        reference to a task vector
   *     @param s         start Date input from user
   *     @param e         end Date input from user
   *
   */
  void timelineHor(std::ostream& os, std::vector<Task>& ts, Date s, Date e, Date st, Date en);
};

#endif
