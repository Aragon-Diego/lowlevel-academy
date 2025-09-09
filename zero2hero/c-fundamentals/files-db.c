#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

struct database_header_t {
  unsigned short version;
  unsigned short employees;
  unsigned int filesize;
};

int main( int argc, char* argv[]) {
  struct database_header_t head = {0};
  struct stat dbStat = {0};
  int fd = open("./my-db.db", O_RDONLY);
  if(fd == -1) {
    perror("open");
    return -1;
  }

  char *mydata = "hello there!\n";
  if (read(fd, &head, sizeof(head)) != sizeof(head)) {
    perror("read");
    close(fd);
    return -1;
  }
  printf("DB VERSION: %u\n", head.version);
  printf("DB NUM OF EMPLOYEES: %u\n", head.employees);
  printf("DB FILE SIZE: %u\n", head.filesize);
  
  if(fstat(fd, &dbStat) < 0) {
    perror("fstat");
    close(fd);
    return -1;
  }
  printf("DB dile length, reported by stat: %lld\n", dbStat.st_size);
  if(dbStat.st_size != head.filesize) {
    printf("GET OUTTA HERE YOU HACKER!\n");
    close(fd);
    return -2;
  }
  return close(fd);
}