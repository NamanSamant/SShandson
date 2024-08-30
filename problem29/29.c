/*
============================================================================
Name : 29.c
Author : Naman Samant
Description : Write a program to get scheduling Policy and modify the scheduling Policy (SCHED_FIFO,
SCHED_RR).
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <errno.h>
#include <string.h>
void printPolicy(int Policy){
	switch(Policy){
        	case SCHED_OTHER:
            		printf("SCHED_OTHER\n");
            		break;
        	case SCHED_RR:
            		printf("SCHED_RR\n");
            		break;
        	case SCHED_FIFO:
            		printf("SCHED_FIFO\n");
            		break;
        	default:
            		printf("Scheduling unknown\n");
    	}
}
int main() {
    	int Policy;
    	struct sched_param parameters;
	Policy = sched_getscheduler(0);
    	if(Policy == -1){
        	printf("sched_getscheduler failed \n");
        	return 0;
    	}
	printPolicy(Policy);
	printf("Modifying scheduling Policy to SCHED_FIFO --\n");
    	parameters.sched_priority = 10;
    	if(sched_setscheduler(0, SCHED_FIFO, &parameters) == -1) {
        	printf("sched_setscheduler failed for SCHED_FIFO %s\n",  strerror(errno));
        	return 0;
    	}
	Policy = sched_getscheduler(0);
    	if(Policy == -1) {
        	printf("sched_getscheduler failed \n");
        	return 0;
    	}
	printPolicy(Policy);
	printf("Modifying scheduling Policy to SCHED_RR...\n");
    	parameters.sched_priority = 10;
    	if(sched_setscheduler(0, SCHED_RR, &parameters) == -1){
        	printf("sched_setscheduler failed for SCHED_RR \n");
        	return 0;
    	}
	Policy = sched_getscheduler(0);
    	if(Policy == -1){
        	printf("sched_getscheduler failed \n");
        	return 0;
    	}
	printPolicy(Policy);
	return 0;
}
