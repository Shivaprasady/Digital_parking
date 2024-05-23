#ifndef PARKING_H
#define PARKING_H 

#include<stdio.h>

#define SUCCESS 0
#define FAILURE 1

#define G \033[32m 
#define R \033[31m

int print_availability();
int available_slot();
int exit_slot();


#endif
