#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#define buffSize 1024
int main()
{
	int fdSource, fdDest;
	ssize_t byteR, byteW;
	char buffer[buffSize];
	fdSource = open("f1.txt", O_WRONLY | O_CREAT, 0644);
	if(fdSource==-1) printf("Error creating file\n");
	else printf("Successfully created file \n");
	const char *cont = "Contents of f1.txt that will be copied in f2.txt\n";
	write(fdSource, cont, strlen(cont));
	close(fdSource);
	fdSource = open("f1.txt", O_RDONLY);
	if(fdSource == -1) printf("Error opening f1.txt\n");
	else printf("Successfully opened f1.txt\n");
	fdDest = open("f2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(fdDest==-1) printf("Error creating file f2.txt\n");
	else printf("Successfully created f2.txt\n");
	while((byteR = read(fdSource, buffer, buffSize)) > 0){
		byteW = write(fdDest, buffer, byteR);
		if(byteR != byteW){
			printf("Error while writing to destination file - f2.txt\n");
			close(fdSource);
			close(fdDest);
		}
	}
	if(byteR==-1) printf("Error\n");
	close(fdSource);
	close(fdDest);
	return 0;
}
