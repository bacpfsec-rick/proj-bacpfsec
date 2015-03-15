/*
  Project : Accelerated Parallel Full Stack Engineering Creator
  Author  : Rick Liu
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
using namespace std;

/*
  Define some constant value by user's preference
  Rises from 10 to 15 as Pfsee envolves into Apfsec
 */
#define maxTaskInProgress 15 

/*
  Data structure
*/
struct state{
  state() {}
  state(string c, int d) : content(c), date(d) {}
  string content;
  int date;
};

struct task {
  task() {}
  task(string n, vector<state> sts, bool f) : name(n), states(sts), finish(f) {}
  string name;
  vector<state> states;
  int finish;
};
static bool recordLoaded;
static int startDate;
static int endDate;
static int numOfTaskUncomplete;
static int numOfTaskCancelled;
static vector<task> tasks;

/*
  Function prototypes
*/
void init();
void read_tasks(ifstream& ifs, vector<task>& tasks);
void read_states(ifstream& ifs, task& bk);
void show_record(ostream& os, vector<task>& tasks);
void write_record(ofstream& ofs, vector<task>& tasks);
void brief_report(ostream& os, vector<task>& tasks);
bool instruct();
void timeline(ofstream& os, vector<task>& tasks, int start, int end);
void print_day(ostream& os, int time, int width);
void next_day(int& today);
void select_action(ostream& os, istream& is, vector<task>& tasks);
int select_task(ostream& os,istream& is, vector<task>& tasks);
void working(ostream& os, istream& is, task& task, int& redo);
/*
  main
*/
int main() {
  // set up
  srand(time(NULL));

  cout<<"----------------------"<<endl;
  cout<<"|  Welcome to Pfsee  |"<<endl;
  cout<<"----------------------"<<endl;
  // initialize
  init();
  while (instruct()) {
    cout<<">>> "<<endl;
  };
  return 0;
}

/*
  Functoin declarations
*/
void init() {
  recordLoaded = false;
  startDate = 99999999;
  endDate = 0;
  numOfTaskUncomplete = 0;
  if( !tasks.empty() ) {
    tasks.clear();
  }
}


bool instruct() {
  char i;
  // cout<<"   (Command List)"<<endl<<"   ";
  cout<<"   ";
  cout<<(recordLoaded ? "" : "(1-Load) ");
  cout<<(recordLoaded ? "(1-Rec Info) " : "");
  cout<<(recordLoaded ? "(2-List rec) " : "");
  cout<<(recordLoaded ? "(3-WORK NOW) " : "");
  cout<<(recordLoaded ? "(4-Timeline) " : "");
  cout<<(recordLoaded ? "(5-Save rec) " : "");
  cout<<"(8-Quit) "<<endl<<">>> ";
  cin>>i;
  // Menu without record
  if (!recordLoaded) {
    switch(i) {
    case '1':
      {
	ifstream ifs;
	ifs.open("data.pfs");
	tasks.clear();
	read_tasks(ifs,tasks);
	ifs.close();
	cout<<"   (Record is loaded into Pfsee)"<<endl;
	return true;
	break;
      }
      default:
	return false;
    }
  }
  // Menu with record
  switch(i) {
  case '2':
    {
      cout<<"   (List the tasks in progress)"<<endl;
	show_record(cout,tasks);
      break;
    }
  case '5':
    {
      ofstream ofs;
      ofs.open("data.pfs");
      write_record(ofs,tasks);
      ofs.close();
      cout<<"   (Record is saved)"<<endl;
      // re-initialize
      init();
      break;
    }
  case '4':
    {
      int start,end;
      cout<<"   (Input Format)"<<endl;
      cout<<"   (YYMMDD YYMMDD) --- eg. 150101 151231"<<endl<<">>> ";
      cin>>start>>end;
      cout<<"   (Timeline from "<<start<<"~"<<end<<")"<<endl;
      ofstream ofs;
      ofs.open("TIMELINE");
      timeline(ofs,tasks,start,end);
      ofs.close();
      cout<<"   (Output to TIMELINE file)"<<endl;
      break;
    }
  case '1':
    {
      cout<<"   (Brief report about records)"<<endl;
      brief_report(cout,tasks);
      break;
    }
  case '3':
    {
      cout<<"   (TIME TO PFSEE)"<<endl;
      select_action(cout,cin,tasks);
      break;
    }
  default:
    return false;
  }
  return true;
}

void read_tasks(ifstream& ifs, vector<task>& tasks) {
  string s;
  if (ifs>>s) {
    task newtask;
    newtask.name = s;
    read_states(ifs,newtask);
    tasks.push_back(newtask);
    // recursively read next task
    read_tasks(ifs,tasks);
  }
  recordLoaded = true;
};

