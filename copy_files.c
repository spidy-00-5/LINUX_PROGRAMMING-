#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#define buf_size 1024


// copy the data from the one file to another file if the second file
// contain data it is erased and old file data is store;


int main(int argc , char* argv[]){
    int inputFd,outputFd,openFlags;
    mode_t fileperms;
    int numread;
    char buf[buf_size];

    if(argc != 3 || strcmp(argv[1] ,"-help") == 0){
        printf("error1");
    }
    openFlags = O_CREAT | O_WRONLY | O_TRUNC;
    fileperms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | 
                S_IROTH |S_IWOTH;
    outputFd = open(argv[2],openFlags,fileperms);
    if(outputFd == -1){
        printf("error2");
    }
    inputFd = open(argv[1],O_RDONLY);
    if(inputFd == -1){
        printf("error3");
    }

    while((numread = read(inputFd , buf ,buf_size)) > 0)
        if(write(outputFd,buf,numread) != numread)
            printf("could not write the buffer ");
    if(numread == -1){
        printf("error4");
    }
    if(close(inputFd) == -1){
        printf("error5");
    }
    if(close(outputFd) == -1){
        printf("error6");
    }
    exit(0);

}

