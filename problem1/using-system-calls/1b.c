/*
============================================================================
Name : 1b.c
Author : Naman Samant
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
Date: 28th Aug, 2024.
============================================================================
*/
#include<unistd.h>
int main(){
	link("hardlink_2.txt","hardlink_2");
	return 0;
}
