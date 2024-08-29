#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int fD=open("open-file.txt", O_RDWR);
	if(fD==-1) printf("There is an error while opening file using open() function\n");
	else printf("Value of File Descriptor = %d\n",fD);
	close(fD);
	fD=open("open-file.txt", O_RDWR | O_CREAT | O_EXCL);
	if(fD==-1) printf("There's an error while opening file with O_EXCL\n");
	else printf("Value of fD (O_EXCL) = %d\n", fD);
	close(fD);
	return 0; 
}
