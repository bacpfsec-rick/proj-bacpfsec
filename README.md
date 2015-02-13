Project     : Pfsee (Parallel Full Stack Engineering Executive)
Description :
Version     :
v0.1	    150212	add	
	    		static vector<task> tasks;
	    		void read_tasks(ifstream& ifs, vector<task>& tasks);
			void read_states(ifstream& ifs, task& bk);
			void show_record(ostream& os, vector<task>& tasks);
			void write_record(ofstream& ofs, vector<task>& tasks);
			bool instruct();
v0.2	    150214~15	add
	    		static bool recordLoaded;
			static int startDate;
			static int endDate;
			static int numOfTaskUncomplete;
			void init();
			brief_report(ostream& os, vector<task>& tasks);
			print_day(ostream& os, int time);
		       	next_day(int& today);
			modify
			everything in v0.1
v0.3	    150215