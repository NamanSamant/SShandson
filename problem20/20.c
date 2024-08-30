/*
============================================================================
Name : 20.c
Author : Naman Samant
Description : Find out the priority of your running program. Modify the priority with nice command.
Date : 30th Aug 2024
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h>
int main() {
	pid_t pId = getpid();
	int priority = getpriority(PRIO_PROCESS, pId);
	if(priority == -1) {
		printf("There was an error fetching priority \n");
		return 0;
	}
	printf("priority of the process: %d\n", priority);
	int newNiceVal = 5;
	int newPriority = nice(newNiceVal);
	if (newPriority == -1) {
        	printf("There was an error setting priority with nice");
        	return 0;
    	}
	priority = getpriority(PRIO_PROCESS, pId);
	if(priority == -1) {
		printf("There was an error fetching priority \n");
		return 0;
	}
	printf("New priority of the process: %d\n", priority);

}
