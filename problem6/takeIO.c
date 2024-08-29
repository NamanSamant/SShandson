#include<unistd.h>
#include<fcntl.h>
int main()
{
	char buff[512];
	ssize_t bytesR;
	while((bytesR = read(STDIN_FILENO, buff, 512)) > 0){
		write(STDOUT_FILENO, buff, bytesR);
	}
	return 0;
}
