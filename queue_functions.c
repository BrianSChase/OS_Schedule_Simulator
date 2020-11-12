
#include <stdio.h>
#include <stdlib.h>




int total_processes = 0;
/////////////////////Structs
//event structure

//type: 
// 1 = arrival of process
// 2 = completion of process
// 3 = time slice
struct event{
  float time;
  int   type;
  struct event* next;
};

//Process structure
struct process{
	float burst_time;
	float arrival_time;
	float remaining_time;
	//To determine where it is in the queue
	int position;
	struct process* next;
};




event* new_event(float t, int ty) 
{ 
    event* temp = (event*)malloc(sizeof(event)); 
    temp->time = t; 
    temp->type = ty; 
    temp->next = NULL; 
  
    return temp; 
}

 
process* new_process(float b, float arrival) 
{ 
    process* temp = (process*)malloc(sizeof(process)); 
    temp->burst_time = b; 
    temp->next = NULL; 
	temp->position = 0;
	temp->arrival_time = arrival;
  
    return temp; 
}


//////////////////////////////////////////////////Event Queue functions
void pop_event(event** head) 
{ 
    event* temp = *head; 
    (*head) = (*head)->next; 
    free(temp); 
} 


void push_event(event** head, float t, int ty, int schedule) 
{ 
	//FCFS
	if(schedule == 1){
		event* start = (*head); 
	  
		// Create new event 
		event* temp = new_event(t, ty); 

		while (start->next != NULL) { 
			start = start->next; 
			} 
		temp->next = start->next; 
        start->next = temp; 
		
	}
	
	

} 

/////////////////////////////////////////////Process queue functions
void pop_process(process** head) 
{ 
    process* temp = *head; 
    (*head) = (*head)->next; 
    free(temp); 

} 



//push based on schedule
void push_process(process** head, float b, int schedule, float a) 
{ 
   process* start = (*head); 
  
    // Create new process 
    process* temp = new_process(b,a); 
	
	//FCFS
	if(schedule == 1){
		
		while (start->next != NULL) { 
			start = start->next; 
			} 
		temp->next = start->next; 
        start->next = temp; 
		total_processes++;
	
	
	}
	
	
	//Shortest run time first
	if(schedule == 2){
	  

		if ((*head)->burst_time > b) { 
	  
			// Insert New Node before head 
			temp->next = *head; 
			(*head) = temp; 
		} 
		else { 
	  

			while (start->next != NULL && 
				   start->next->burst_time < b) { 
				start = start->next; 
				//keeps track of what position it is in the list
				temp->position++;
			} 
	  

			temp->next = start->next; 
			start->next = temp; 
			total_processes++;
			
		} 
	}
} 


