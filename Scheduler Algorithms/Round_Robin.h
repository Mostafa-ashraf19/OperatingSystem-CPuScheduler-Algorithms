#pragma once
#ifndef ROUND_ROBIN_ 
#define ROUND_ROBIN_ 
#include"Object.h"
class Round_Robin 
{
protected:
	std::queue<def_Temp>Ready_Queue;
	std::queue<def_Temp>Wating_Queue;
	int current;
	std::vector<def_Temp>v;
	def_Temp dt;
	int QuantumTime;
	int sum()
	{
		std::queue<def_Temp>temp = Ready_Queue;
		int sum = 0;
		while (temp.size())
		{
			sum += temp.front().second.Busrt_time;
			temp.pop();
		}
		return sum;
	}
public:
	Round_Robin() = default;
	explicit Round_Robin(int Quantumtime) :QuantumTime(Quantumtime) ,current(0){};
	void Push_process(std::string _ProcessName,
		int _BurstTime);
	void Run();
};

#endif // !ROUND_ROBIN_ 



