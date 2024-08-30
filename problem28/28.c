/*
============================================================================
Name : 28.c
Author : Naman Samant
Description : Write a program to get maximum and minimum real time priority.
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
int main() {
	int minPriorityRR;
    	int minPriorityFIFO;
    	int maxPriorityFIFO;
    	int maxPriorityRR;
   	minPriorityFIFO = sched_get_priority_min(SCHED_FIFO);
   	 if (minPriorityFIFO == -1) {
        	perror("SCHED_FIFO failed");
        	exit(EXIT_FAILURE);
    	}
	minPriorityRR = sched_get_priority_min(SCHED_RR);
   	if (minPriorityRR == -1) {
        	perror("SCHED_RR failed");
        	exit(EXIT_FAILURE);
    	}
	maxPriorityFIFO = sched_get_priority_max(SCHED_FIFO);
    	if (maxPriorityFIFO == -1) {
        	perror("SCHED_FIFO failed");
        	exit(EXIT_FAILURE);
    	}
   	maxPriorityRR = sched_get_priority_max(SCHED_RR);
    	if (maxPriorityRR == -1) {
        	perror("SCHED_RR failed");
        	exit(EXIT_FAILURE);
    	}
	printf("RT scheduling priorities - \n");
   	printf("SCHED_RR - \n");
    	printf("Maximum priority: %d\n", maxPriorityRR);
    	printf("Minimum priority: %d\n", minPriorityRR);
	printf("SCHED_FIFO - \n");
  	printf("Maximum priority: %d\n", maxPriorityFIFO);
    	printf("Minimum priority: %d\n", minPriorityFIFO);
	return 0;
}
