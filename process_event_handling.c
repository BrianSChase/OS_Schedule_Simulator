#include <stdio.h>
#include <stdlib.h>
#include "queue_functions.c"
#include "driver.c"

//global
float time = 0.0;
//CPU state:
//1. Active
//2. Idle
int CPU;
//Time until next process
float next_process_time;

////////////////STEPS:
/*
1. Process is created
	1a. Create process arrival event
		1ba. If preempting, create time slice event and process complete event
		1bb. If not preempting, create process complete event
	2. Have first process go into CPU and update CPU status, pop arrival event
	3. AFter CPU finishes task, Update CPU status and appropriate statistics, pop process and completion event
	4. Repeat


*/



void create_process(){
	//push process
	push_process(&process_head, 0, 0, 0, total_processes);
	
	//push appropriate events
	//arrival event
	push_event(event** head, time, 1 , priority)
	
	//if round robin create time slice event
	if(schedule == 2)
		push_event(event** head, time, 3 , priority)
	//else push Completion event
	else
		push_event(event** head, time, 2 , priority)
	
	//Update times
	
	//Update necessary statistics
	
	
}


//Process the next event
void process_event(event** eve){
	//if arrival
	if(eve->type == 1){
		CPU = 1;
		time = process_head->arrival_time;
		
		pop_event(event_head);
	}
	
	//if completion
	if(eve->type == 2){
		CPU = 2;
		if(schedule < 2)
			time += process_head->burst time;
		else
			time += process_head->remaining_time;
		pop_process(process_head);
		pop_event(event_head);
	}
	
	//if time slice
	if(eve->type == 3{
		process_head->remaining_time = (process_head->burst_time - quantum);
		if(process_head->time_remaining > 0.0)
			time += quantum;
		if(process_head->time_remaining <= 0.0)
			time += (quantum + process_head->time_remaining);
			pop_process(process_head);
		//Move process to the back of line
		
	}
	
	
}

//THis will determine where the events go.
void schedule_events(){
	
}