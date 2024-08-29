#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>
int main() {
	const char *fName = "f1.txt";
	int fD = open(fName, O_RDWR | O_CREAT | O_APPEND, 0644);
	if(fD < 0) {
		printf("There's an error while creating file \n");
		return 0;
	}
	int fDDuplicate = dup(fD);
	if(fDDuplicate < 0) {
		close(fD);
		printf("There's an Error while duplicating file \n");
		return 0;
	}
	char *data = "Content of Original File \n";
	if(write(fD, data, strlen(data)) < 0) {
		printf("Error occurred writing into the file \n");
		close(fD);
		close(fDDuplicate);
		return 0;
	}
	data = "Content written from Duplicate file \n";
	if(write(fDDuplicate, data, strlen(data)) < 0) {
		printf("Error while writing into the file \n");
		close(fD);
		close(fDDuplicate);
		return 0;
	}
	close(fD);
	close(fDDuplicate);
	return 0;

}
