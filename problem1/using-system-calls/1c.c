/*
============================================================================
Name : 1c.c
Author : Naman Samant
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
Date: 28th Aug, 2024.
============================================================================
*/
#include<sys/types.h>
#include<sys/stat.h>
int main(){
	mkfifo("fyfo(using-sys-call)",0666);
	return 0;
}
