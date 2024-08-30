/*
============================================================================
Name : 6.c
Author : Naman Samant
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 29th Aug, 2024.
============================================================================
*/
#include<unistd.h>
#include<fcntl.h>
int main()
{
	char buff[512];
	ssize_t bytesR;
	while((bytesR = read(STDIN_FILENO, buff, 512)) > 0){
		write(STDOUT_FILENO, buff, bytesR);
	}
	return 0;
}
