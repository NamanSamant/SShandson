/*
============================================================================
Name : 26b.c
Author : Naman Samant
Description : Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
    char *program = "./26a";  
    char *arguments[] = {program, "Naman", NULL}; 
    printf("executing program %s with agrument -> Naman(as string)\n", program);
    execvp(program, arguments);
    perror("execution failed");
    return 1;
}
