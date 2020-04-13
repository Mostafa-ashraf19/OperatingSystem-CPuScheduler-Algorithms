//
// Created by samy on ١‏/٤‏/٢٠٢٠.
// Round Robin scheduler

#ifndef CPUSCHEDULER_ROUNDROBIN_H
#define CPUSCHEDULER_ROUNDROBIN_H
#include "Process.h"

//Assume process sorted by arrival time
//This functions calculate and store average time & turnaround time for each process in process.waitingTime & process.turn_aroundTime

void roundRobin_waitingTime (Process *p , int noProcess, quantum q) {
   int  i ; //counter
 float  currentTime = p[0].arrivalTime ;
 float *remainBurstTime = (float *)malloc(sizeof(int) * noProcess);
 float *calcResponseTime = (float *)malloc(sizeof(int) * noProcess);

 float sumBurst =0 ;
        for (i = 0; i < noProcess; i++)
        {
            remainBurstTime[i] = p[i].burstTime;
            sumBurst+=p[i].burstTime;
            calcResponseTime[i] = FALSE;   //process still in ready queue

        }
  int x = 0 ;
    while (TRUE)
    {
        x=1;
        int check = TRUE;
        // all process not finished when false break the while loop

        /*  */
        for (i = 0; i < noProcess; i++) {
            if (p[i].arrivalTime <= currentTime) {
                /* if process still has burst time */
                if (remainBurstTime[i] > 0) //added  || currentTime < sumBurst
                {
                    x++;
                    // we can't break a loop as a process still has burst time

                    check = FALSE;

                    /* if process still in ready queue */
                    if (calcResponseTime[i] == FALSE) {
                        // response time = current time - arrival time
                        p[i].responseTime = currentTime /*- p[i].arrivalTime*/;
                        //std::cout << p[i].id << " res : " <<p[i].responseTime <<std::endl ;
                        calcResponseTime[i] = TRUE;
                        // process left ready queue
                    }

                    /* if Process remain time > quantum */
                    if (remainBurstTime[i] > q) {
                        // increase current time by quantum
                        currentTime += q;

                        // remain time = remain time - quantum time
                        remainBurstTime[i] -= q;

                    }
                    /*else if (remainBurstTime[i]<=q){
                        currentTime +=remainBurstTime[i];
                    }*/
                        /*else if ( p[i].arrivalTime > currentTime){
                            currentTime += p[i].arrivalTime- currentTime;

                        }*/
                        /* if process remain time < quantum time */
                    else {
                        currentTime += remainBurstTime[i];
                        // time process wait in cpu =  current time - burst time
                        p[i].waitingTime = currentTime - p[i].burstTime /*- p[i].arrivalTime*/; //i edit added arrival time
                        // burst time now = 0
                        remainBurstTime[i] = 0;
                        // i=0;

                    }
                }

            }
            /*else if(p[i].arrivalTime > currentTime)
                calcResponseTime[i]=TRUE;*/

        }
        if (x <= 1){
            currentTime++;}

        /* no process has burst time */

        if (check == TRUE)

            break; //break while loop

    }
     for (i=0 ; i<noProcess ; i++){
         if (p[i].responseTime < p[i].arrivalTime){
             p[i].responseTime = p[i].arrivalTime;}
         p[i].completionTime = p[i].arrivalTime+ p[i].waitingTime+p[i].burstTime;
         //std::cout << p[i].id << " comp : " <<p[i].completionTime <<std::endl ;
     }
    free(remainBurstTime);
    free (calcResponseTime);
    // free memory allocation



};

void roundRobin_calculate_turnaround_time(Process *p, int noProcess)
{
    int i;
    // counter

    /* calculate turnaround time for each process */
    for (i = 0; i < noProcess; i++)
        p[i].turn_aroundTime = p[i].burstTime + p[i].waitingTime /*- p[i].arrivalTime*/;

};



#endif //CPUSCHEDULER_ROUNDROBIN_H
