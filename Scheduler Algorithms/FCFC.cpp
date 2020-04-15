#include "FCFS.h"
process_queue:: process_queue()
	{
		head = NULL;
	}
void process_queue:: add_process_parameter(string data, int running, int arriving, int index_number)
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
	
	void FCFS :: set_new_process(string name, int run, int arrive)
	{
		count++;
		index_num++;
		processes.add_process_parameter(name, run, arrive, index_num);
	}
	void  FCFS :: calc_waiting_time()
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
	float FCFS :: average_fun()
	{
		int sum = 0;
		process* current = processes.head->next;
		while (current != NULL)
		{
			sum += current->waiting_time;
			current = current->next;
		}
		total_average = static_cast<float>(sum) / count;
	return total_average;

	}
	void FCFS :: sort()// function to sort processes according to the running time
	{
		process* current = processes.head;
		int num = 0;
		while (num < count)
		{
			while (current->next != NULL)
			{
				if (current->arrived_time > (current->next->arrived_time))
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
	void  FCFS :: is_equal()
	{
		process* current = processes.head;
		while (current != NULL)
		{
			process* current_equal = current;
			while (current_equal != NULL)
			{
				if (current->arrived_time == current_equal->arrived_time)
				{
					if (current->running_time > current_equal->running_time)
					{
						process* temp;

						temp = new process;

						temp->process_name = current->process_name;
						temp->running_time = current->running_time;
						temp->index = current->index;
						/////////////////////////////////
						current->process_name= current_equal->process_name;
						current->running_time= current_equal->running_time;
						current->index= current_equal->index;
						////////////////////////////////
						current_equal->process_name= temp->process_name;
						current_equal->running_time= temp->running_time;
						current_equal->index= temp->index;
					}

				}
				current_equal = current_equal->next;
			}
			current = current->next;
		}
	}
	/*void FCFS :: return_values()
	{
		if (current_return != NULL)
		{

			current_return = current_return->next;
		}
	}*/
	process* FCFS :: return_value_to_mostafa()
	{
		return processes.head;
	}

	void  FCFS :: is_burst_equal_zero()
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
	void  FCFS :: fcfs_method()
	{
		sort();
		calc_waiting_time();
		average_fun();
		is_burst_equal_zero();
        //is_equal();
		//print();
	}
