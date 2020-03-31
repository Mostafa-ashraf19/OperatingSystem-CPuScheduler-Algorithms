#ifndef OBJECT_
#define OBJECT_
#include<iostream>
#include<queue>
#include<vector>
 
struct object
{
	int Arrival_time,
		Busrt_time,
		Reminaing_time,
		wating_time,
		turn_around_time;
	friend std::ostream& operator<< (std::ostream& out, const object& o) {
		out << o.Arrival_time
			<< " " << o.Busrt_time
			<< " " << o.Reminaing_time
			<< " " << o.wating_time
			<< " " << o.turn_around_time;
		return out;
	}
};
using def_Temp = std::pair<std::string, object>;

//class declation
//{
//protected:
//	std::priority_queue<def_Temp,
//		std::vector<def_Temp>, SJF::smll_BRT>Ready_Queue;
//	std::priority_queue<def_Temp,
//		std::vector<def_Temp>, SJF::smll_BRT>Wating_Queue;
//	int current;
//	std::vector<def_Temp>v;
//	def_Temp dt;
//};
#endif // !OBJECT_
