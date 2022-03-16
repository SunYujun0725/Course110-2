/*	provide exact one stack and one circular queue  */
/*	you should do operations on them by functions   */
#include "basic.h"
#include "myDS.h"
#define MAX_stack MAX_person
#define MAX_queue (MAX_person * MAX_person)
#define flow(state) {printf(#state"flow\n");return;}

//stack
int stack_array[MAX_stack];
int stack_rear = 0;

//circular queue
int queue_array[MAX_queue];
int queue_rear = 1;
int queue_front = 0;

void _stack_push(int value);
void _stack_pop();
BOOL _stack_empty();
int _stack_top();
void _queue_push(int value);
void _queue_pop();
BOOL _queue_empty();
int _queue_front();

//add
void _stack_push(int value){
	if (stack_rear == MAX_stack) flow(Over)	//full
	stack_array[stack_rear++] = value;
}

void _queue_push(int value){
	if (queue_rear == queue_front) flow(Over)
	queue_array[queue_rear] = value;
	queue_rear = queue_rear + 1 % MAX_queue;
}

//delete
void _stack_pop(){
	if (_stack_empty()) flow(Under)
	stack_rear--;
}

void _queue_pop(){
	if (_queue_empty()) flow(Under)
	queue_front = queue_front + 1 % MAX_queue;
}

//get element
int _stack_top(){
	if (_stack_empty()){
		printf("No element\n");
		exit(1);
	}
	return stack_array[stack_rear - 1];
}

int _queue_front(){
	if (_queue_empty()){
		printf("No element\n");
		exit(1);
	}
	return queue_array[queue_front + 1];
}

//state
BOOL _stack_empty(){
	if (stack_rear == 0) return TRUE;
	return FALSE;
}

BOOL _queue_empty(){
	if ( (queue_front + 1 % MAX_queue) == queue_rear) return TRUE;
	return FALSE;
}