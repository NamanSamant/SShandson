/*
============================================================================
Name : 5.c
Author : Naman Samant
Description : Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
Date: 29th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main()
{
	const char *fileNames[] = {"f1.txt", "f2.txt", "f3.txt", "f4.txt", "f5.txt"};
	int fD[5];
	int i=0;
	while(1)
	{
	        for(i;i<5;i++)
	        {
		          char fName[30];
		          strcpy(fName, fileNames[i]);
		          fD[i] = open(fName, O_CREAT | O_RDWR, 0644);
		          if(fD[i]==-1) printf("error creating the file%d\n",i);
		          else printf("Created %s with FD value = %d\n",fName, fD[i]);
	        }
		sleep(1);
	}
	return 0;
}
