#include<sys/types.h>
#include<sys/stat.h>
int main(){
	mkfifo("fyfo(using-sys-call)",0666);
	return 0;
}
