/*
============================================================================
Name : 27e.c
Author : Anuj Chaudhary
Description : Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execle
d. execv
e. execvp
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
	printf("Implementing `ls -Rl` using execvp:\n");
    	char *in[] = { "ls", "-Rl", NULL };
    	execvp("ls", in);
    	perror("execvp failed"); 
    	return 1;
}
