#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//#include <myerro.h>
//#include "ourhdr.h"

char buf1[] ="abcdefghij";
char buf2[] ="ABCDEFGHIJ";

int main(void)
{
	int fd;
	if((fd=creat("file.hole",0777))<0)
		printf("creat error");
	if(write(fd,buf1,10)!=10)
		printf("buf1 write error");
	if(lseek(fd,40,SEEK_SET)==-1)
		printf("lseek error");
	if(write(fd,buf2,10)!=10)
		printf("buf2 write error");
	exit(0);
}
