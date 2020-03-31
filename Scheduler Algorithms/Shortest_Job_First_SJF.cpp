#include "Shortest_Job_First_SJF.h"
/* SJF NonPremtive Algorithm */
void _SJF_NonPremtive::Push_process(std::string _ProcessName,int _BurstTime) {
	Ready_Queue.push({ _ProcessName,{0,_BurstTime}});
}
void _SJF_NonPremtive::Run() {
	while (Ready_Queue.size())
	{
		dt = Ready_Queue.top();
		dt.second.wating_time = current;
		current += dt.second.Busrt_time;
		dt.second.turn_around_time = current;
		Wating_Queue.push(dt);
		v.push_back(dt);
		Ready_Queue.pop();
	}
	Wating_Queue = Ready_Queue;
}
int _SJF_NonPremtive::Sum(SJF::type t)
{
		int sum = 0;
		switch (t)
		{
		case SJF::AVWT:
			for (auto a : v)
				sum += a.second.wating_time;
			return sum;
		case SJF::AVTAT:
			for (auto a : v)
				sum += a.second.turn_around_time;
			return sum;
		default:
			return 0;
		}
	}
float  _SJF_NonPremtive::AverageWaitingTime()
{
	return (v.size()) ? static_cast<float>(Sum(SJF::AVWT)) / v.size() : 0;
}
float _SJF_NonPremtive::AverageTurnarroundTime()
{
	return (v.size()) ? static_cast<float>(Sum(SJF::AVTAT))/v.size() : 0;
}

/* SJF Premtive Algorithm */