/*
============================================================================
Name : 11.c
Author : Naman Samant
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
Date: 29th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>
int main() {
	const char *fName = "f2.txt";
	const char *dubfName = "duplicate.txt";

	int fD = open(fName, O_RDWR | O_CREAT | O_APPEND, 0644);
	if(fD < 0) {
		printf("Error while creating the file \n");
		return 0;
	}
	int fd = open(dubfName, O_RDWR | O_CREAT | O_APPEND, 0644);
	if(fd < 0) {
		printf("Error while creating the file \n");
		return 0;
	}
	int fDDuplicate = dup2(fD, fd);
	if(fDDuplicate < 0) {
		close(fD);
		printf("Error while duplicating the file \n");
		return 0;
	}
	char *data = "Content in the Original File (dup2) \n";
	if(write(fD, data, strlen(data)) < 0) {
		printf("Error while writing into the file \n");
		close(fD);
		close(fDDuplicate);
		return 0;
	}
	data = "Content from Duplicate file  (dup2) \n";
	if(write(fDDuplicate, data, strlen(data)) < 0) {
		printf("Error while writing into the file \n");
		close(fD);
		close(fDDuplicate);
		return 0;
	}
	close(fD);
	close(fDDuplicate);
	close(fd);
	return 0;
}
