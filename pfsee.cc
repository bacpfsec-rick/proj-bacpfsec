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
bool instruct();
void timeline(ostream& os, vector<task>& tasks, int start, int end);
void print_day(ostream& os, int time);

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
  startDate = 1<31;
  endDate = 0;
  numOfTaskUncomplete = 0;
  if( !tasks.empty() ) {
    tasks.clear();
  }
}


bool instruct() {
  char i;
  cout<<"   (Command list)"<<endl<<"   ";
  cout<<(recordLoaded ? "" : "(1-Load) ");
  cout<<(recordLoaded ? "(2-List) " : "");
  cout<<(recordLoaded ? "(3-Save) " : "");
  cout<<(recordLoaded ? "(4-Time) " : "");
  cout<<"(8-Quit) ";
  cout<<endl<<">>> ";
  cin>>i;
  switch(i) {
  case '1':
    {
    ifstream ifs;
    string data;
    cout<<"   Read data from file:";
    cin>>data;
    ifs.open(data);
    if (!ifs.is_open()) {
      cout<<"   ***No such file***";
    }
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
      string data;
      cout<<"   Save data to file  :";
      cin>>data;
      ofs.open(data);
      write_record(ofs,tasks);
      ofs.close();
      break;
    }
  case '4':
    {
      int start,end;
      cout<<"   (Input Format)"<<endl;
      cout<<"   (YYYYMMDD YYYYMMDD) --- eg. 20150101 20151231"<<endl<<">>>";
      cin>>start>>end;
      timeline(cout,tasks,start,end);
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
  time_t st(startDate),s(0), et(endDate), e(0);
  struct tm* cst = localtime(&st);
  struct tm* cs = localtime(&s);
  cs->tm_year = start/10000-1900;
  cs->tm_mon = start/100%100-1;
  cs->tm_mday = start%100;
  struct tm* cet = localtime(&et);
  struct tm* ce = localtime(&e);
  ce->tm_year = end/10000-1900;
  ce->tm_mon = end/100%100-1;
  ce->tm_mday = end%100;
  if ((cst->tm_year>ce->tm_year) ||
      (cst->tm_year==ce->tm_year && cst->tm_mon>ce->tm_mon) ||
      (cst->tm_year==ce->tm_year && cst->tm_mon==ce->tm_mon 
       && cst->tm_mday>ce->tm_mday) ||
      (cet->tm_year<cs->tm_year) ||
      (cet->tm_year==cs->tm_year && cet->tm_mon<cs->tm_mon) ||
      (cet->tm_year==cs->tm_year && cet->tm_mon==cs->tm_mon 
       && cet->tm_mday<cs->tm_mday) ) {
    os<<"   ***Nothing done in given period***"<<endl;
  } else {

  }
}
