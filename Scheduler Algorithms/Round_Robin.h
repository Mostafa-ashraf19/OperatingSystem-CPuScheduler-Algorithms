#ifndef ROUND_ROBIN_H
#define ROUND_ROBIN_H

#include <iostream>
#include <string>
#define TRUE 1
#define FALSE 0
#include <vector>
#include <algorithm>

struct Process {
      int id ;
    //char id [30] ;           //   Process id
    int arrivalTime ;      //   Arrival time is the point of time at which a process enters the ready queue.
    int waitingTime ;      //   Waiting time is the amount of time spent by a process waiting in the ready queue for getting the CPU.
    int responseTime ;     //   Response time is the amount of time after which a process gets the CPU for the first time after entering the ready queue.
    int burstTime ;        //   Burst time is the amount of time required by a process for executing on CPU. (Execution time.)
    int turn_aroundTime ;  //   Turn Around time is the total amount of time spent by a process in the system.
    int completionTime ;   //   Completion time is the point of time at which a process completes its execution on the CPU and takes exit from the system.
    int isCompleted ;        //   Define if process completed or not 1 (completed) or 0 (not completed.)
    int priority ;           //   lower number means high priority.
    int remainTime;
    std::vector<int> start;
    std::vector<int> end ;

                             //   Waiting time = Turn Around time – Burst time
                             //   Response Time = Time at which process first gets the CPU – Arrival time
                             //   Turn Around time = Burst time + Waiting time  or Turn Around time = Completion time – Arrival time
};


class RoundRobin {
    std::vector<Process> p;
    typedef int quantum ;     // The period of time for which a process is allowed to run in a preemptive multitasking system is generally called the time slice or quantum.
    quantum  Q ;
    int id;
public:
    std::pair<std::vector<int>,std::vector<int>> process_start_end(int i)
    {

        return  {p[i].start , p[i].end};
    };

    std::vector<Process> getProcesses (){
        return p;
    }
    void arrayofProcess_Processing (   );
    void get_start_end (  );
    float avg_Waitting_Time (  );
    void process_Init ( );
    void roundRobin_calculate_turnaround_time( );
    void set_QuantumTime (quantum q) ;
    void roundRobin_waitingTime ( );
    RoundRobin();
void add_Process(std::string process_name, int arrivalTime ,int burstTime);
};

#endif // ROUND_ROBIN_H
