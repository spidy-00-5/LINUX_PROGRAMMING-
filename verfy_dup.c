#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd;
  fd = open(argv[1], O_RDWR | O_APPEND | O_SYNC);
  if (fd == -1) {
    printf("need a file to open ");
  } else {
    int newfd = dup(fd);

    int flag1 = fcntl(fd, F_GETFL);
    int flag2 = fcntl(newfd, F_GETFL);

    int offset1 = lseek(fd, 0, SEEK_CUR);
    int offset2 = lseek(newfd, 0, SEEK_CUR);

    if (offset1 != -1 && offset2 != -1) {
      if (offset1 == offset2)
        printf("both the offset are same\n");
    }
    int fd2 = open(argv[1], O_RDONLY);
    int offset3 = lseek(fd, 5, SEEK_CUR);

    offset1 = lseek(fd, 0, SEEK_CUR);
    offset2 = lseek(newfd, 0, SEEK_CUR);

    if (offset3 != -1 && offset2 != -1) {
      if (offset3 == offset2)
        printf("both the offset are same\n");
      else
	      printf("both offset are different ");
    }

    int offset4 = lseek(fd2, 0, SEEK_CUR);

    if (offset4 != -1){
      if (offset3 == offset4)
        printf("both the offset points to the same offset \n");
      else
        printf("both the offset are different \n");
    }

    if (flag1 & O_SYNC && flag2 & O_SYNC) {
      printf("both the have O_SYCN \n");
    }
    if (flag1 & O_APPEND && flag2 & O_APPEND) {
      printf("both the have O_APPEND\n");
    }
    int flag3 = fcntl(fd2, F_GETFL);

    if (flag1 == flag3) {
      printf("both have the same flag\n");
    } else {
      printf("both are differnt\n");
    }
  }

  return 0;
}
