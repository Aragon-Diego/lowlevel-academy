#include <stdio.h>
#include <stdbool.h>
#define MAX_EMPLOYEES 1000

struct employee_t {
  int id;
  char firstname[64];
  char lastname[64];
  float income;
  bool isManager;
};

int main() {
  // struct employee_t Fred;
  // Fred.income = 100.00;
  // Fred.isManager = true;

  struct employee_t employees[MAX_EMPLOYEES] = {0};
  int i = 0;
  for(i = 0; i < MAX_EMPLOYEES; i++) {
    employees[i].income = 0;
    employees[i].isManager = false;
  }

  printf("%f\n", employees[10].income);
}