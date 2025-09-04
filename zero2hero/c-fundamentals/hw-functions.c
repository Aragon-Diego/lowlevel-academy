#include <stdio.h>

int add_two_numbers(int a, int b) {
  return a + b;
}

int main() {
  int other_num = add_two_numbers(2, 3);
  printf("%d", other_num);
}