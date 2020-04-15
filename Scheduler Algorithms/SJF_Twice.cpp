#include "SJF_Twice.h"
SJF_TWICE:: SJF_Twice::SJF_Twice()
{
	head_current = processes.head;
}

void SJF_TWICE:: SJF_Twice::set_new_process(string name, int run, int arrive)
{
	count++;
	index_num++;
	processes.add_process_parameter(name, run, arrive, index_num);
	//premptive();
}

void SJF_TWICE:: SJF_Twice::calc_waiting_time()
{
	processes.head->waiting_time = 0;
	process* current = processes.head->next;
	int wait_time_temp = processes.head->running_time;
	while (current != NULL)
	{
		current->waiting_time = wait_time_temp;
		wait_time_temp += current->running_time;
		current = current->next;
	}

}

float SJF_TWICE:: SJF_Twice::average_fun()
{
	int sum = 0;
    process* current = processes.head/*->next*/;
	while (current != NULL)
	{
        sum += current->waiting_time - current->arrived_time;
		current = current->next;
	}
    total_average = static_cast<float>(sum)/count;
    return  total_average;
}

void SJF_TWICE:: SJF_Twice::sort()
{
	process* current = processes.head;
	int num = 0;
	while (num < count)
	{
		while (current->next != NULL)
		{
			if (current->running_time > (current->next->running_time))
			{
				process temp; //temporary process
				temp.process_name = current->process_name;
				temp.index = current->index;
				temp.running_time = current->running_time;
				temp.arrived_time = current->arrived_time;
				/////////////////////////////////////////////
				current->process_name = current->next->process_name;
				current->index = current->next->index;
				current->running_time = current->next->running_time;
				current->arrived_time = current->next->arrived_time;
				////////////////////////////////////////////
				current->next->process_name = temp.process_name;
				current->next->index = temp.index;
				current->next->running_time = temp.running_time;
				current->next->arrived_time = temp.arrived_time;
				///////////////////////////////////////////

			}
			current = current->next;
		}
		current = processes.head;
		num++;
	}
}

void SJF_TWICE:: SJF_Twice::non_premptive()
{

	if (count == 1 || count == 2) return;
    int flagcount=0;
    for(auto a=processes.head;a != nullptr;a=a->next)
    {
            if(a->arrived_time == 0)
                flagcount++;
    }
    if(flagcount == count)
    {
        sort();
        return;
    }
	int current_time = 0;
	process* current = processes.head;
	if (processes.head != NULL && processes.head->next != NULL)
	{
		while (current->next != NULL)
		{
			current = current->next;
		}
        if ((current->arrived_time) < (processes.head->running_time))
		{
			if (((processes.head->running_time) /*- (current->arrived_time)*/) >= (current->running_time))
			{
				process* current_temp = processes.head;
				while (current_temp->next->next != NULL)
				{
					current_temp = current_temp->next;
				}

				current->next = processes.head->next;
				processes.head->next = current;
				current_temp->next = NULL;
				{
					process* temporary = processes.head->next;
					if (temporary->next != NULL)
					{
						while (temporary->next != NULL)
						{
							if ((temporary->running_time) > (temporary->next->running_time))
							{
								process temp_data; //temporary process
								temp_data.process_name = temporary->process_name;
								temp_data.index = temporary->index;
								temp_data.running_time = temporary->running_time;
								temp_data.arrived_time = temporary->arrived_time;
								/////////////////////////////////////////////
								temporary->process_name = temporary->next->process_name;
								temporary->index = temporary->next->index;
								temporary->running_time = temporary->next->running_time;
								temporary->arrived_time = temporary->next->arrived_time;
								////////////////////////////////////////////
								temporary->next->process_name = temp_data.process_name;
								temporary->next->index = temp_data.index;
								temporary->next->running_time = temp_data.running_time;
								temporary->next->arrived_time = temp_data.arrived_time;
								///////////////////////////////////////////
							}
							temporary = temporary->next;
						}
					}


				}
			}
			else
			{
				sort();
			}
		}
		else
		{
			int current_time = 0;
			process* current_moving = processes.head;
			do
			{
				current_time += current_moving->running_time;
				current_moving = current_moving->next;
				current_time += current_moving->running_time;
			} while ((current->arrived_time > current_time) && (current_moving->next != NULL));

			if (((current_moving->running_time) /*- (current->arrived_time)*/) >= (current->running_time))
			{
				process* current_temp = current_moving;
				while (current_temp->next->next != NULL)
				{
					current_temp = current_temp->next;
				}

				current->next = current_moving->next;
				current_moving->next = current;
				current_temp->next = NULL;
				{
					process* temporary = current_moving->next;
					if (temporary->next != NULL)
					{
						while (temporary->next != NULL)
						{
							if ((temporary->running_time) > (temporary->next->running_time))
							{
								process temp_data; //temporary process
								temp_data.process_name = temporary->process_name;
								temp_data.index = temporary->index;
								temp_data.running_time = temporary->running_time;
								temp_data.arrived_time = temporary->arrived_time;
								/////////////////////////////////////////////
								temporary->process_name = temporary->next->process_name;
								temporary->index = temporary->next->index;
								temporary->running_time = temporary->next->running_time;
								temporary->arrived_time = temporary->next->arrived_time;
								////////////////////////////////////////////
								temporary->next->process_name = temp_data.process_name;
								temporary->next->index = temp_data.index;
								temporary->next->running_time = temp_data.running_time;
								temporary->next->arrived_time = temp_data.arrived_time;
								///////////////////////////////////////////
							}
							temporary = temporary->next;
						}
					}


				}
			}
			else
			{
				sort();
			}

		}
	}
	else
	{
		sort();
	}
}

