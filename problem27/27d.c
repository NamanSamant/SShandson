/*
============================================================================
Name : 27d.c
Author : Naman Samant
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
 	printf("Implementing 'ls -R1' execv:\n");
    	char *ink[] = { "ls", "-Rl", NULL };
    	execv("/bin/ls", ink);
    	perror("execv failed"); 
    	return 1;
}
