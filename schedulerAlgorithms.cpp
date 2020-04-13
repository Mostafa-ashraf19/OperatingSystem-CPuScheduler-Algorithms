#include "schedulerAlgorithms.h"
#include<algorithm>
#include<QDebug>
Algorithms::Algorithms()
{
    type = FCFS;
       current = 0;
}

int Algorithms::val(scheduler_type t)
{
    switch (t)
    {
    case FCFS:
        while(Process.size())
        {
            Time_res.push_back(current);
            current += Process.front().second;
            Process.pop();
        }
        if (Time_res.size() == 0) return  0;
        return static_cast<int>(accumulate(Time_res.begin(), Time_res.end(),0))
                /static_cast<int>((Time_res.size()));

    default:
        break;
    }
    return  0;
}

void Algorithms::push(std::string processname, int bursttime)
{
    Process.push({processname,bursttime});
}

void Algorithms::pop()
{
    Process.pop();
    Time_res.pop_back();
}
