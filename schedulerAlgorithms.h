#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include<queue>
#include<string>
#include<algorithm>
#include<numeric>
enum scheduler_type{ FCFS , SJF};

class Algorithms
{
    std::queue<std::pair<std::string,int>>Process;
    std::vector<int>Time_res;
    int type;
    int current;
public:
    Algorithms();

    int val(scheduler_type t);
    void push(std::string,int);
    void pop();

};

#endif // ALGORITHMS_H
