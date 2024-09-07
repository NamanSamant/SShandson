/*
============================================================================
Name : 13.c
Author : Naman Samant
Description :Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 30th Aug, 2024.
============================================================================
*/#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>
#include <string.h>
int main(){
	fd_set readFds;
	struct timeval tOut;
	tOut.tv_sec = 10;
	tOut.tv_usec = 0;
	FD_ZERO(&readFds);
	FD_SET(STDIN_FILENO, &readFds);
	printf("Waiting for input(for 10 seconds)\n");
	int value = select(STDIN_FILENO + 1, &readFds, NULL, NULL, &tOut);
	if(value == -1) {
		printf("There's an error while reading input\n");
		return 0;
	}
	if(value == 0) {
		printf("No Data was entered in 10 seconds\n");
		return 0;
	}
	if(FD_ISSET(STDIN_FILENO, &readFds)) {
		char buffer[1024];
		printf("Data available on STDIN\n");
		ssize_t byteR = read(STDIN_FILENO, buffer, 1024);
		buffer[byteR] = '\0';
		printf("Data = %s\n", buffer);
	}
	return 0;
}
