#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdio.h>
#include<string.h>

int  buf_size  = 1024;

int count = 0;

static void fatal(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}
// copy the data to another file but it should be from 
// the end give the number of line to be copied.
int convertStrToInt(char* s){
	int length = strlen(s);
	int num = 0;
	int i = 0;
	while(i < length){
		int n = s[i] - '0';
		num = num*10 + n;
		i++;
	}
	return num;
}


int main(int argc , char* argv[]){
	int inputFd ;
	char buffer[buf_size];
	if(argc != 3 ){
		fprintf(stderr, "Usage: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	int N = convertStrToInt(argv[2]);

	inputFd = open(argv[1],O_RDONLY);
	if(inputFd == -1){
		fatal(argv[2]);
	}
	//find the size of the file 
	int offset = lseek(inputFd ,0,SEEK_END);
	
	int run = 0;
	int numread;
	struct arra *data; 
        int capacity = 0;
        
	if(offset < buf_size){
		buf_size = 0;
	}

	while((numread = pread(inputFd , buffer , buf_size , offset - buf_size) )>0){

		int curroffset = lseek(inputFd , 0 , SEEK_CUR);
		offset = lseek(inputFd, curroffset - buf_size , SEEK_CUR);
		if(offset <= -1){
			buf_size = 0;
			offset = curroffset;
			lseek(inputFd , 0 ,SEEK_SET);
		}


		
	}
	if(numread == -1){
		fatal("read");
	}



	

}
