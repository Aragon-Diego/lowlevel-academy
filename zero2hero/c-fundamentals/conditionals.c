#include <stdio.h>

int main() {
  int temp;
  printf("what temp?");
  scanf("%d", &temp);
  if(temp >= 70) {
    printf("hot\n");
  } else if (temp >= 30 && temp <70) {
    printf("mid\n");
  } else {
    printf("cold\n");
  }
}