#include <stdio.h>

// something is wrong here :(
int swap( int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
  return 0;
}

int main() {
  int a = 10;
  int b = 20;
  swap(&a, &b);
  printf("a: %d, b: %d\n", a, b);
}