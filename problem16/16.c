/*
============================================================================
Name : 16.c
Author : Naman Samant
Description : Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock
Date: 29th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
void setLock(int fd, int lockType) {
	struct flock lock;
	lock.l_type = lockType;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();
	if(fcntl(fd, F_SETLKW, &lock) == -1) {
		printf("Not able to lock \n");
		exit(EXIT_FAILURE);
	}
}
void removeLock(int fd) {
	struct flock lock;
	lock.l_type = F_UNLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();
	if(fcntl(fd, F_SETLKW, &lock) == -1) {
		printf("Unable to release lock \n");
		exit(EXIT_FAILURE);
	}
}
int main() {
	const char *fName = "f1.txt";
	int fD = open(fName, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	if(fD == -1) {
		printf("There's an error while opening file \n");
		return 0;
	}
	printf("Applying write lock...\n");
	setLock(fD, F_WRLCK);
	printf("Write lock applied. Press Enter to release the lock...\n");
	getchar();
	removeLock(fD);
	printf("Write lock released. Press Enter to apply read lock...\n");
	getchar();
	printf("Applying read lock...\n");
   	setLock(fD, F_RDLCK);
    	printf("Read lock applied. Press Enter to release the lock...\n");
    	getchar();
	removeLock(fD);
	printf("Read lock released\n");
	close(fD);
    	return 0;
}
