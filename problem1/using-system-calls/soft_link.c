#include<unistd.h>
#include<stdio.h>
int main()
{
	if(symlink("naman.txt", "naman-slink2")==0)
	{
		printf("Created\n");
	}
	else
	{
		perror("Error while Creating");
	}
	return 0;
}
