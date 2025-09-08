#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 1000

struct employee_t {
  int id;
  int income;
  bool staff;
};

int init_employee(struct employee_t *e) {
  static int numEmployees = 0;
  numEmployees++;

  e->id = numEmployees;
  e->income = 0;
  e->staff = false;
  return numEmployees;
}

int main(){
  int n = 4;
  struct employee_t *employees = malloc(sizeof(struct employee_t)*n);
  if (employees == NULL) {
    printf("Allocator fail");
    return -1;
  }
  for(int i = 0; i < n; i++) {
    int id = init_employee(&employees[i]);
    printf("NEW employee, id:%d\n", id);
  }
  free(employees);
  employees = NULL;
}