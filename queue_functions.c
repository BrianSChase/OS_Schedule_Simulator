
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
	int burst_time;
	int arrival_time;
	int remaining_time;
	int pid;
	//To determine where it is in the queue
	int position = 0;
	struct process* next;
};




event* new_event(float t, int ty) 
{ 
    event* temp = (event*)malloc(sizeof(event)); 
    temp->time = t; 
    temp->type = ty; 
	temp->priority = p;
    temp->next = NULL; 
  
    return temp; 
}

 
process* new_process(int b, int p, int arr, int id) 
{ 
    process* temp = (process*)malloc(sizeof(process)); 
    temp->burst_time = b; 
    temp->priority = p; 
	temp->arrival_time = arr;
	temp->pid = id;
    temp->next = NULL; 
	total_processes++;
  
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
void push_event(event** head, float t, int ty, int p) 
{ 
    event* start = (*head); 
  
    // Create new event 
    event* temp = new_event(t, ty, p); 
  
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



//push based on priority
void push_process(process** head, int b, int p,int arr, int id) 
{ 
   process* start = (*head); 
  
    // Create new process 
    process* temp = new_process(b, p, arr, id); 
  
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