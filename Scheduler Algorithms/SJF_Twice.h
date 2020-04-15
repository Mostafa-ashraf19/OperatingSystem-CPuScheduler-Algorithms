#ifndef SJF_TWICE_
#define SJF_TWICE_

#include<string>
using namespace std;
namespace SJF_TWICE {

struct process {

	string process_name;
	int running_time;
	int waiting_time;
	int arrived_time;
	int index;
	process* next;
};
struct none_process {
	int start;
	int finsh;

};

class process_queue {             //ready queue
private:
	process* head;    // the front of ready queue
public:
	process_queue();
	void add_process_parameter(string data, int running, int arriving, int index_number);
	friend class SJF_Twice;


};
class SJF_Twice
{
private:
	int count = 0;

	process_queue processes;
	float total_average;
	int index_num = 0;
	//process* current_return = processes.head;
	int x = 0;
	process* head_current;
public:
	SJF_Twice();
	void set_new_process(string name, int run, int arrive);
	void calc_waiting_time();
	float average_fun();
	void sort();// function to sort processes according to the running time
	void non_premptive();
	void premptive();
	void is_burst_equal_zero();
	process* return_value_to_mostafa();
	void premptive_method();
	void non_premptive_method();

};
}
#endif // SJF_TWICE_
