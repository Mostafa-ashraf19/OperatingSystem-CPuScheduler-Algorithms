/*

operating systems
project 1: processes scheduling
algorthim 4
made by : mohamed obada

*/

#ifndef PRIORTY_TWICE
#define PRIORTY_TWICE
#include<iostream>
#include<string>

namespace PriortyTwice {

using namespace std;
struct process {

	string process_name;
	int running_time;
	int waiting_time;
	int arrived_time;
	int priority;
	int index;

	process* next;
};
class process_queue {             //ready queue
private:
	process* head;    // the front of ready queue
public:
	process_queue();
	void add_process_parameter(string data, int running, int arriving, int priority_num, int index_number);
	friend class Priorty_Twice;
};
class Priorty_Twice
{
private:
	int count = 0;
	process_queue processes;
	float total_average;
	int index_num = 0;
	process* current_return = processes.head;
	int x = 0;
public:
	void set_new_process(string name, int run, int arrive, int prio_num);
	void calc_waiting_time();
	float average_fun();
	void sort();// function to sort processes according to the priority
	void non_premptive();
	void premptive();
	void is_burst_equal_zero();
	process* return_value_to_mostafa();
	void non_premptive_method();
	void premptive_method();
};
}
#endif //  PRIORTY_TWICE
