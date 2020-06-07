#ifndef PRIORTY_
#define PRIORTY_

#include<vector>
#include<utility>
#include<string>
#include<algorithm>
using namespace std;

namespace Priorty_Area {


struct process {
    std::string name;
    int index;
    int burst_time;
    int arrival_time;
    int priority;
    int waiting_time;
    int starting_time;
    int end_time;
};
class Priority
{
private:
    std::vector<process>ready_queue;
    int process_index;
    int count;
    process* process_temp;
    void calc_waiting_time();
    void calc_starting_end_time();
    void SJF_sort_according_to_arrival_time();
public:
    Priority();
    void set_new_process(string process_name, int process_burst_time, int process_arrival_time, int process_priority);
    float average_waiting_time();
    void non_preemptive();
    void preemptive();
    std::vector<Priorty_Area::process>return_ready_queue();
    int return_count_of_processes();
};

}



#endif


