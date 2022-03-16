/* all algorithm about graph in here */
#include "basic.h"
#include "myAlgo.h"
#include "myDS.h"
#define MAX_algorithm 2

char algo_name[MAX_algorithm][10] = {"DFS", "BFS"};
int relation_map[MAX_person][MAX_person];
int visited[MAX_person];

void _map_init(){
	for (int i = 0; i < MAX_person; i++)
		for (int j = 0; j < MAX_person; j++)
			relation_map[i][j] = FALSE;
}

void algo_init(){
	for (int i = 0; i < MAX_person; i++) visited[i] = FALSE;
	while(!_stack_empty()) _stack_pop();
	while(!_queue_empty()) _queue_pop();
}

BOOL _DFS(int now_person, int to_find){
	visited[now_person] = TRUE;	//set visited

	if (now_person == to_find){	//find
		_stack_push(to_find);
		return TRUE;
	}

	for (int i = 1; i < MAX_person; i++){	//traverse all
		if (relation_map[now_person][i] == TRUE && visited[i] == FALSE){
			if (_DFS(i, to_find)){	//can find
				_stack_push(now_person);
				return TRUE;
			}
		}
	}
	return FALSE; //cannot find
}

BOOL _BFS(int ini_person, int to_find){
	visited[ini_person] = ini_person;	//record come_from
	_queue_push(ini_person);	//first BFS

	while(!_queue_empty()){
		int now_person = _queue_front();
		_queue_pop();

		if (now_person == to_find) break; //find

		for (int i = 1; i < MAX_person; i++){	//traverse all
			if (relation_map[now_person][i] == TRUE && visited[i] == FALSE){
				visited[i] = now_person;	//record come_from
				_queue_push(i);	//push into search queue
			}
		}
	}

	if (visited[to_find] == FALSE) return FALSE; //cannot find;
	while(to_find != visited[to_find]){	//record path
		_stack_push(to_find);
		to_find = visited[to_find];	//become come_from
	}
	_stack_push(to_find); //ini_person;
	return TRUE;	//can find
}