void SJF_TWICE:: SJF_Twice::premptive()
{
	process* current = processes.head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	if ((processes.head != NULL) && (processes.head->next != NULL))

	{

		if (current->arrived_time <= (processes.head->running_time))
		{
			int remain_time;
			int first_running_time;
			if (((processes.head->running_time) - (current->arrived_time)) > (current->running_time))
			{
				process_queue processes_temp;
				process* current_temp = processes_temp.head;
				process* delete_front_of_ready_queue = processes.head;
				process* delete_back_of_ready_queue = current;
				/////////////////////////////
				if (current->arrived_time > processes.head->running_time)
					first_running_time = processes.head->running_time;
				else
					first_running_time = current->arrived_time;
				/////////////////////////////
				processes_temp.add_process_parameter(processes.head->process_name, first_running_time, processes.head->arrived_time, processes.head->index);
				current_temp = processes_temp.head;
				processes_temp.add_process_parameter(current->process_name, current->running_time, current->arrived_time, current->index);
				current_temp = current_temp->next;
				////////////////////////////////////////////////
				remain_time = ((processes.head->running_time) - (current->arrived_time));
				if (remain_time <= 0) { remain_time = 0; }
				///////////////////////////////////////////////
                processes_temp.add_process_parameter(processes.head->process_name, remain_time, current->arrived_time, processes.head->index);
				current_temp = current_temp->next;
				current_temp->next = processes.head->next;
				processes.head = processes_temp.head;
				delete delete_front_of_ready_queue;
				process* temp = processes.head;
				if (processes.head->next != NULL)
				{
					while (temp->next->next != NULL)
					{
						temp = temp->next;
					}
					temp->next = NULL;
				}

			}
			else
			{
				{
					process* temporary = processes.head->next;
					if (temporary->next != NULL)
					{
						while (temporary->next != NULL)
						{
							if ((temporary->running_time) > (temporary->next->running_time))
							{
								process temp_data; //temporary process
								temp_data.process_name = temporary->process_name;
								temp_data.index = temporary->index;
								temp_data.running_time = temporary->running_time;
								temp_data.arrived_time = temporary->arrived_time;
								/////////////////////////////////////////////
								temporary->process_name = temporary->next->process_name;
								temporary->index = temporary->next->index;
								temporary->running_time = temporary->next->running_time;
								temporary->arrived_time = temporary->next->arrived_time;
								////////////////////////////////////////////
								temporary->next->process_name = temp_data.process_name;
								temporary->next->index = temp_data.index;
								temporary->next->running_time = temp_data.running_time;
								temporary->next->arrived_time = temp_data.arrived_time;
								///////////////////////////////////////////
							}
							temporary = temporary->next;
						}
					}


				}
			}
		}
		else
		{
			int remain_time;
			int first_running_time;
			int current_time = 0;///////////////////////////////////////
			process* current_moving = processes.head;

			do
			{
				current_time += current_moving->running_time;
				current_moving = current_moving->next;
				current_time += current_moving->running_time;
			} while ((current->arrived_time > current_time) && (current_moving->next != NULL));
			process* follow_line = processes.head;
			while (follow_line->next->process_name != current_moving->process_name)
			{
				follow_line = follow_line->next;
			}
			if (((current_moving->running_time) - (current->arrived_time)) > (current->running_time))
			{
				process_queue processes_temp;
				process* current_temp = processes_temp.head;

				process* delete_front_of_ready_queue = current_moving;
				process* delete_back_of_ready_queue = current;
				/////////////////////////////
				if (current->arrived_time > current_moving->running_time)
					first_running_time = current_moving->running_time;
				else
					first_running_time = current->arrived_time;
				/////////////////////////////
				processes_temp.add_process_parameter(current_moving->process_name, first_running_time, current_moving->arrived_time, current_moving->index);
				current_temp = processes_temp.head;
				processes_temp.add_process_parameter(current->process_name, current->running_time, current->arrived_time, current->index);
				current_temp = current_temp->next;
				////////////////////////////////////////////////
				remain_time = ((current_moving->running_time) - (current->arrived_time));
				if (remain_time <= 0) { remain_time = 0; }
				///////////////////////////////////////////////
                processes_temp.add_process_parameter(current_moving->process_name, remain_time, current->arrived_time, current_moving->index);
				current_temp = current_temp->next;
				current_temp->next = current_moving->next;
				follow_line->next = processes_temp.head;

				process* temp = current_moving;
				if (current_moving->next != NULL)
				{
					while (temp->next->next != NULL)
					{
						temp = temp->next;
					}
					delete delete_front_of_ready_queue;
					temp->next = NULL;
				}

			}
			else
			{
				{
					process* temporary = current_moving->next;
					if (temporary->next != NULL)
					{
						while (temporary->next != NULL)
						{
							if ((temporary->running_time) > (temporary->next->running_time))
							{
								process temp_data; //temporary process
								temp_data.process_name = temporary->process_name;
								temp_data.index = temporary->index;
								temp_data.running_time = temporary->running_time;
								temp_data.arrived_time = temporary->arrived_time;
								/////////////////////////////////////////////
								temporary->process_name = temporary->next->process_name;
								temporary->index = temporary->next->index;
								temporary->running_time = temporary->next->running_time;
								temporary->arrived_time = temporary->next->arrived_time;
								////////////////////////////////////////////
								temporary->next->process_name = temp_data.process_name;
								temporary->next->index = temp_data.index;
								temporary->next->running_time = temp_data.running_time;
								temporary->next->arrived_time = temp_data.arrived_time;
								///////////////////////////////////////////
							}
							temporary = temporary->next;
						}
					}


				}
			}

		}
	}
	else
	{
		sort();
	}

}

