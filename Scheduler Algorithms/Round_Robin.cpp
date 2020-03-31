#include "Round_Robin.h"

void Round_Robin::Push_process(std::string _ProcessName,
	int _BurstTime)
{
	Ready_Queue.push({ _ProcessName,{0,_BurstTime} });
}
void Round_Robin::Run()
{
	int sum = Round_Robin::sum();
	def_Temp temp;
	int rem = 0;
	int starttime = 0;
	int arrivaltime = 0;
	std::cout << "fisrt sum= " << sum << '\n';
	while (sum)
	{
		temp = Ready_Queue.front();
		if (temp.second.Busrt_time < QuantumTime)
		{
			sum = sum - temp.second.Busrt_time;
			temp.second.Busrt_time = 0;
			//temp.second.wating_time += Ready_Queue.front().second.Busrt_time;
			
			std::cout << "sum: " << sum << "burst time " << temp.first << "= " << temp.second.Busrt_time << std::endl;
			Ready_Queue.pop();
			continue;
		}
		else
		{
			temp.second.Busrt_time = temp.second.Busrt_time - QuantumTime;
			sum = sum - QuantumTime;
			//temp.second.Busrt_time += 
			std::cout << "sum: " << sum << "burst time " << temp.first << "= " << temp.second.Busrt_time << std::endl;
		}
		Ready_Queue.pop();
		Ready_Queue.push(temp);
	}
}