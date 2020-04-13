//
// Created by samy on ١٣‏/٤‏/٢٠٢٠.
//

#ifndef CPUSCHEDULER_INTERFACE_H
#define CPUSCHEDULER_INTERFACE_H

#include "Process.h"
#include "Sort_by_arriveTime.h"
#include "roundRobin.h"
#include <vector>
 #include <bits/stdc++.h>
#include <utility>
using namespace std;
//print vector
void print(std::vector<float> const &input)
{
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}

//get start and ends of each process
void get_start_end (Process p[] , int noProcess , float q){
    int i;
    for (i=0 ; i < noProcess ; i++){
        p[i].remainTime=p[i].burstTime;
    }
    int x = 1 ;
    float maxComp = p[0].completionTime;
    for (i=1 ; i < noProcess ; i++){
        if (p[i].completionTime > maxComp)
            maxComp = p[i].completionTime;

    }

    float currentTime = p[0].arrivalTime /*p[0].responseTime*/;
    while (true){
        x=1;
        for (i=0 ; i< noProcess ; i++){
            if (p[i].remainTime > 0 && p[i].arrivalTime <= currentTime){
                x++;
                p[i].start.push_back(currentTime);
                if (p[i].remainTime >q){
                    p[i].end.push_back(currentTime + q);
                    currentTime +=q;
                    p[i].remainTime -= q;
                }
                else {
                    p[i].end.push_back(currentTime + p[i].remainTime);
                    currentTime += p[i].remainTime;
                    p[i].remainTime = 0;
                }

            }

        }
        if (x <= 1){
            currentTime++;}
        if (currentTime >= maxComp)
            break;
    }
    for (i=0 ; i < noProcess ; i++){
        cout << "Start " <<p[i].id <<" :" ,
                print(p[i].start);
        cout <<endl;

        cout << "end " <<p[i].id <<" :" ,
                print(p[i].end);
        cout <<endl;
        //cout << maxComp;
    }
};


void arrayofProcess_Processing (Process *p , int noProcess, quantum q) {
    //intialise array of processes
    process_Init(p,noProcess);
    //sort by arrival time
    merge_sort_by_arrive_time(p,0,noProcess-1);
    //calculate waitting time for each process
    roundRobin_waitingTime(p,noProcess,q);
    //calculate turnarround time for all processes time from a
    roundRobin_calculate_turnaround_time(p,noProcess);

    get_start_end (p , noProcess , q);

};

float avg_Waitting_Time (Process *p , int noProcess  ){
    float avg = 0;
    for (int i = 0; i < noProcess; ++i) {
        avg = avg + p[i].waitingTime;

    }
    return avg/noProcess;
};

pair < vector <float >, vector <float> > process_start_end(Process p )
{
     pair <vector <float> , vector <float>> pair1;
     pair1.first = p.start;
     pair1.second = p.end ;
    return  pair1;
};






#endif //CPUSCHEDULER_INTERFACE_H
