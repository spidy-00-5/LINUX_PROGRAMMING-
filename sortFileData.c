#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#define buf_size 1024

// this finction sorts the data in the file the data is the random number
// in the binary formate and the output is the sorted in the increasing order
//int fstat(int fd, struct stat *st)
//struct stat st;
//st.st_size
int compar(const void* a , const void* b){
	int x = *(int*)a;
	int y = *(int*)b;
	return (x > y) - (x < y); 
}
struct arr {
	int start;
	int length;
};
int main(int argc , char* argv[]){
	int inputFd, outputFd;
	int *num = malloc(buf_size);

	if(argc != 3 ){
		printf("invalid argument");
		return 0;
	}
	inputFd = open(argv[1] , O_RDONLY);
	if(inputFd == -1){
		printf("could not open intput file");
		return 0;
	}
	struct stat st;
	int value = fstat(inputFd , &st);
	int size = st.st_size;
	if(size % 4 != 0){
		printf("curroupt file");
		return 0;
	}
	outputFd = open(argv[2],O_WRONLY| O_CREAT | O_TRUNC);
	if(outputFd == -1){
		printf("could not open output file");
		return 0;
	}
	int tempFd;
	char template[] = "/tmp/tempfileXXXXXX";
	tempFd = mkstemp(template);
	if(tempFd == -1){
		printf("tempfile is not created");
		return 0;
	}
	int readnum;
	struct arr *arry = NULL;
	int run = 0;
	int capacity = 0;
	ssize_t = tmp_total = 0
	while((readnum = read(inputFd , num ,buf_size)) > 0){
		run++;
		qsort(num , readnum/sizeof(int) ,sizeof(int),compar);
		struct arr *newarr = realloc(arry , run * sizeof(struct arr));
	        newarr[run-1].start = tmp_total;
		newarr[run-1].length = readnum;
		arry = newarr;

		ssize_t  wrt = write(tempFd , num , readnum);
		if(wrt == -1){
			printf("error in writing to file");
		}
		tem_total += wrt;
	}
	// i got the tempfile with sorted the run;
	return 0;

}








