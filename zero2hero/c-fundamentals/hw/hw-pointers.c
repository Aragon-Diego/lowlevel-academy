#include <stdio.h>

// something is wrong here :(
int swap( int *a, int *b) { // x10, x11
  int temp = *a; //10
  *a = *b; 
  //apuntador a = a valor del apuntador de b (20) 
  //apuntador en x10 = 20
  *b = temp;
  // apuntador de b = a int temp
  // apuntador en x11 = 10
  return 0;
}

int main() {
  int a = 10;
  int b = 20;
  swap(&a, &b);
  printf("a: %d, b: %d\n", a, b);
}