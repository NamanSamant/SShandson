/*
============================================================================
Name : 25.c
Author : Naman Samant
Description : Write a program to create three child processes. The parent should wait for a particular child (use
waitpId system call).
Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main() {
	int stat;
	pid_t pId1, pId2, pId3;
    	pId1 = fork();
    	if (pId1 < 0) {
        	printf("Fork failure for child 1 \n");
        	exit(1);
    	}else if (pId1 == 0) {
		printf("Child 1: pId - %d\n", getpid());
        	sleep(2);
        	exit(1);
    	}
	pId2 = fork();
    	if (pId2 < 0) {
        	printf("Fork failure for child 2 \n");
        	exit(1);
    	}else if (pId2 == 0) {
        	printf("Child 2: pId - %d\n", getpid());
        	sleep(4);
        	exit(2);
    	}
   	pId3 = fork();
    	if (pId3 < 0) {
        	printf("Fork failure for child 3\n");
        	exit(1);
    	}else if (pId3 == 0) {
        	printf("Child 3: pId - %d\n", getpid());
        	sleep(6);
        	exit(3);
    	}
    	printf("Parent process is waiting for Child 2 (pId - %d) to finish...\n", pId2);
    	waitpid(pId2, &stat, 0);
    	if(WIFEXITED(stat)) {
        	printf("Parent process: Child 2 (pId - %d) finished with exit status %d\n", pId2, WEXITSTATUS(stat));
    	}else {
        	printf("Parent process: Child 2 (pId - %d) did not terminate normally\n", pId2);
    	}
	waitpid(pId1, NULL, 0);
    	waitpid(pId3, NULL, 0);
	printf("Parent process: All children have finished.\n");
    	return 0;
}
