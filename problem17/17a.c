/*
============================================================================
Name : 17a.c
Author : Naman Samant
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
int main()
{
	int detail;
	struct{
		int ticketNo;
	}t;
	t.ticketNo=200;
	detail = open("f1.txt",O_CREAT|O_RDWR, 0744);
	write(detail, &t, sizeof(t));
	close(detail);
	detail = open("f1.txt",O_RDONLY);
	read(detail, &t,sizeof(t));
	printf("ticket no is - %d\n",t.ticketNo);
	close(detail);
}
