
/*
============================================================================
Name : 27c.c
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
	printf("Implementing 'ls -R1' execle:\n");
   	execle("/bin/ls", "ls", "-Rl", (char *)NULL, NULL);
    	perror("execle failed"); 
  	return 1  ;
}
