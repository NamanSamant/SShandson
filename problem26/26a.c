/*
============================================================================
Name : 26a.c
Author : Naman Samant
Description : Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>

int main(int count, char *ip[]) {
    if (count > 1) {
        printf("Hi I am %s\n", ip[1]);
    } else {
        printf("new\n");
    }
    return 0;
}
