#include "basic.h"
#include "myIO.h"
#include "myAlgo.h"

int main(int argc, char **argv){
	int person1, person2;
	_check_argument(argc, argv);   

	_build_map();   
	
	printf("Enter query: ");
	while(scanf("%d", &person1) != EOF && person1 > 0){
		scanf("%d", &person2);

		for (int i = 1; i < argc; i++){
			algo_init();
			if (strcasecmp(argv[i], "DFS") == 0){
				_DFS(person1, person2);
				_print(DFS)    //macro: printf("DFS: "); _print_relation();   //
			}
			else if (strcasecmp(argv[i], "BFS") == 0){
				_BFS(person1, person2);
				_print(BFS)   //macro: printf("BFS: "); _print_relation();   //
			}
		}
		printf("Enter query: ");
	}
	return 0;
}
