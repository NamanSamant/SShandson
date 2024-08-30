/*
============================================================================
Name : 1a.c
Author : Naman Samant
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
Date: 28th Aug 2024
============================================================================
*/
#include<unistd.h>
#include<stdio.h>
int main()
{
	if(symlink("naman.txt", "naman-slink2")==0)
	{
		printf("Created\n");
	}
	else
	{
		perror("Error while Creating");
	}
	return 0;
}
