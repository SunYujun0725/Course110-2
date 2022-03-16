#ifndef myIO_H
#define myIO_H
#define _print(state) {printf(#state": ");_print_relation();}

#define MAX_algorithm 2
char algo_name[MAX_algorithm][10];
int relation_map[MAX_person][MAX_person];

void _build_map();  //
void _print_relation();
void _check_argument(int argc, char **argv);  //
void _err_message(int condition);

#endif