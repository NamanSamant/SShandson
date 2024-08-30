/*
============================================================================
Name : 9.c
Author : Naman Samant
Description : Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
Date: 29th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include<string.h>
int main() {
	const char *fName = "f1.txt";
	int fD = creat(fName, 0644);
	if(fD < 0) {
		printf("Error creating file f1.txt\n");
		return 0;
	}
	const char *data = "Content of f1.txt \n";
	ssize_t byteW = write(fD, data, strlen(data));
	if(byteW < 0) {
		printf("Error when writing to file f1.txt\n");
		return 0;
	}
	close(fD);
	struct stat fileStats;
	if(stat(fName, &fileStats) < 0) {
		printf("Error while reading file stats \n");
		return 0;
	}
    	printf("File =  %s\n", fName);
    	printf("Inode =  %ld\n", (long) fileStats.st_ino);
    	printf("Number of hard links =  %ld\n", (long) fileStats.st_nlink);
    	printf("UID = %d\n", fileStats.st_uid);
    	printf("GID =  %d\n", fileStats.st_gid);
    	printf("Size =  %ld bytes\n", (long) fileStats.st_size);
    	printf("Block size =  %ld bytes\n", (long) fileStats.st_blksize);
    	printf("Number of blocks =  %ld\n", (long) fileStats.st_blocks);
    	printf("Time of last access = %s", ctime(&fileStats.st_atime));
    	printf("Time of last modification =  %s", ctime(&fileStats.st_mtime));
    	printf("Time of last change =  %s", ctime(&fileStats.st_ctime));
	return 0;
}
