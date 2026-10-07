#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

#define buf_size 1024

int main(int argc , char* argv[]){
	int fd;
	char *buf = "the great life";

	if(argc != 2){
		printf("error");
	}
	fd = open(argv[1],O_APPEND | O_WRONLY);
	if(fd == -1){
		printf("file can not open");
	}
	int offset = lseek(fd,0,SEEK_SET);
	int wrt = write(fd,buf,14);
	if(wrt == -1 ){
		printf("error in the write ");
	}
	return 0;
	
}
