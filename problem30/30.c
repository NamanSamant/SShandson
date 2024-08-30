
/*
============================================================================
Name : 30.c
Author : Naman Samant
Description : Write a program to run a script at a specific time using a Daemon process.
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>
#include <errno.h>
void createDaemon(){
    	pid_t pid;
	pid = fork();
	if(pid < 0){
		exit(EXIT_FAILURE);
    	}
	if(pid > 0){
        	exit(EXIT_SUCCESS);
 	}
	if(setsid() < 0){
        	exit(EXIT_FAILURE);
    	}
	pid = fork();
	if (pid < 0){
        	exit(EXIT_FAILURE);
    	}
	if(pid > 0){
        	exit(EXIT_SUCCESS);
    	}
	umask(0);
	for (int x = sysconf(_SC_OPEN_MAX); x >= 0; x--) {
        	close(x);
    	}
}
void runScript(const char *scriptPath, int hour, int minute) {
    	time_t now;
    	struct tm *currTime;
	while (1){
	now = time(NULL);
        currTime = localtime(&now);
	if (currTime->tm_hour == hour && currTime->tm_min == minute) {
            	if (system(scriptPath) == -1) {
                	perror("Failure to execute script");
            	}
            	break;
        }
	sleep(60);
	}
}
int main() {
    	const char *scriptPath = "./script.sh";
    	int hour = 18;
    	int minute = 59;
	createDaemon();
	runScript(scriptPath, hour, minute);
	return 0;
}
