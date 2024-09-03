/*
============================================================================
Name : 4.c
Author : Naman Samant
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 29th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
int main()
{
	int fD=open("open-file.txt", O_RDWR);
	if(fD==-1) printf("There is an error while opening file using open() function\n");
	else printf("Value of File Descriptor = %d\n",fD);
	close(fD);
	fD=open("open-file.txt", O_RDWR | O_CREAT | O_EXCL, 0644);
	if(fD==-1) printf("There's an error while opening file with O_EXCL because - %s\n", strerror(errno));
	else printf("Value of fD (O_EXCL) = %d\n", fD);
	close(fD);
	return 0; 
}
