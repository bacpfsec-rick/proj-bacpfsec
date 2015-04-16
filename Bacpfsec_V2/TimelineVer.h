/**
 * @file   TimelineVer.h
 * @Author Bacpfsec Rick
 * @date   20150416
 * @brief  Concrete class of Timeline
 *
 * TimelineVer stands for concrete class with vertical timeline
 */
#ifndef _TIMELINEVER_H_
#define _TIMELINEVER_H_
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Timeline.h"

/**
 * @brief  TimelineVer is concrecte class for timeline interface
 * 
 * TimelineVer illustrate timeline in vertical style
 *
 */
class TimelineVer : public TimelineInterface {
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
 /**    Private helper to build vertical timeline
   *     @param os        ostream
   *     @param ts        reference to a task vector
   *     @param s         start Date input from user
   *     @param e         end Date input from user
   *
   */
  void timelineVer(std::ostream& os, std::vector<Task>& ts, Date s, Date e, Date st, Date en);
};

#endif
