#include <stdio.h>
#include <stdbool.h>

struct employee_t {
  int id;
  int income;
  bool staff;
};

void initialize_employee(struct employee_t *e){
  e->id=0;
  e->income=0;
  e->staff=false;
}

int main() {
  struct employee_t Ralph;
  initialize_employee(&Ralph);
  printf("%d\n", Ralph.income);
}