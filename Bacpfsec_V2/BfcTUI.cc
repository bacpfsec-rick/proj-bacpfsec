/**
 * @file   BfcTUI.cc
 * @Author Bacpfsec Rick
 * @date   20150405
 * @brief  Implementation for BfcTUI Class
 *
 * BfcTUI is the TUI version of program
 */
#include "BfcTUI.h"
#include <sstream>
#include <iomanip>
#include <time.h>
#include <fstream>
BfcTUI::BfcTUI() {
  BfcPrototype::init();
}

BfcTUI::~BfcTUI() {
  BfcPrototype::init();
}

void BfcTUI::printDay(std::ostream& os, Date d, int width) {
  std::stringstream ss;
  int time = d.getValue();
  ss<<(time/10000)<<"-"<<(time/100%100)<<"-"<<(time%100);
  std::string t;
  ss>>t;
  os<<std::left<<std::setw(width)<<t;
}

void BfcTUI::showRecord(std::ostream& os, std::vector<Task>& ts, int s) {
  for(int i=0; i<ts.size(); ++i) {
    if (ts[i].getStatus()==s) { 
      os<<"    Task name : "<<ts[i].getTaskName()<<std::endl;
      os<<"     Details  : ";
      for(int j=0; j<ts[i].getStates().size(); ++j) {
	os<<"[";
	std::string content = ts[i].getStates()[j].getContent();
	os<<content<<"]";
	Date date = ts[i].getStates()[j].getDate();
	int  width = 8;
	if (date.getValue()/1000%10==0) { // XX0XXX
	  --width;
	}
	if (date.getValue()/10%10==0) {   // XXXX0X
	  --width;
	}
	printDay(os,date,width);
	os<<std::left<<std::setw(18-content.size()-2-width);
      }
      os<<std::endl;
    }
  }
}

void BfcTUI::writeRecord(std::ostream& os, std::vector<Task>& ts) {
  for(int i=0; i<ts.size(); ++i) {
    os<<ts[i].getTaskName()<<" ";
    for(int j=0; j<ts[i].getStates().size(); ++j) {
      os<<"[ "<<ts[i].getStates()[j].getContent()<<" ] "
	 <<ts[i].getStates()[j].getDate().getValue()<<" ";
    }
    os<<ts[i].getStatus()<<std::endl;
  }
  setRecordLoaded(false);
}

void BfcTUI::briefReport(std::ostream& os, std::vector<Task>& ts) {
  os<<"   First date of the recording : "<<
    getStartDate().getValue()<<std::endl;
  os<<"   Last date of data updating  : "<<
    getEndDate().getValue()<<std::endl;
  os<<"   Number of tasks in progress : "<<
    getNumOfTaskUncomplete()<<std::endl;
  os<<"   Number of tasks completed   : "<<
    (ts.size()-getNumOfTaskUncomplete()-getNumOfTaskCancelled())<<std::endl;
  os<<"   Number of tasks cancalled   : "<<
    getNumOfTaskCancelled()<<std::endl;
}

void BfcTUI::timeline(std::ostream& os, std::vector<Task>& ts,
		      Date s, Date e, bool m) {
  int sdValue = getStartDate().getValue(),
    edValue = getEndDate().getValue(),
    sValue = s.getValue(), eValue = e.getValue();
  int sdYear=sdValue/10000, edYear=edValue/10000,
    sYear=sValue/10000, eYear=eValue/10000;
  int sdMon=sdValue/100%100, edMon=edValue/100%100,
    sMon=sValue/100%100, eMon=eValue/100%100;
  int sdDay=sdValue%100, edDay=edValue%100,
    sDay=sValue%100, eDay=eValue%100;
  if ((sdYear>eYear) ||
      (sdYear==eYear && sdMon>eMon) ||
      (sdYear==eYear && sdMon==eMon && sdDay>eDay) ||
      (edYear<sYear) ||
      (edYear==sYear && edMon<sMon) ||
      (edYear==sYear && edMon==sMon && edDay<sDay) ) {
    os<<"   ***Nothing done in given period***"<<std::endl;
  } else {
    if (m) {
      timelineVer(os,ts,s,e);
    } else {
      timelineHor(os,ts,s,e);
    }
  }

}

