
/*
============================================================================
Name : 22.c
Author : Naman Samant
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
int main() {
	int fD = open("f1.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
    	if (fD < 0) {
        	printf("There was an error opening file");
        	exit(1);
    	}
	pid_t pId = fork();
	if(pId == -1) {
    		printf("There was error creating child processes \n");
    		return 0;
    	} else if(pId == 0) {
    		const char *childMssg = "Hi this is the child process.\n";
        	if (write(fD, childMssg, strlen(childMssg)) < 0) {
            		printf("There was an error writing from child process \n");
            		close(fD);
            		exit(1);
        	}
        	printf("The child process wrote to the file.\n");
    	} else {
    		const char *parentMssg = "Hello from the parent process.\n";
        	if (write(fD, parentMssg, strlen(parentMssg)) < 0) {
            		printf("There was an error writing from child process \n");
            		close(fD);
            		exit(1);
        	}
        	printf("The parent process wrote to the file.\n");
    	}
	close(fD);
    	return 0;
}
