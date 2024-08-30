#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
void printOpenMode(int flags){
	int accessMode = flags & O_ACCMODE;
	if (accessMode == O_RDONLY){
        printf("read-only mode.\n");
   	}else if(accessMode == O_WRONLY){
        printf("write-only mode.\n");
    	}else if (accessMode == O_RDWR){
        printf("read-write mode.\n");
    	}else{
        printf("Unknown mode.\n");
    	}
}
int main(){
    	const char *fName = "f.txt"; 
	int fd = open(fName, O_RDONLY | O_CREAT, 0644);
    	if(fd < 0){
        printf("unable to create or open file\n");
        return 0;
	}
	int flags = fcntl(fd, F_GETFL);
	if (flags < 0){
	printf("There's an error while getting flags \n");
        close(fd);
        return 0;
	}
	printOpenMode(flags);
	close(fd);
	return 0;
}
