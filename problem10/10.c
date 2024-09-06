/*
============================================================================
Name : 10.c
Author : Naman Samant
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data
Date: 29th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>
int main() {
	const char *fName = "f1.txt";
	int fD = open(fName, O_RDWR | O_CREAT, 0644);
	if(fD < 0) {
		printf("Error creating file f1.txt \n");
		close(fD);
		return 0;
	}
	const char *text = "yo what up";
	ssize_t byteW = write(fD, text, strlen(text));
	if(byteW < 0) {
		printf("Error writing to file f1.txt\n");
		close(fD);
		return 0;
	}
	off_t offset = lseek(fD, 10, SEEK_CUR);
	if(offset == (off_t) -1) {
		printf("Error when moving pointer in the file\n");
		close(fD);
		return 0;
	}
	printf("moved to:- %ld\n", offset);
	text = "all good!!";
	byteW = write(fD, text, 10);
	if(byteW < 0) {
		printf("There's an error while writing in file after seeking\n");
		close(fD);
		return 0;
	}
	close(fD);
	printf("File written successfully. To see the empty spaces use `od -c %s`\n", fName);
	return 0;


}
