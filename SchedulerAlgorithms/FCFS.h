#ifndef FCFS_F
#define FCFS_F

#include<iostream>
#include<utility>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>

namespace FCFS_Area {

using namespace std;
struct process {
    string name;
    int index;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int starting_time;
    int end_time;
};
class FCFS
{
private:
    vector<process>ready_queue;
    int process_index;
    int wait_time_temp;
    int count;
    process* process_temp;
public:
    FCFS();
    void set_new_process(string process_name, int process_burst_time, int process_arrival_time);
    void calc_waiting_time();


    void calc_startint_ending_time();

    float average_waiting_time();

    void fcfs_sort_according_to_arrival_time();

    void first_come_first_serve();

    vector<process> return_ready_queue();

    int return_count_of_processes();

};

}
#endif