void read_states(ifstream& ifs, task& bk) {
  string s;
  if (ifs>>s) {
    if ( s=="1" ) { // task completed
      bk.finish = 1;
    } else if ( s=="0" ) { // task in progress
      bk.finish = 0;
      ++numOfTaskUncomplete;
    } else if ( s=="2" ) {
      bk.finish = 2;
      ++numOfTaskCancelled;
    } else {
      state newState;
      int date;
      newState.content = s;
      ifs>>date;
      // set up the start date and end date
      if ( startDate > date ) {
	startDate = date;
      }
      if ( endDate < date ) {
	endDate = date;
      }
      newState.date = date;
      bk.states.push_back(newState);
      // recursively read next state
      read_states(ifs,bk);
    }
  }
};

void show_record(ostream& os, vector<task>& tasks) {
  for(int i=0; i<tasks.size(); ++i) {
    if (tasks[i].finish==0) { // print only the tasks in progress
      os<<"    Task name : "<<tasks[i].name<<endl;
      os<<"    Progress  : ";
      for(int j=0; j<tasks[i].states.size(); ++j) {
	string content = tasks[i].states[j].content; 
	os<<content<<"[";
	int date = tasks[i].states[j].date, width = 6;
	if (date/1000%10==0) { // XX0XXX
	  --width;
	}
	if (date/10%10==0) {   // XXXX0X
	  --width;
	}
	print_day(os,date,width);
	os<<left<<setw(18-content.size()-2-width)<<"]";
      }
      os<<endl;
    }
  }
}

void print_day(ostream& os, int time, int width) {
  stringstream ss;
  ss<<(time/10000)<<"-"<<(time/100%100)<<"-"<<(time%100);
  string t;
  ss>>t;
  os<<left<<setw(width)<<t;
}

void write_record(ofstream& ofs, vector<task>& tasks) {
  for(int i=0; i<tasks.size(); ++i) {
    ofs<<tasks[i].name<<" ";
    for(int j=0; j<tasks[i].states.size(); ++j) {
	ofs<<tasks[i].states[j].content<<" "<<tasks[i].states[j].date<<" ";
    }
    ofs<<tasks[i].finish<<endl;
  }
  recordLoaded = false;
}

void timeline(ofstream& os, vector<task>& tasks, int start, int end) {
  int sd_year=(startDate)/10000, ed_year=(endDate)/10000,
    s_year=start/10000, e_year=end/10000;
  int sd_mon=(startDate)/100%100, ed_mon=(endDate)/100%100,
    s_mon=start/100%100, e_mon=end/100%100;
  int sd_day=(startDate)%100, ed_day=(endDate)%100,
    s_day=start%100, e_day=end%100;
  if ((sd_year>e_year) ||
      (sd_year==e_year && sd_mon>e_mon) ||
      (sd_year==e_year && sd_mon==e_mon && sd_day>e_day) ||
      (ed_year<s_year) ||
      (ed_year==s_year && ed_mon<s_mon) ||
      (ed_year==s_year && ed_mon==s_mon && ed_day<s_day) ) {
    os<<"   ***Nothing done in given period***"<<endl;
  } else {
    // print title
    os<<left<<setw(15)<<"Date\\Task";
    for (int i=0; i<tasks.size(); ++i) {
      os<<left<<setw(15)<<tasks[i].name;
    }
    os<<endl;
    // print date
    int track[tasks.size()];
    for(int i=0; i<tasks.size(); ++i) {
      track[i]=0;
    }
    for(int i=start; i<=endDate; next_day(i)) {
      print_day(os,i,15);
      for(int j=0; j<tasks.size(); ++j) {
	if (tasks[j].states[tasks[j].states.size()-1].date<i) {
	  os<<setw(15)<<"";
	  continue;
	}
	while( tasks[j].states[track[j]].date<i) { // trace to partial start
	  ++track[j];
	}
	if (tasks[j].states[track[j]].date==i) {
	  os<<left<<setw(15)<<tasks[j].states[track[j]].content;
	  ++track[j];
	} else {
	  os<<setw(15)<<"";
	}
      }
      os<<endl;
    }
  }
}

void brief_report(ostream& os, vector<task>& tasks) {
  os<<"   First date of the recording : "<<startDate<<endl;
  os<<"   Last date of updating data  : "<<endDate<<endl;
  os<<"   Number of tasks in progress : "<<numOfTaskUncomplete<<endl;
  os<<"   Number of tasks completed   : "<<
    (tasks.size()-numOfTaskUncomplete-numOfTaskCancelled)<<endl;
  os<<"   Number of tasks cancalled   : "<<numOfTaskCancelled<<endl;
}

void next_day(int& today) {
  int year = today/10000, mon = today/100%100, day=today%100;
  int result;
  // init the result to imaginary date before true result
  switch(mon) { 
  case 1 :case 3 :case 5 :case 7 :case 8 :case 10:
    {
      if (day!=31) {
	result = today;
      } else {
	result=year*10000+(mon+1)*100+0;
      }
    break;
    }
  case 4 :case 6 :case 9 :case 11 :
    {
      if (day!=30) {
	result = today;
      } else {
	result=year*10000+(mon+1)*100+0;
      }
      break;
    }
  case 2:
    {
      if (day<28) {
	result = today;
      } else if (day==29) {
	result=year*10000+(mon+1)*100+0;
      } else {
	if(year%4!=0 || (year%4==0&&year%400!=0)) { // ! lunar year
	  result=year*10000+(mon+1)*100+0;
	} else {
	  result = today;
	}
      }
      break;    
    }
  case 12: 
    {
      if (day!=31) {
	result = today;
      } else {
	result=(year+1)*10000+1*100+0;
      }
      break;
    }
  default:
    break;
  }
  ++result;
  today = result;
}

