/**
 * @file   BfcTerminal.cc
 * @Author Bacpfsec Rick
 * @date   20150406
 * @brief  Implementation for BfcTerminal Class
 *
 * BfcTerminal Class used the terminal for user-interface
 */
#include "BfcTerminal.h"
#include <sstream>
#include <time.h>
#include <fstream>

BfcTerminal::BfcTerminal(Setup f) : BfcTUI(f) {

}

bool BfcTerminal::instruct() {
  std::vector<Task>& ref = getTasks();
  std::cout<<"   ";
  std::cout<<(getRecordLoaded() ? "" : "(1-Load) ");
  std::cout<<(getRecordLoaded() ? "(1-Rec Info) " : "");
  std::cout<<(getRecordLoaded() ? "(2-List rec) " : "");
  std::cout<<(getRecordLoaded() ? "(3-WORK NOW) " : "");
  std::cout<<(getRecordLoaded() ? "(4-Timeline) " : "");
  std::cout<<(getRecordLoaded() ? "(5-Save rec) " : "");
  std::cout<<"(8-Quit) "<<std::endl;
  char i;
  while ( std::cout<<">>> " && !(std::cin>>i)) {
    std::cin.clear();
    std::cin.ignore(1024, '\n');
    std::cout<<"   ***Invalid input, please re-enter***"<<std::endl;
  }
  // Menu when record unloaded
  if (!getRecordLoaded()) {
    switch(i) {
    case '1':
      {
	std::ifstream ifs;
	ifs.open("DATA.bfc");
	ref.clear();
	readTasks(ifs,ref);
	ifs.close();
	std::cout<<"   (Record is loaded into Bacpfsec)"<<std::endl;
	return true;
	break;
      }
      default:
	return false;
    }
  }
  // Menu with record loaded
  switch(i) {
  case '2':
    {
      int selector;
      std::cout<<"   (Select the desired task status)"<<std::endl;
      std::cout<<"   (0 : List the uncompleted tasks)"<<std::endl;
      std::cout<<"   (1 : List the finished tasks)"<<std::endl;
      std::cout<<"   (2 : List the cancelled tasks)"<<std::endl;
      std::cout<<">>> ";
      std::cin>>selector;
      std::cout<<"   (Record Listing)"<<std::endl;
      showRecord(std::cout,ref,selector);
      break;
    }
  case '5':
    {
      std::ofstream ofs;
      ofs.open("DATA.bfc");
      writeRecord(ofs,ref);
      ofs.close();
      std::cout<<"   (Record is saved)"<<std::endl;
      init();
      break;
    }
  case '4':
    {
      int start,end;
      std::cout<<"   (Input 2 valid date)"<<std::endl;
      std::cout<<"   (YYYYMMDD YYYYMMDD)"<<std::endl;
      std::cout<<"   (20150101 20151231 for eg.)"<<std::endl;
      while ( std::cout<<std::endl<<">>> " && 
	      !(std::cin>>start && std::cin>>end)) {
	std::cin.clear();
	std::cin.ignore(1024, '\n');
	std::cout<<"   ***Invalid input, please re-enter***"<<std::endl;
      }
      std::cout<<"   (Timeline from "<<start<<"~"<<end<<")"<<std::endl;
      bool destination;
      std::cout<<"   (Select output destination)"<<std::endl;
      std::cout<<"   (0: Right here at terminal)"<<std::endl;
      std::cout<<"   (1: local TIMELINE.tl file)"<<std::endl;
      while ( std::cout<<">>> " && !(std::cin>>destination)) {
	std::cin.clear();
	std::cin.ignore(1024, '\n');
	std::cout<<"   ***Invalid input, please re-enter***"<<std::endl;
      }
      if (destination==0) {
	timeline(std::cout,ref,Date(start),Date(end));//,style);
      } else {
	std::ofstream ofs;
	ofs.open("TIMELINE.tl");
	timeline(ofs,ref,Date(start),Date(end));//,style);
	ofs.close();
	std::cout<<"   (TIMELINE.tl updated)"<<std::endl;
      }
      break;
    }
  case '1':
    {
      std::cout<<"   (Brief report about records)"<<std::endl;
      briefReport(std::cout,ref);
      break;
    }
  case '3':
    {
      std::cout<<"   (BacpFesC STARTS)"<<std::endl;
      selectAction(std::cout,std::cin,ref);
      break;
    }
  default:
    return false;
  }
  return true;
}

void BfcTerminal::run() {
  srand(time(NULL));
  welcome(std::cout);
  while (instruct()) {
    std::cout<<">>> "<<std::endl;
  }
}
