#include "SJF_Twice.h"
//using namespace JSF_Area;

JSF_Area:: SJF::SJF()
{
    process_index = 0;

    count = 0;
}

void  JSF_Area :: SJF::set_new_process(string process_name, int process_burst_time, int process_arrival_time)
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

void JSF_Area:: SJF::calc_waiting_time()
{

    for (int i = 0; i < ready_queue.size(); i++)
    {
        ready_queue[i].waiting_time = ready_queue[i].starting_time - ready_queue[i].arrival_time;

    }
}

void JSF_Area:: SJF::calc_startint_ending_time()
{
    ready_queue[0].starting_time = 0;
    ready_queue[0].end_time = ready_queue[0].burst_time;
    for (int i = 1; i < ready_queue.size(); i++)
    {
        ready_queue[i].starting_time = ready_queue[i - 1].end_time;;
        ready_queue[i].end_time = ready_queue[i].starting_time + ready_queue[i].burst_time;
    }
}

float JSF_Area:: SJF::average_waiting_time()
{

    float average_wait_time = 0;
    int sum = 0;


    for (auto it : ready_queue)
    {
        sum += (it).waiting_time;
    }
    average_wait_time = (float)sum / count;
    return average_wait_time;
}

void JSF_Area:: SJF::SJF_sort_according_to_arrival_time()
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

void JSF_Area:: SJF::non_preemptive()
{
    int init = 0;
    for (int j = 0; j < ready_queue.size(); j++)
    {
        if (ready_queue[j].arrival_time != 0)
        {
            init = 1;
        }
    }
    for (int i = init; i < ready_queue.size(); i++)
    {
        for (int j = init; j < ready_queue.size() - 1; j++)
        {
            if (ready_queue[j].burst_time > ready_queue[j + 1].burst_time)

            {
                swap(ready_queue[j], ready_queue[j + 1]);
            }
        }
    }
}

void JSF_Area:: SJF::preemptive()
{
    shorted_job_first_non_preemptive();
    if (ready_queue[0].burst_time - ready_queue[1].arrival_time > ready_queue[1].burst_time)
    {
        auto it = ready_queue.begin();
        it++;
        it++;
        vector<process> insert_queue;
        insert_queue.push_back({ ready_queue[0].name,ready_queue[0].index
                                , ready_queue[1].arrival_time ,
                                 ready_queue[0].arrival_time,0 });
        insert_queue.push_back({ ready_queue[1].name,ready_queue[1].index
                                ,ready_queue[1].burst_time  ,
                                 ready_queue[1].arrival_time,0 });
        insert_queue.push_back({ ready_queue[0].name,ready_queue[0].index
                                ,ready_queue[0].burst_time - ready_queue[1].arrival_time ,
                                 ready_queue[0].arrival_time,ready_queue[1].arrival_time
                                 + ready_queue[1].burst_time });
        ready_queue[0] = insert_queue[0];
        ready_queue[1] = insert_queue[1];
        ready_queue.insert(it, insert_queue[2]);
        non_preemptive();
        ready_queue[0].waiting_time = 0;
        ready_queue[0].starting_time = 0;
        ready_queue[0].end_time = ready_queue[0].burst_time;
        for (int i = 1; i < count + 1; i++)
        {
            ready_queue[i].starting_time = ready_queue[i - 1].end_time;
            ready_queue[i].end_time = ready_queue[i].starting_time + ready_queue[i].burst_time;
            ready_queue[i].waiting_time = ready_queue[i].starting_time - ready_queue[i].arrival_time;
        }
        for (int j = 1; j < ready_queue.size(); j++)
        {
            if (ready_queue[j].name == ready_queue[0].name)
            {
                ready_queue[j].waiting_time -= ready_queue[1].arrival_time;
                break;
            }
        }
    }




}

void JSF_Area:: SJF::shorted_job_first_non_preemptive()
{
    SJF_sort_according_to_arrival_time();
    non_preemptive();
    calc_startint_ending_time();
    calc_waiting_time();

}

void JSF_Area:: SJF::shorted_job_first_preemptive()
{


    preemptive();

}

vector<JSF_Area::process> JSF_Area:: SJF::return_ready_queue()
{
    return this->ready_queue;
}

int JSF_Area:: SJF::  return_count_of_processes()
{
    return count;
}