void SJF_TWICE:: SJF_Twice::is_burst_equal_zero()
{
	process* current = processes.head;
	process* zero_burst_time;
	if ((processes.head != NULL) && (processes.head->next != NULL))

	{
		while (current->next != NULL)
		{
			if (current->next->running_time == 0)
			{
				zero_burst_time = current->next;
				current->next = current->next->next;
				delete zero_burst_time;
			}
			current = current->next;
		}
	}
}

SJF_TWICE:: process* SJF_TWICE:: SJF_Twice::return_value_to_mostafa()
{
	return processes.head;
}

void  SJF_TWICE:: SJF_Twice::premptive_method()
{
	premptive();
	calc_waiting_time();
	average_fun();
	is_burst_equal_zero();

	//print();
}

void SJF_TWICE:: SJF_Twice::non_premptive_method()
{


    non_premptive();
	calc_waiting_time();
	average_fun();
//	is_burst_equal_zero();

}

SJF_TWICE:: process_queue::process_queue()
{
	head = NULL;
}

void SJF_TWICE:: process_queue::add_process_parameter(string data, int running, int arriving, int index_number)
{
	process* temp;
	temp = new process;
	temp->process_name = data;
	temp->running_time = running;
	temp->index = index_number;

	temp->arrived_time = arriving;
	temp->next = NULL;
	if (head == NULL)
	{
		head = temp;

	}
	else
	{
		process* current = head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = temp;


	}
}