void BfcTUI::timelineVer(std::ostream& os, std::vector<Task>& ts,
			 Date s, Date e) {
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
  int last = (getEndDate().getValue()>e.getValue()) ? e.getValue() : getEndDate().getValue();
  for(int i=s.getValue(); i<=last; i=s.getValue()) {
    printDay(os,Date(i),15);
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

void BfcTUI::timelineHor(std::ostream& os, std::vector<Task>& ts,
			 Date s, Date e) {
  // print title and date
  os<<std::left<<std::setw(15)<<"Task\\Date";
  int last = (getEndDate().getValue()>e.getValue()) ? e.getValue() : getEndDate().getValue();
  Date d(s);
  for (int i=d.getValue(); i<=last; i=d.getValue()) {
    printDay(os,Date(i),15);
    d.nextDate();
  }
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

    
int BfcTUI::selectTask(std::ostream& os, std::istream& is,
		       std::vector<Task>& ts) {
 os<<"   (0-Random)";
  for(int i=0; i<ts.size(); ++i) {
    if(ts[i].getStatus()==0) {
      os<<" ("<<i+1<<"-"<<ts[i].getTaskName()<<")";
    }
  }
  os<<std::endl<<">>> ";
  int choice;
  is>>choice;
  if (choice==0) {
    do {
      choice = rand()%ts.size();
    } while (ts[choice].getStatus()!=0);
    return choice;
  } else if (choice> ts.size() || ts[choice-1].getStatus()!=0) {
    os<<"   ***Invalid choice***"<<std::endl;
    selectTask(os,is,ts);
  }
  return choice-1;
}


void BfcTUI::selectAction(std::ostream& os, std::istream& is,
			  std::vector<Task>& ts) {
  os<<"   (0-Back) "<<
    ((getNumOfTaskUncomplete() == 0) ? "" : "(1-Continue uncompleted work) ")<<
    ((getNumOfTaskUncomplete() < getMaxTaskInProgress()) ? 
     "(2-Start new work)" : "")<<std::endl;
  int choice;
  os<<">>> ";
  is>>choice;
  if (choice==0) {
    return;
  } else if (choice==1) {
    if (getNumOfTaskUncomplete() == 0) {
      os<<"   ***Invalid choice***"<<std::endl;
      selectAction(os,is,ts);
    } else {
      os<<"   (Select an work)"<<std::endl;
      int choice = selectTask(os,is,ts);
      os<<"   (Work on "<<ts[choice].getTaskName()<<")"<<std::endl;
      working(os,is,ts[choice]);
    }
  } else if (choice==2) {
    if (getNumOfTaskUncomplete() < getMaxTaskInProgress()) {
      Task newTask;
      os<<"   (Name Format)"<<std::endl;
      os<<"   (Less than 10 char) --- eg. Sample_task1"<<std::endl<<">>> ";
      std::string name;
      is>>name;
      newTask.setTaskName(name);
      newTask.setStatus(0);
      ts.push_back(newTask);
      setNumOfTaskUncomplete(getNumOfTaskUncomplete()+1);
      os<<"   (Work on "<<newTask.getTaskName()<<")"<<std::endl;
      working(os,is,ts[ts.size()-1]);
    } else {
      os<<"   ***Reach the parallel limit***"<<std::endl;
      selectAction(os,is,ts); 
    }
  } else {
    os<<"   ***Invalid choice***"<<std::endl;
    selectAction(os,is,ts);
  }
}

void BfcTUI::working(std::ostream& os, std::istream& is, Task& t) {
  os<<"   (0-Back) (1-Finish it) (2-Cancel it) (3-Update a new progress)"
    <<std::endl<<">>> ";
  int choice;
  is>>choice;
  std::time_t tm;
  time(&tm);
  struct tm* today = localtime(&tm);
  if (choice==0) {
    os<<"   (Nothing happened)"<<std::endl;
    return;
  } else if (choice==1) {
    State finishState;
    finishState.setContent("FINISH");
    Date d((1900+today->tm_year)%100*10000
	      +(1+today->tm_mon)*100+today->tm_mday);
    d.nextDate(); // FINISH is marked at the next day
    finishState.setDate(d);
    t.getStates().push_back(finishState);
    t.setStatus(1);
    setNumOfTaskUncomplete(getNumOfTaskUncomplete()-1);
    os<<"   (Record updated)"<<std::endl;
  } else if (choice==2) {
    State cancelState;
    cancelState.setContent("CANCEL");
    Date d((1900+today->tm_year)%100*10000
	   +(1+today->tm_mon)*100+today->tm_mday);
    d.nextDate(); // FINISH is marked at the next day
    cancelState.setDate(d);
    t.getStates().push_back(cancelState);
    t.setStatus(2);
    setNumOfTaskUncomplete(getNumOfTaskUncomplete()-1);
    setNumOfTaskCancelled(getNumOfTaskCancelled()+1);
    os<<"   (Record updated)"<<std::endl;
  } else if (choice==3) {
    bool merge;
    os<<"   (Record for today already exists)"<<std::endl;
    os<<"   (Type 1 to merge the progress)"<<std::endl;
    os<<"   (Type 0 to overwrite the progress)"<<std::endl;
    if (merge==0) {
      t.getStates().pop_back();
    }
    os<<"   (Progress Format)"<<std::endl;
    os<<"   (Detail in 20 chars / Date is auto recorded) "<<
      "--- eg. Chap2 "<<std::endl<<">>> ";
    std::string content;
    is>>content;
    State newState;
    newState.setContent(content);
    Date d((1900+today->tm_year)%100*10000
	   +(1+today->tm_mon)*100+today->tm_mday);
    newState.setDate(d);
    if (merge==0) {
      t.getStates().push_back(newState);
    } else {
      t.getStates()[t.getStates().size()-1].merge(newState);
    }
    os<<"   (Record updated but not saved yet)"<<std::endl;
    working(os,is,t);
  } else {
    os<<"   ***Invalid choice***"<<std::endl;
    working(os,is,t);
  }
}

void BfcTUI::run() {

}
