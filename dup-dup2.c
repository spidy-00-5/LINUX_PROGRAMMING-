#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int dup2_fcntl(int fd, int newfd) {
  if (newfd < 0)
    return -1;
  if (fcntl(fd, F_GETFL) == -1)
    return -1;
  if (fd == newfd)
    return newfd;

  // find if thre is already a filedesc with newfd;
  if (fcntl(newfd, F_GETFL) != -1)
    close(newfd);

  return fcntl(fd, F_DUPFD, newfd);
}

int main(int argc, char *argv[]) {
  int fd1;
  if (argc == 1) {
    printf("no file");
  } else {
    fd1 = open(argv[1], O_RDONLY);
    if (fd1 == -1) {
      printf("error in opening the file");
    }
    int fd2 = fcntl(fd1, F_DUPFD, 0); // this is similar to dup
    if (fd2 == -1) {
      printf("error in the dup fun ");
    }
    else printf("%d",fd2);

    int fd3 = dup2_fcntl(fd1, 5);

    if (fd3 == -1)
      printf("can not be done ");
    else {
      printf("%d", fd3);
    }
  }
  return 0;
}
