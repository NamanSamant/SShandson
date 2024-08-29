#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main()
{
	const char *fileNames[] = {"f1.txt", "f2.txt", "f3.txt", "f4.txt", "f5.txt"};
	int fD[5];
	for(int i=0;i<5;i++)
	{
		char fName[30];
		strcpy(fName, fileNames[i]);
		fD[i] = open(fName, O_CREAT | O_RDWR, 0644);
		if(fD[i]==-1) printf("error creating the file%d\n",i);
		else printf("Created %s with FD value = %d\n",fName, fD[i]);
	}
	while(1)
	{
		sleep(1);
	}
	return 0;
}
