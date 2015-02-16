Project     : Pfsee (Parallel Full Stack Engineering Executive)
Description :
Version     :
v0.1	    150212	Design basic data structure of the Pfsee	
	    ADD		static vector<task> tasks;
	    		void read_tasks(ifstream& ifs, vector<task>& tasks);
			void read_states(ifstream& ifs, task& bk);
			void show_record(ostream& os, vector<task>& tasks);
			void write_record(ofstream& ofs, vector<task>& tasks);
			bool instruct();
v0.2	    150214~15	Improve the recording mechanism
	    ADD		static bool recordLoaded;
			static int startDate;
			static int endDate;
			static int numOfTaskUncomplete;
			void init();
			brief_report(ostream& os, vector<task>& tasks);
			print_day(ostream& os, int time);
		       	next_day(int& today);
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
V1.1	    ***		Implement the data encryption