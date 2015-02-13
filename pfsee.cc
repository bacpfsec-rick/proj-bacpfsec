/*
  Project name : Parallel Full Stack Engineering Executive
  Author       : Rick Liu
  Version/Date : 0.1/20140212
 */
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

struct book {
  book() {}
  book(string n, vector<state> sts, bool f) : name(n), states(sts), finish(f) {}
  string name;
  vector<state> states;
  bool finish;
};

static vector<book> books;

/*
  Function prototypes
*/
void read_books(ifstream& ifs, vector<book>& books);
void read_states(ifstream& ifs, book& bk);
void show_record(ostream& os, vector<book>& books);
void write_record(ofstream& ofs, vector<book>& books);
bool instruct();

int main() {
  cout<<"--------------------------"<<endl;
  cout<<"|                        |"<<endl;
  cout<<"|  Welcome to Pfsee 0.1  |"<<endl;
  cout<<"|                        |"<<endl;
  cout<<"--------------------------"<<endl;

  while (instruct()) {
    cout<<">>>"<<endl;
  };
  return 0;
}

bool instruct() {
  char i;
  cout<<"(~~~~~~~~~~~~~)"<<endl;
  cout<<"(Command list:)"<<endl;
  cout<<"(1-Load record)"<<endl;
  cout<<"(2-Show record)"<<endl;
  cout<<"(3-Save record)"<<endl;
  cout<<"(4-Quit       )"<<endl;
  cout<<"(~~~~~~~~~~~~~)"<<endl;
  cout<<">>> ";
  cin>>i;
  switch(i) {
  case '1':
    {
    ifstream ifs;
    string data;
    cout<<"Read data from file:";
    cin>>data;
    ifs.open(data);
    if (!ifs.is_open()) {
      cout<<"Error: No such file!";
    }
    books.clear();
    read_books(ifs,books);
    ifs.close();
    break;
    }
  case '2':
    {
    show_record(cout,books);
    break;
    }
  case '3':
    {
    ofstream ofs;
    string data;
    cout<<"Save data to file  :";
    cin>>data;
    ofs.open(data);
    write_record(ofs,books);
    ofs.close();
    break;
    }
  case '4':
    {
    return false;
    break;
    }
  default:
    return false;
  }
  return true;
}

void read_books(ifstream& ifs, vector<book>& books) {
  string s;
  if (ifs>>s) {
    book newBook;
    newBook.name = s;
    read_states(ifs,newBook);
    books.push_back(newBook);
    // recursively read next book
    read_books(ifs,books);
  }
};

void read_states(ifstream& ifs, book& bk) {
  string s;
  if (ifs>>s) {
    if ( s=="1" ) { // end of a book record
      bk.finish = 1;
    } else if ( s=="0" ) { // end of a book record
      bk.finish = 0;
    } else {
      state newState;
      int date;
      newState.content = s;
      ifs>>date;
      newState.date = date;
      bk.states.push_back(newState);
      // recursively read next state
      read_states(ifs,bk);
    }
  }
};

void show_record(ostream& os, vector<book>& books) {
  for(int i=0; i<books.size(); ++i) {
    if (books[i].finish!=1) { // print only the books in progress
      os<<"Book name: "<<books[i].name<<endl;
      os<<"Progress : ";
      for(int j=0; j<books[i].states.size(); ++j) {
	time_t t(books[i].states[j].date);
	struct tm* current_time = localtime(&t);
	os<<books[i].states[j].content<<"["<<1+current_time->tm_mon
	    <<"-"<<current_time->tm_mday<<"]   ";
      }
      os<<endl;
    }
  }
}

void write_record(ofstream& ofs, vector<book>& books) {
  for(int i=0; i<books.size(); ++i) {
    ofs<<books[i].name<<" ";
    for(int j=0; j<books[i].states.size(); ++j) {
	ofs<<books[i].states[j].content<<" "<<books[i].states[j].date<<" ";
    }
    ofs<<books[i].finish<<endl;
  }
}
