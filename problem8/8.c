/*
============================================================================
Name : 8.c
Author : Naman Samant
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date: 29th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define bSize 1024

int main() {
	int fD = open("f1.txt", O_RDONLY);
	if(fD == -1) {
		printf("Error opening file f1.txt\n");
		return 0;
	}
	ssize_t byteR;
	char buffer[bSize], line[bSize];
	int j = 0;
	while((byteR = read(fD, buffer, bSize)) > 0) {
		for(int i = 0; i < byteR; i++) {
			if(buffer[i] == '\n') {
				line[j] = '\0';
				printf("%s\n", line);
				j = 0;
			} else line[j++] = buffer[i];
		}
	}
	if(j > 0) {
		line[j] = '\0';
		printf("%s\n", line);
	}
	close(fD);
	return 0;

}
