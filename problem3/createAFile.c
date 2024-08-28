#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
	int fD=creat("textFile.txt",0644);
	if(fD==-1){
		printf("Error creting a file\n");
		return 0;
	}
	printf("Value of file Descriptor = %d\n",fD);
	close(fD);
	return 0;
}
