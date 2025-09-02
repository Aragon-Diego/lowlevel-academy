#include <stdio.h>

#define MAX_ID 32

int main() {
  //int ids[MAX_ID];
  //int ids[] = {0,1,2};
  int ids[MAX_ID] = {0,1,2};
  printf("%d\n", ids[0]);
  ids[3]= 0x41;
  printf("%d\n", ids[3]);

  char mystr[] = {'h','e','l','l','o',0};
  printf("%s\n", mystr);
  char *myotherstr = "hello";
  printf("%s\n", myotherstr);
}