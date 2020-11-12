#include "queue_functions.c"
#include "process_event_handling.c"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>




const int MAX_PROCESSES = 10000;





float urand()
{
	return( (float) rand()/RAND_MAX );
}


float genexp(float lambda)
{
	float u,x;
	x = 0;
	while (x == 0)
		{
			u = urand();
			x = (-1/lambda)*log(u);
		}
	return(x);
}






int main(int argc, char *argv[]){
	int schedule = atoi(argv[1]);
	int lambda = atoi(argv[2]);
	float average_service_time = atof(argv[3]);
	float quantum = atof(argv[4]);
	float time = 0.0;
	float random;
	float arrival;
	random = genexp(average_service_time);
	
	process* process_head = new_process(random,0.0);
	event* event_head = new_event(0.0,1);
	
	//FCFS simulator
	if(schedule == 1){
		//first process
		create_process(event_head, process_head, time, schedule,random,0 );

		
		while(total_processes < MAX_PROCESSES){
	

			//if arrival
			if(event_head->type == 1){

				time = process_head->arrival_time;
				
				pop_event(&event_head);
			}
			
			//if completion, update time and pop current process and event
			if(event_head->type == 2){

				if(schedule < 3)
					time += process_head->burst_time;
				else
					time += process_head->remaining_time;
				pop_process(&process_head);
				pop_event(&event_head);
			}





			arrival = (genexp(1/lambda) + time);
			random = genexp(average_service_time);
			create_process(event_head, process_head, time, schedule,random,arrival);
			

		
			
		
		
		}
		
		
	}
	
	
	if(schedule == 2){
		std::cout<<"Shortest run time first not implemented";
	}
	
	if(schedule == 3){
		std::cout<<"Round robin not implemented";
	}
	
	
	return 0;
}


	
	