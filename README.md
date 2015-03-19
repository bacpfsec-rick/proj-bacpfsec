Project     : 
	    Bacpsec
     (Balanced Accelerated Creative Parallel Stack Engineering Conquerer)

Description :
	    Back to August, 2014, an idea of making a personal multi-project 
	    management software flash into my mind.
	    Not until I saw the concept	of FSE(full stack engineer) 
	    did I started the actual coding of Pfsee.
	    With some casual time, the Pfsee1.0 is now released.
	    The TUI is simple, but the idea behind it is attractive:
	    Based on the knowledge of FSE and sub-consciousness,
	    the most efficient way for multi-project management is to treat
	    your brain as CPU, let the projects come across on the bus,
	    then solve them by using DIVIDE AND CONQUER!
Version     :
v0.1	    150212	Design basic data structure of the Pfsee	
	    ADD		static vector<task> tasks;
	    		read_tasks(ifstream& ifs, vector<task>& tasks);
			read_states(ifstream& ifs, task& bk);
			show_record(ostream& os, vector<task>& tasks);
			write_record(ofstream& ofs, vector<task>& tasks);
			instruct();
v0.2	    150214~15	Improve the recording mechanism
	    ADD		#define maxTaskInProgress 5
	    		static bool recordLoaded;
			static int startDate;
			static int endDate;
			static int numOfTaskUncomplete;
			init();
			brief_report(ostream& os, vector<task>& tasks);
			print_day(ostream& os, int time);
		       	next_day(int& today);
			timeline(ofstream& os, vector<task>& tasks,
					     int start, int end);
	    MODIFY	everything in v0.1
v0.3	    150215~16	Finish the task execution functions
	    ADD		select_action(ostream& os, istream& is, 
	    				     vector<task>& tasks);
			select_task(ostream& os,istream& is, 
					     vector<task>& tasks);
			working(ostream& os, istream& is, 
					     task& task, int& redo);
	    MODIFY      everything in v0.2
V1.0	    150216	Public the practical program at GitHub
	    PUBLISH	pfsee.cc
	    		Makefile
			data.pfs
V1.1        150217	Polish the TIMELINE and List Rec with <iomanip>
	    REWORK	print_day(ostream& os, int time,int width);
	    MODIFY	show_record(ostream& os, vector<task>& tasks);
			timeline(ofstream& os, vector<task>& tasks,
					     int start, int end);
V1.2	    150311      Add option of cancelling task and debug for select_task
	    ADD		static int numOfTaskCancelled;
	    MODIFY	read_states(ifstream& ifs, task& bk);
			working(ostream& os, istream& is, 
					     task& task, int& redo);
			brief_report(ostream& os, vector<task>& tasks);
			select_task(ostream& os,istream& is, 
					     vector<task>& tasks);
V1.2.1	    150314      Improve the record of FINISH or CANCEL by marking
	    MODIFY	working(ostream& os, istream& is, 
					     task& task, int& redo);
            RENAME      Pfsee -> Apfsec
	    		Accelerated Parallel Full Stack Engineering Creator
V1.2.2      150316	Debug and rename the program
	    DEBUG	timeline(ofstream& os, vector<task>& tasks,
					     int start, int end);

	    RENAME	Apfsec -> Bacpfsec
	    		Balanced Accelerated Creative Parallel
1			Full Stack Engineering Conqueror
V1.2.3      150316      Slight modification
V1.3	    ***		Implement the data encryption