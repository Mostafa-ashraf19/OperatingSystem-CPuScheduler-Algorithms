//
// Created by samy on ١‏/٤‏/٢٠٢٠.
//

#ifndef CPUSCHEDULER_PROCESS_H
#define CPUSCHEDULER_PROCESS_H
#define TRUE 1
#define FALSE 0
#include <bits/stdc++.h>
#include <vector>
using namespace std;
#include "stdio.h"

typedef float quantum ;     // The period of time for which a process is allowed to run in a preemptive multitasking system is generally called the time slice or quantum.

struct Process {
      int id ;
    //char id [30] ;           //   Process id
    float arrivalTime ;      //   Arrival time is the point of time at which a process enters the ready queue.
    float waitingTime ;      //   Waiting time is the amount of time spent by a process waiting in the ready queue for getting the CPU.
    float responseTime ;     //   Response time is the amount of time after which a process gets the CPU for the first time after entering the ready queue.
    float burstTime ;        //   Burst time is the amount of time required by a process for executing on CPU. (Execution time.)
    float turn_aroundTime ;  //   Turn Around time is the total amount of time spent by a process in the system.
    float completionTime ;   //   Completion time is the point of time at which a process completes its execution on the CPU and takes exit from the system.
    int isCompleted ;        //   Define if process completed or not 1 (completed) or 0 (not completed.)
    int priority ;           //   lower number means high priority.
    float remainTime;
    vector <float> start;
    vector <float> end ;

                             //   Waiting time = Turn Around time – Burst time
                             //   Response Time = Time at which process first gets the CPU – Arrival time
                             //   Turn Around time = Burst time + Waiting time  or Turn Around time = Completion time – Arrival time

                             //for more details : https://www.gatevidyalay.com/turn-around-time-response-time-waiting-time/
};


//
void process_Init (Process p[] , int noProcess)  {

int i ; //counter
    for (i = 0; i < noProcess; i++) {
        p[i].isCompleted = FALSE;
        p[i].waitingTime = 0;
        p[i].responseTime = 0;
        p[i].completionTime = 0;

    }

};


#endif //CPUSCHEDULER_PROCESS_H

