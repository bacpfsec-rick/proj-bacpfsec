#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

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
  bool finish;
};
static bool recordLoaded;
static int startDate;
static int endDate;
static int numOfTaskUncomplete;
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
void timeline(ostream& os, vector<task>& tasks, int start, int end);
void print_day(ostream& os, int time);
void next_day(int& today);

int main() {
  cout<<"----------------------"<<endl;
  cout<<"|  Welcome to Pfsee  |"<<endl;
  cout<<"----------------------"<<endl;
  init();
  while (instruct()) {
    cout<<">>>"<<endl;
  };
  return 0;
}

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
  cout<<"   (Command List)"<<endl<<"   ";
  cout<<(recordLoaded ? "" : "(1-Load) ");
  cout<<(recordLoaded ? "(2-List) " : "");
  cout<<(recordLoaded ? "(3-Save) " : "");
  cout<<(recordLoaded ? "(4-Time) " : "");
  cout<<(recordLoaded ? "(5-Info) " : "");
  cout<<"(8-Quit) ";
  cout<<endl<<">>> ";
  cin>>i;
  switch(i) {
  case '1':
    {
    ifstream ifs;
    ifs.open("data.pfs");
    /*
    string data;
    cout<<"   Read data from file:";
    cin>>data;
    ifs.open(data);
    if (!ifs.is_open()) {
      cout<<"   ***No such file***";
    }
    */
    tasks.clear();
    read_tasks(ifs,tasks);
    ifs.close();
    break;
    }
  case '2':
    {
    show_record(cout,tasks);
    break;
    }
  case '3':
    {
      ofstream ofs;
      /*
      string data;
      cout<<"   Save data to file  :";
      cin>>data;
      ofs.open(data);
      */
      ofs.open("data.pfs");
      write_record(ofs,tasks);
      ofs.close();
      break;
    }
  case '4':
    {
      int start,end;
      cout<<"   (Input Format)"<<endl;
      cout<<"   (YYMMDD YYMMDD) --- eg. 150101 151231"<<endl<<">>>";
      cin>>start>>end;
      timeline(cout,tasks,start,end);
      break;
    }
  case '5':
    {
      brief_report(cout,tasks);
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
    if (tasks[i].finish!=1) { // print only the tasks in progress
      os<<" Task name : "<<tasks[i].name<<endl;
      os<<" Progress  : ";
      for(int j=0; j<tasks[i].states.size(); ++j) {
	//	time_t t(tasks[i].states[j].date);
	//	struct tm* current_time = localtime(&t);
	os<<tasks[i].states[j].content<<"[";
	print_day(os,tasks[i].states[j].date);
	os<<"]\t";
      }
      os<<endl;
    }
  }
}

void print_day(ostream& os, int time) {
  os<<time/10000<<"-"<<time/100%100<<"-"<<time%100;
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

void timeline(ostream& os, vector<task>& tasks, int start, int end) {
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
    os<<"   Date\\Task\t";
    for (int i=0; i<tasks.size(); ++i) {
      os<<tasks[i].name<<"\t";
    }
    os<<endl;
    // print date
    int track[tasks.size()];
    for(int i=0; i<tasks.size(); ++i) {
      track[i]=0;
    }
    for(int i=start; i<=endDate; next_day(i)) {
      os<<"   ";
      print_day(os,i);
      os<<"\t";
      for(int j=0; j<tasks.size(); ++j) {
	if (tasks[j].states[track[j]].date==i) {
	  os<<tasks[j].states[track[j]].content;
	  ++track[j];
	}
	os<<"\t";
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
    (tasks.size()-numOfTaskUncomplete)<<endl;
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
