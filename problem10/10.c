#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>
int main() {
	const char *fName = "f1.txt";
	int fD = open(fName, O_RDWR | O_CREAT, 0644);
	if(fD < 0) {
		printf("Error creating file f1.txt \n");
		close(fD);
		return 0;
	}
	const char *text = "yowhatsup";
	ssize_t byteW = write(fD, text, strlen(text));
	if(byteW < 0) {
		printf("Error writing to file f1.txt\n");
		close(fD);
		return 0;
	}
	off_t offset = lseek(fD, strlen(text), SEEK_CUR);
	if(offset == (off_t) -1) {
		printf("Error when moving pointer in the file\n");
		close(fD);
		return 0;
	}
	text = "allgood";
	byteW = write(fD, text, strlen(text));
	if(byteW < 0) {
		printf("There's an error while writing in file after seeking\n");
		close(fD);
		return 0;
	}
	close(fD);
	printf("File written successfully. To see the empty spaces use `od -c %s`\n", fName);
	return 0;


}
