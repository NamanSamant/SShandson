
/*
============================================================================
Name : 23.c
Author : Naman Samant
Description : CWrite a program to create a Zombie state of the running program.
Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main() {
	pid_t pId = fork();
	if (pId < 0) {
       		printf("Fork failed");
        	return 1;
    	} else if (pId == 0) {
		printf("(when pid == 0) Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        	exit(0);
	} else {
        	printf("(when pid is positive) Parent process: PID = %d, Child PID = %d\n", getpid(), pId);
        	sleep(20);
		wait(NULL);
        	printf("Parent process:  Child process has released\n");
    	}
	return 0;
}
