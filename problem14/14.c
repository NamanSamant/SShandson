/*
============================================================================
Name : 14.c
Author : Naman Samant
Description : Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
void printFileType(const char *filePath) {
    	struct stat fileInfo;
	if (stat(filePath, &fileInfo) != 0) {
        printf("Error\n");
        exit(EXIT_FAILURE);
	}
	if (S_ISREG(fileInfo.st_mode)) {
        	printf("%s- This file is a regular file.\n", filePath);
    	} else if (S_ISDIR(fileInfo.st_mode)) {
        	printf("%s- This is a directory.\n", filePath);
    	} else if (S_ISLNK(fileInfo.st_mode)) {
        	printf("%s- This is a symbolic link.\n", filePath);
    	} else if (S_ISCHR(fileInfo.st_mode)) {
        	printf("%s- THis is a character device.\n", filePath);
    	} else if (S_ISBLK(fileInfo.st_mode)) {
        	printf("%s- This is a block device.\n", filePath);
    	} else if (S_ISFIFO(fileInfo.st_mode)) {
        	printf("%s- This is a FIFO (named pipe).\n", filePath);
    	} else if (S_ISSOCK(fileInfo.st_mode)) {
        	printf("%s- This is a socket.\n", filePath);
    	} else {
        	printf("%s- This is of an unknown file type.\n", filePath);
    	}
}
int main() {
    	char filePath[1024];
	printf("Please enter the file path: ");
    	if (fgets(filePath, sizeof(filePath), stdin) == NULL) {
        printf("There's an error while reading path\n");
        return 0;
	}
	filePath[strcspn(filePath, "\n")] = '\0';
	printFileType(filePath);
	return 0;
}