void select_action(ostream& os, istream& is, vector<task>& tasks) {
  os<<"   (0-Back) "<<
    ((numOfTaskUncomplete == 0) ? "" : "(1-Continue uncompleted work) ")<<
    ((numOfTaskUncomplete < maxTaskInProgress) ? 
     "(2-Start new work)" : "")<<endl;
  int choice;
  os<<">>> ";
  is>>choice;
  if (choice==0) {
    return;
  } else if (choice==1) {
    if (numOfTaskUncomplete == 0) {
      os<<"   ***Invalid choice***"<<endl;
      select_action(os,is,tasks);
    } else {
      os<<"   (Select an work)"<<endl;
      int choice = select_task(os,is,tasks);
      os<<"   (Work on "<<tasks[choice].name<<")"<<endl;
      int redo=0;
      working(os,is,tasks[choice],redo);
    }
  } else if (choice==2) {
    if (numOfTaskUncomplete < maxTaskInProgress) {
      task newTask;
      os<<"   (Name Format)"<<endl;
      os<<"   (Less than 10 char) --- eg. Sample_task1"<<endl<<">>> ";
      string name;
      is>>name;
      newTask.name = name;
      newTask.finish = 0;
      tasks.push_back(newTask);
      ++numOfTaskUncomplete;
      os<<"   (Work on "<<newTask.name<<")"<<endl;
      int redo=0;
      working(os,is,tasks[tasks.size()-1],redo);
    } else {
      os<<"   ***Reach the parallel limit***"<<endl;
      select_action(os,is,tasks); 
    }
  } else {
    os<<"   ***Invalid choice***"<<endl;
    select_action(os,is,tasks);
  }
}

int select_task(ostream& os, istream& is, vector<task>& tasks) {
  os<<"   (0-Random)";
  for(int i=0; i<tasks.size(); ++i) {
    if(tasks[i].finish==0) {
      os<<" ("<<i+1<<"-"<<tasks[i].name<<")";
    }
  }
  os<<endl<<">>> ";
  int choice;
  is>>choice;
  if (choice==0) {
    do {
      choice = rand()%tasks.size();
    } while (tasks[choice].finish!=0);
    return choice;
  } else if (choice> tasks.size() || tasks[choice-1].finish!=0) {
    os<<"   ***Invalid choice***"<<endl;
    select_task(os,is,tasks);
  }
  return choice-1;
}

void working(ostream& os, istream& is, task& task, int& redo) {
  os<<"   (0-Back) (1-Finish it) (2-Cancel it) (3-Update a new progress)"
    <<((redo>0) ? " (4-Redo an update) " : "")<<endl<<">>> ";
  int choice;
  is>>choice;
  if (choice==0) {
    os<<"   (Nothing happened)"<<endl;
    return;
  } else if (choice==1) {
    state finishState;
    finishState.content = "FINISH";
    time_t t;
    time(&t);
    struct tm* today = localtime(&t);
    int date;
    date = (1900+today->tm_year)%100*10000
      +(1+today->tm_mon)*100+today->tm_mday;
    next_day(date); // FINISH is marked at the next day
    finishState.date = date;
    task.states.push_back(finishState);
    task.finish = 1;
    --numOfTaskUncomplete;
    os<<"   (Record updated)"<<endl;
  } else if (choice==2) {
    state cancelState;
    cancelState.content = "CANCEL";
    time_t t;
    time(&t);
    struct tm* today = localtime(&t);
    int date;
    date = (1900+today->tm_year)%100*10000
      +(1+today->tm_mon)*100+today->tm_mday;
    next_day(date); // FINISH is marked at the next day
    cancelState.date = date;
    task.states.push_back(cancelState);
    task.finish = 2;
    --numOfTaskUncomplete;
    ++numOfTaskCancelled;
    os<<"   (Record updated)"<<endl;
  } else if (choice==3) {
    os<<"   (Progress Format)"<<endl;
    os<<"   (Detail in 20 chars / Date is auto recorded) "<<
      "--- eg. Chap2 "<<endl<<">>> ";
    string content;
    is>>content;
    state newState;
    newState.content = content;
    time_t t;
    time(&t);
    struct tm* today = localtime(&t);
    int date;
    date = (1900+today->tm_year)%100*10000
      +(1+today->tm_mon)*100+today->tm_mday;
    newState.date = date;
    task.states.push_back(newState);
    os<<"   (Record updated)"<<endl;
    working(os,is,task,redo);
  } else if (choice==4) {
    if (redo>0) {
      task.states.pop_back();
      --redo;
    } else {
      os<<"   ***Invalid choice***"<<endl;
      working(os,is,task,redo);
    }
  } else {
    os<<"   ***Invalid choice***"<<endl;
    working(os,is,task,redo);
  }
}
