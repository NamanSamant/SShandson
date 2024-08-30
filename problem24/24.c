/*
============================================================================
Name : 24.c
Author : Naman Samant
Description : Write a program to create an orphan process.
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
		printf("(when pId == 0) Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
		sleep(5);
		printf("(when pId == 0) Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
	} else {
        	printf("(when pId is positive) Parent process: PID = %d, Child PID = %d\n", getpid(), pId);
        	exit(0);
    	}
	return 0;
}
