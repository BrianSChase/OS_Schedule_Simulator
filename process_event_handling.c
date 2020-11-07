#include <stdio.h>
#include <stdlib.h>



//global
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


//time variable is system time
void create_process(event* event_head, process* process_head, float time, int schedule){
	//push process
	push_process(&process_head, 0.1);
	
	//push appropriate events
	//arrival event
	push_event(&event_head, time, 1);
	
	//if round robin create time slice event
	if(schedule == 2)
		push_event(&event_head, time, 3);
	//else push Completion event
	else
		push_event(&event_head, time, 2);
	
	//Update times
	
	//Update necessary statistics
	
	
}


//Process the next event
//time variable is the system time
void process_event(event* eve, event* event_head, process* process_head, float time, int schedule, float quantum){
	//if arrival
	if(eve->type == 1){
		CPU = 1;
		time = process_head->arrival_time;
		
		pop_event(&event_head);
	}
	
	//if completion
	if(eve->type == 2){
		CPU = 2;
		if(schedule < 2)
			time += process_head->burst_time;
		else
			time += process_head->remaining_time;
		pop_process(&process_head);
		pop_event(&event_head);
	}
	
	//if time slice
	if(eve->type == 3){
		process_head->remaining_time = (process_head->burst_time - quantum);
		if(process_head->remaining_time > 0.0)
			time += quantum;
		if(process_head->remaining_time <= 0.0)
			time += (quantum + process_head->remaining_time);
			pop_process(&process_head);
		//Move process to the back of line
		
	}
	
	
}

//THis will determine where the events go.
void schedule_events(){
	
}