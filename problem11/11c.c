#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>
int main() {
	const char *fName = "f3.txt";
	int fD = open(fName, O_RDWR | O_CREAT | O_APPEND, 0644);
	if(fD < 0) {
		printf("Error while creating the file \n");
		return 0;
	}
	int fDDuplicate = fcntl(fD, F_DUPFD, 0);
	if(fDDuplicate < 0) {
		close(fDDuplicate);
		printf("There's an error while duplicating file \n");
		return 0;
	}
	char *data = "original content of file (fcntl) \n";
	if(write(fD, data, strlen(data)) < 0) {
		printf("Error while writing into the file \n");
		close(fD);
		close(fDDuplicate);
		return 0;
	}
	data = "Content written from Duplicate file  (fcntl) \n";
	if(write(fDDuplicate, data, strlen(data)) < 0) {
		printf("Error while writing into the file \n");
		close(fD);
		close(fDDuplicate);
		return 0;
	}
	close(fD);
	close(fDDuplicate);

}
