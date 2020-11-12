#include <stdio.h>
#include <stdlib.h>
#include <iostream>


//global
//CPU state:
//1. Active
//2. Idle
int CPU;
//Time until next process
float next_process_time;



//time variable is system time
void create_process(event* event_head, process* process_head, float time, int schedule, float burst,float arrival){
	//push process
	push_process(&process_head, burst, schedule, arrival);
	
	
	//push appropriate events
	//arrival event
	push_event(&event_head, time, 1, schedule);

	//if round robin create time slice event
	if(schedule == 3)
		push_event(&event_head, time, 3, schedule);
	//else push Completion event
	else
		push_event(&event_head, time, 2, schedule);

	
}

//Function currently not working
//Process the next event
//time variable is the system time
float process_event(event* event_head, process* process_head, float time, int schedule, float quantum){
	
	std::cout<<"In function";
	//if arrival
	if(event_head->type == 1){
		CPU = 1;
		time = process_head->arrival_time;
		
		pop_event(&event_head);
	}
	
	//if completion, update time and pop current process and event
	if(event_head->type == 2){
		CPU = 2;
		if(schedule < 2)
			time += process_head->burst_time;
		else
			time += process_head->remaining_time;
		pop_process(&process_head);
		pop_event(&event_head);
	}
	
	//if time slice
	if(event_head->type == 3){
		process_head->remaining_time = (process_head->burst_time - quantum);
		if(process_head->remaining_time > 0.0)
			time += quantum;
		if(process_head->remaining_time <= 0.0)
			time += (quantum + process_head->remaining_time);
			pop_process(&process_head);
		//Move process to the back of line
		
	}
	
	return time;
}

