/*
============================================================================
Name : 3.c
Author : Naman Samant
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call.
Date: 28th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
	int fD=creat("textFile.txt",0644);
	if(fD==-1){
		printf("Error creting a file\n");
		return 0;
	}
	printf("Value of file Descriptor = %d\n",fD);
	close(fD);
	return 0;
}
