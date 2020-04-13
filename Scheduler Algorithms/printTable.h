//
// Created by samy on ١١‏/٤‏/٢٠٢٠.
//
#include <stdio.h>
#ifndef CPUSCHEDULER_PRINTTABLE_H
#define CPUSCHEDULER_PRINTTABLE_H

#include "Process.h"

void printTable(Process p[], int noProcess)
{
    int i;


    puts("\t+-----+------------+-------------+----------+-------------+-----------------+--------------+-----------------+");
    puts("\t| PID | Burst Time | Arrive Time | Priority | Completion Time |  Response Time  | Waiting Time | Turnaround Time |");
    puts("\t+-----+------------+-------------+----------+-------------+-----------------+--------------+-----------------+");


    for (i = 0; i < noProcess; i++)
    {
        printf("\t| %d |     %3f    |     %3f     |    %3f   |     %3f     |      %3f       |      %3f     |        %3f      |\n",
               p[i].id, p[i].burstTime, p[i].arrivalTime, p[i].priority, p[i].completionTime, p[i].responseTime, p[i].waitingTime, p[i].turn_aroundTime);

        puts("\t+-----+------------+-------------+----------+-------------+-----------------+--------------+-----------------+");
    }

    puts("\n");
};

#endif //CPUSCHEDULER_PRINTTABLE_H
