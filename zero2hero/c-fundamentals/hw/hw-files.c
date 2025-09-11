#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

void print_the_flag() {
  int fd = open("/tmp/flag", O_RDWR);
  printf("%d\n", fd);
  char buff[100];
  if(read(fd, buff, sizeof(buff)) == -1) {
    perror("read");
    close(fd);
    return;
  }
  printf("%s\n", buff);
  close(fd);
  return;
}

int main() {
  print_the_flag();
}