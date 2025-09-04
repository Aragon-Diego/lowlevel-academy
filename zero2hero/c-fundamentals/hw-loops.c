#include <stdio.h>

void count_evens_to_1000(void) {
  int i = 0;
  int limit = 1000;
  for(i = 0; i < limit; i++) {
    if(i % 2 == 0) {
      printf("%d\n", i);
    }
  }
}

int main() {
  count_evens_to_1000();
}