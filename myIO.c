/* deal with all input and output 							  */
/* input format: person1 number_of_friend friend1, friend2... */
/* output format: algorithm: person1 to person2				  */
/* error condition and message at the end					  */
#include "basic.h"
#include "myIO.h"
#include "myDS.h"
#include "myAlgo.h"
#define _err_ag(cond) {_err_message(cond);exit(1);}

//undirected graph
void _build_map(){
	int person1, person2, friend_num;
	
	_map_init();

	//enter
	printf("Build map\nEnter a person(-1 for stop): ");
	while(scanf("%d", &person1) != EOF && person1 > 0){
		printf("Enter the number of person's friend count: ");
		scanf("%d", &friend_num);
		printf("Enter friends separated by space: ");
		for (int i = 0; i < friend_num; i++){
			scanf("%d", &person2);
			relation_map[person1][person2] = TRUE;
			relation_map[person2][person1] = TRUE;
		}
		printf("Enter a person: ");
	}
}

//path from person1 to person2
void _print_relation(){
	//nothing
	if (_stack_empty()){
		printf("Stranger!\n");
		return;
	}

	//path
	printf("%d", _stack_top());
	_stack_pop();
	while(!_stack_empty()){
		printf(" > %d", _stack_top());
		_stack_pop();
	}
	printf("\n");
}

void _check_argument(int argc, char **argv){
	#define SAME 0
	
	if (argc == 1) _err_ag(0)	//case no argu
	if (argc - 1 > MAX_algorithm) _err_ag(1) //case many argu
	
	//case unknown
	for (int i = 1; i < argc; i++){
		int flag = FALSE;
		for (int j = 0; j < MAX_algorithm; j++){
			if (strcasecmp(argv[i], algo_name[j]) == SAME){
				flag = TRUE;
				break;
			}
		}
		if (!flag) _err_ag(2)
	}

	//case same
	for (int i = 1; i < argc - 1; i++){
		for (int j = i + 1; j < argc; j++){
			if (strcasecmp(argv[i], argv[j]) == SAME) _err_ag(3);
		}
	}
	
	#undef SAME
}

void _err_message(int condition){
	if (condition == 0) printf("no arguments!\n");
	else if (condition == 1) printf("too many arguments!\n");
	else if (condition == 2) printf("unknown algorithm!\n");
	else if (condition == 3) printf("same algorithm!\n");
	printf("usage: a.out algorithm1 [algorithm2]\n");
}