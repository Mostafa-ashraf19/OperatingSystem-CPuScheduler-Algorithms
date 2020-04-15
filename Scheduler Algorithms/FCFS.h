#ifndef FCFS_H_
#define FCFS_H_
#include<iostream>
#include<string>
using namespace std;
struct process {

	string process_name;
	int running_time;
	int waiting_time;
	int arrived_time;

	int index;
	process* next;
};
class process_queue {
private:
	process* head;    // the front of ready queue
public:
	process_queue();
	void add_process_parameter(string data, int running, int arriving, int index_number);
	friend class FCFS;

};
class FCFS {
private:
	int count = 0;
	process_queue processes;
	float total_average;
	int index_num = 0;
	process* current_return = processes.head;
	int x = 0;
public:

	void set_new_process(string name, int run, int arrive);
	void calc_waiting_time();
	float average_fun();
	void sort();
    void is_equal();
	//void return_values();
	process* return_value_to_mostafa();
	void is_burst_equal_zero();
	void fcfs_method();
};

#endif // FCFS_H_
/*int main()
{
	FCFS fcfs;
	string name;     int run;         int arrive = 0;
	while (1)
	{
		cin >> name >> run >> arrive;

		fcfs.set_new_process(name, run, arrive);
		fcfs.fcfs_method();
		fcfs.return_value_to_mostafa();// this function return values return poiner
		//arrive++;


	}

}*/
