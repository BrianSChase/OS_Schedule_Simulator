
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
	int position = 0;
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

 
process* new_process(float b) 
{ 
    process* temp = (process*)malloc(sizeof(process)); 
    temp->burst_time = b; 
    temp->next = NULL; 
  
    return temp; 
}


//////////////////////////////////////////////////Event Queue functions
void pop_event(event** head) 
{ 
    event* temp = *head; 
    (*head) = (*head)->next; 
    free(temp); 
} 

//push based on priority
void push_event(event** head, float t, int ty) 
{ 
    event* start = (*head); 
  
    // Create new event 
    event* temp = new_event(t, ty); 
  
    // Special Case: The head of list has lesser 
    // priority than new node. So insert new 
    // node before head node and change head node. 
    if ((*head)->priority > p) { 
  
        // Insert New Node before head 
        temp->next = *head; 
        (*head) = temp; 
    } 
    else { 
  
        // Traverse the list and find a 
        // position to insert new node 
        while (start->next != NULL && 
               start->next->priority < p) { 
            start = start->next; 
        } 
  
        // Either at the ends of the list 
        // or at required position 
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
	total_processes--;
} 



//push based on shortest burst time
void push_process(process** head, float b) 
{ 
   process* start = (*head); 
  
    // Create new process 
    process* temp = new_process(b); 
  
    // Special Case: The head of list has lesser 
    // priority than new node. So insert new 
    // node before head node and change head node. 
    if ((*head)->burst_time > b) { 
  
        // Insert New Node before head 
        temp->next = *head; 
        (*head) = temp; 
    } 
    else { 
  
        // Traverse the list and find a 
        // position to insert new node 
        while (start->next != NULL && 
               start->next->burst_time < b) { 
            start = start->next; 
			//keeps track of what position it is in the list
			temp->position++;
        } 
  
        // Either at the ends of the list 
        // or at required position 
        temp->next = start->next; 
        start->next = temp; 
		total_processes++;
    } 
} 