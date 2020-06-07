#ifndef SHORTEST_JOB_FIRST_STF_H_
#define SHORTEST_JOB_FIRST_STF_H_
#include"Object.h"

namespace SJF {
	struct smll_ART
	{
		bool operator()(def_Temp x, def_Temp y)
		{
			return x.second.Arrival_time > y.second.Arrival_time;
		}
	};
	struct smll_BRT
	{
		bool operator()(def_Temp x, def_Temp y)
		{
			return x.second.Busrt_time > y.second.Busrt_time;
		}
	};
	struct smll_Ky
	{
		bool operator()(def_Temp x, def_Temp y)
		{
			return x.first > y.first;
		}
	};
	enum type { AVWT, AVTAT };
}
class _SJF_NonPremtive 
{
protected:
	std::priority_queue<def_Temp,
		std::vector<def_Temp>, SJF::smll_BRT>Ready_Queue;
	std::priority_queue<def_Temp,
		std::vector<def_Temp>, SJF::smll_BRT>Wating_Queue;
	int current;
	std::vector<def_Temp>v;
	def_Temp dt;
	int Sum(SJF::type t);
public:
	_SJF_NonPremtive() : current(0) {};
	void Push_process(std::string _ProcessName,
						int _BurstTime);
	void Run();
	float AverageWaitingTime();
	
	float AverageTurnarroundTime();

	auto begin() {
		return v;
	}
};

#endif // ! SHORTEST_JOB_FIRST_STF_H_