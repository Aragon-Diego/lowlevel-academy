#include <stdio.h>

struct Employee {
  char *name;
  int age;
};

int main(int argc, char **argv) {

    struct Employee emp = {
      .name = "Steve",
      .age = 42
    };

    printf("%s, aged %d years\n", emp.name, emp.age);

    return 0;

}