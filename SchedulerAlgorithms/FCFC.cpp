#include "FCFS.h"

FCFS_Area:: FCFS::FCFS()
{
    process_index = 0;
    wait_time_temp = 0;
    count = 0;
}

void FCFS_Area:: FCFS::set_new_process(string process_name, int process_burst_time, int process_arrival_time)
{

    process_index++;
    count++;

    process_temp = new process;
    process_temp->index = process_index;
    process_temp->name = process_name;
    process_temp->burst_time = process_burst_time;
    process_temp->arrival_time = process_arrival_time;

    ready_queue.push_back(*process_temp);


    delete process_temp;
}

void FCFS_Area::FCFS::calc_waiting_time()
{
    wait_time_temp = 0;
    for (int i = 0; i < ready_queue.size(); i++)
    {
        ready_queue[i].waiting_time = wait_time_temp - ready_queue[i].arrival_time;
        wait_time_temp += ready_queue[i].burst_time;
    }
}

void FCFS_Area::FCFS::calc_startint_ending_time()
{
    for (int i = 0; i < ready_queue.size(); i++)
    {
        ready_queue[i].starting_time = ready_queue[i].waiting_time;
        ready_queue[i].end_time = ready_queue[i].waiting_time + ready_queue[i].burst_time;
    }
}

float FCFS_Area::FCFS::average_waiting_time()
{

    float average_wait_time = 0;
    int sum = 0;


    for (auto it : ready_queue)
    {
        sum += (it).waiting_time-(it).arrival_time;
    }
    average_wait_time = (float)sum / count;
    return average_wait_time;
}

void FCFS_Area::FCFS::fcfs_sort_according_to_arrival_time()
{
    for (int i = 0; i < ready_queue.size(); i++)
    {
        for (int j = 0; j < ready_queue.size() - 1; j++)
        {
            if (ready_queue[j].arrival_time > ready_queue[j + 1].arrival_time)

            {
                swap(ready_queue[j], ready_queue[j + 1]);
            }
        }
    }
}

void FCFS_Area::FCFS::first_come_first_serve()
{
    fcfs_sort_according_to_arrival_time();
    calc_waiting_time();
    calc_startint_ending_time();
}

std::vector<FCFS_Area::process> FCFS_Area:: FCFS:: return_ready_queue()
{
    return  this->ready_queue;
}

int FCFS_Area::FCFS::return_count_of_processes()
{
    return count;
}
