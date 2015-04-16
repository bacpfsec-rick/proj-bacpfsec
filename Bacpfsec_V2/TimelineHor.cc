/**
 * @file   TimlineHorr.cc
 * @Author Bacpfsec Rick
 * @date   20150416
 * @brief  Implementation of TimelineHor Class
 *
 * TimelineHor is concrete implementation for Timeline Interface
 */
#include "TimelineHor.h"

void TimelineHor::timeline(std::ostream& os, std::vector<Task>& ts,
		      Date s, Date e, Date st, Date en) {
  timelineHor(os,ts,s,e,st,en);
}


void TimelineHor::timelineHor(std::ostream& os, std::vector<Task>& ts,
			 Date s, Date e, Date st, Date en) {
  // print title and date
  os<<std::left<<std::setw(15)<<"Task\\Date";
  int last = (en.getValue()>e.getValue()) ? e.getValue() : en.getValue();
  Date d(s);
  for (int i=d.getValue(); i<=last; i=d.getValue()) {
    Date::printDay(os,Date(i),15);
    d.nextDate();
  }
  os<<std::endl;
  // print title and states
  for (int k=0; k<ts.size(); k++) {
    os<<std::left<<std::setw(15)<<ts[k].getTaskName();
    d = s;
    int curr = 0;
    for(int i=d.getValue(); i<=last; i=d.getValue()) {
      if (Date(i)==ts[k].getStates()[curr].getDate()) {
	os<<std::left<<std::setw(15)<<ts[k].getStates()[curr].getContent();
	curr++;
      } else {
	os<<std::setw(15)<<"";
      }
      d.nextDate();
    }
    os<<std::endl;
  }
}
