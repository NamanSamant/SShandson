/*
============================================================================
Name : 26.c
Author : Naman Samant
Description : Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
    	char *program = "./26a";
    	printf("Executing %s\n", program);
	if (execl(program, program, NULL) == -1) {
        	printf("execv failed \n");
        	exit(1);
    	}
	printf("Not executed if execv is successful\n");
    	return 0;
}
