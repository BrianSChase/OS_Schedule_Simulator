#include "queue_functions.c"
#include "process_event_handling.c"
#include <stdio.h>
#include <stdlib.h>


/*
Notes:
1. Adjust the queue push functions so that if its schedule FCFS, just do a normal push
and then skip the restorecrtmode

*/









//Global variables
bool end_condition = false;
//This will hold the command line arg for the type of schedule
int schedule;
//This will hold command line quantum
float quantum;
const int MAX_PROCESSES = 10000;

process* process_head(0.1);
event* event_head = new_event(1.0,1);

void printList(struct event* n) 
{ 
    while (n != NULL) { 
        printf(" %d ", (int)n->time); 
        n = n->next; 
    } 
}









int main(){
	//create_process();

	//process* process_head(0.1);
	//event* event_head = new_event(1.0,1,5);
	
	/*
	push_event(&event_head, 3.0,2,3);
	push_event(&event_head, 2.0,3,2);
	push_event(&event_head, 4.0,3,4);
	
	
	printList(event_head);
	 
	
	
	pop_event(&event_head);
	
	printList(event_head);
	pop_event(&event_head);
	pop_event(&event_head);
	
	*/
	
	
	return 0;
}