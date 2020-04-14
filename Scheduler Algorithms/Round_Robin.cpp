#include "Round_Robin.h"


std::pair<std::vector<int>,std::vector<int>> RoundRobin:: process_start_end(int index)
    {
        return  {p[index].start , p[index].end};
    };

std::vector<Process> RoundRobin:: getProcesses (){
        return p;
    }
void RoundRobin:: arrayofProcess_Processing (   ) {
    //intialise array of processes
    process_Init();
    //sort by arrival time
    std::sort(p.begin(),p.end(),[](Process x , Process y){
        return x.arrivalTime < y.arrivalTime;
    });
    //calculate waitting time for each process
    roundRobin_waitingTime();
    //calculate turnarround time for all processes time from a
    roundRobin_calculate_turnaround_time();
    get_start_end () ;
}
float  RoundRobin ::  avg_Waitting_Time (  ){
    float avg = 0;
    for (unsigned int i = 0; i < p.size(); ++i) {
        avg = avg + p[i].waitingTime;
    }
    return avg/ static_cast<float>(p.size());
}
void RoundRobin:: process_Init ( ){
    unsigned int i ; //counter
    for ( i = 0; i < p.size(); i++) {
        p[i].isCompleted = FALSE;
        p[i].waitingTime = 0;
        p[i].responseTime = 0;
        p[i].completionTime = 0;
    }
}
void RoundRobin :: roundRobin_calculate_turnaround_time( ){
    unsigned int i;
    // counter
    /* calculate turnaround time for each process */
    for (i = 0; i < p.size(); i++)
        p[i].turn_aroundTime = p[i].burstTime + p[i].waitingTime /*- p[i].arrivalTime*/;

}
void RoundRobin :: set_QuantumTime (quantum q){
    Q =q  ;
}
void RoundRobin ::  get_start_end (  ){
    unsigned int i;
    for (i=0 ; i < p.size(); i++){
        p[i].remainTime=p[i].burstTime;
    }
    int x = 1 ;
    int maxComp = p[0].completionTime;
    for (i=1 ; i < p.size() ; i++){
        if (p[i].completionTime > maxComp)
            maxComp = p[i].completionTime;

    }
    int currentTime = p[0].arrivalTime;
    while (true){
        x=1;
        for (i=0 ; i< p.size() ; i++){
            if (p[i].remainTime > 0 && p[i].arrivalTime <= currentTime){
                x++;
                p[i].start.push_back(currentTime);
                if (p[i].remainTime >Q){
                    p[i].end.push_back(currentTime + Q);
                    currentTime +=Q;
                    p[i].remainTime -= Q;
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

}
void RoundRobin:: roundRobin_waitingTime ( ){
    int  i ; //counter
    int  currentTime = p[0].arrivalTime ;
    int *remainBurstTime = new int[(sizeof(int) *p.size())];
    int *calcResponseTime = new int[(sizeof(int)*p.size())];

    int sumBurst =0 ;
    for (i = 0; i < p.size(); i++)
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
        for (i = 0; i < p.size(); i++) {
            if (p[i].arrivalTime <= currentTime && remainBurstTime[i] > 0) {
                /* if process still has burst time */
                x++;
                if (remainBurstTime[i] > Q) {
                    // we can't break a loop as a process still has burst time
                    // increase current time by quantum
                    currentTime += Q;
                    // remain time = remain time - quantum time
                    remainBurstTime[i] -= Q;
                    check = FALSE;
                } else {
                    currentTime += remainBurstTime[i];
                    // time process wait in cpu =  current time - burst time
                    p[i].waitingTime = currentTime - p[i].burstTime - p[i].arrivalTime; //i edit added arrival time
                    // burst time now = 0
                    remainBurstTime[i] = 0;
                }
                /* if process still in ready queue */
                if (calcResponseTime[i] == FALSE) {
                    // response time = current time - arrival time
                    p[i].responseTime = currentTime /*- p[i].arrivalTime*/;
                    //std::cout << p[i].id << " res : " <<p[i].responseTime <<std::endl ;
                    calcResponseTime[i] = TRUE;
                    // process left ready queue
                }

            }

            }
        
        if (x <= 1){
            currentTime++;}
        /* no process has burst time */
        if (check == TRUE
            break; //break while loop
    }
    for (i=0 ; i<p.size() ; i++){
        if (p[i].responseTime < p[i].arrivalTime){
            p[i].responseTime = p[i].arrivalTime;}
        p[i].completionTime = p[i].arrivalTime+ p[i].waitingTime+p[i].burstTime;
    }
    delete[] remainBurstTime;
    delete[] calcResponseTime;

}

void RoundRobin:: add_Process(std::string process_name, int arrivalTime ,int burstTime)
{
    p.push_back({id , arrivalTime , 0 , 0 ,burstTime});
    id++;
}
RoundRobin ::RoundRobin(){id=0;};






