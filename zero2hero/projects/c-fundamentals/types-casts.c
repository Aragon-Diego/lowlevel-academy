#include <stdio.h>

int main(int argc, char *argv[]) {
  unsigned int x = 4;
  int sx = (int)(x);

  unsigned int bigx = 0xfffffefe;
  short kindabig = (short) bigx;

  short short2 = -1;
  int wasAShort = (int) short2;

  float f = 3.14;
  int wasAFloat = (int)f;

  

}