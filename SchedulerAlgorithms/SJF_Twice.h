#pragma once

#include<string>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

namespace JSF_Area {
struct process {
    string name;
    int index;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int starting_time;
    int end_time;
};
class SJF
{
private:
    vector<process>ready_queue;
    int process_index;
    int count;
    process* process_temp;
    void calc_waiting_time();
    void calc_startint_ending_time();
    void SJF_sort_according_to_arrival_time();
    void non_preemptive();
    void preemptive();
public:
    SJF();
    void set_new_process(string process_name, int process_burst_time, int process_arrival_time);
    float average_waiting_time();
    void shorted_job_first_non_preemptive();
    void shorted_job_first_preemptive();
    vector <process>return_ready_queue();
    int return_count_of_processes();

};

}
