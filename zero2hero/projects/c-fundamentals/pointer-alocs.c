#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 1000

struct employee_t {
  int id;
  int income;
  bool staff;
};

void init_employee(struct employee_t *e) {
  e->id = 0;
  e->income = 0;
  e->staff = false;
}

int main(){
  int n = 4;
  struct employee_t *employees = malloc(sizeof(struct employee_t)*n);
  if (employees == NULL) {
    printf("Allocator fail");
    return -1;
  }
  init_employee(&employees[0]);
  printf("%d\n", employees[0].income);
  free(employees);
  employees = NULL;
}