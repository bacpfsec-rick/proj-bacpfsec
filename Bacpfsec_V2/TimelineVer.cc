/**
 * @file   TimlineVer.cc
 * @Author Bacpfsec Rick
 * @date   20150416
 * @brief  Implementation of TimelineVer Class
 *
 * TimelineVer is concrete implementation for Timeline Interface
 */
#include "TimelineVer.h"

void TimelineVer::timeline(std::ostream& os, std::vector<Task>& ts,
		      Date s, Date e, Date st, Date en) {
  timelineVer(os,ts,s,e,st,en);
}


void TimelineVer::timelineVer(std::ostream& os, std::vector<Task>& ts,
			 Date s, Date e, Date st, Date en) {
  // print title
  os<<std::left<<std::setw(15)<<"Date\\Task";
  for (int i=0; i<ts.size(); ++i) {
    os<<std::left<<std::setw(15)<<ts[i].getTaskName();
  }
  os<<std::endl;
  // keep track
  int track[ts.size()];
  for(int i=0; i<ts.size(); ++i) {
    track[i]=0;
  }
  // print states
  int last = (en.getValue()>e.getValue()) ? e.getValue() : en.getValue();
  for(int i=s.getValue(); i<=last; i=s.getValue()) {
    Date::printDay(os,Date(i),15);
    for(int j=0; j<ts.size(); ++j) {
      if (ts[j].getStates()[ts[j].getStates().size()-1].getDate().getValue()<i) {
	os<<std::setw(15)<<"";
	continue;
      }
      while( ts[j].getStates()[track[j]].getDate().getValue()<i) {
	++track[j];
      }
      if (ts[j].getStates()[track[j]].getDate().getValue()==i) {
	os<<std::left<<std::setw(15)<<
	  ts[j].getStates()[track[j]].getContent();
	++track[j];
      } else {
	os<<std::setw(15)<<"";
      }
    }
    os<<std::endl;
    s.nextDate();
  }
}
