
/*
============================================================================
Name : 17b.c
Author : Naman Samant
detailription : Write a program to simulate online ticket reservation. Implement write lock
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
int main() {
    	int detail;
    	struct {
        	int ticketNo;
    	}t;
	struct flock lock;
	detail = open("f1.txt", O_RDWR);
    	lock.l_type = F_WRLCK;
    	lock.l_whence = SEEK_SET;
    	lock.l_start = 0;
    	lock.l_len = sizeof(t);
    	lock.l_pid = getpid();
	fcntl(detail, F_SETLKW, &lock);
	printf("Inside critical section\n");
	read(detail, &t, sizeof(t));
	printf("Current ticket number is - %d\n", t.ticketNo);
  	t.ticketNo++;
	lseek(detail, 0, SEEK_SET);
    	write(detail, &t, sizeof(t));
	printf("Press Enter to unlock\n");
    	getchar();
    	lock.l_type = F_UNLCK;
    	fcntl(detail, F_SETLK, &lock);
	printf("Out of critical section\n");
	close(detail);
	return 0;
}
