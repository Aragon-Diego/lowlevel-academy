#include <stdio.h>

// Global scope

int g_NumPersons = 0;

void some_other_function() {
  int personID = 1;
}

int main() {
  int personID = 0;
  int person2ID = personID + 1;
  personID += 1;
  {
    int personID = 100;
    personID += 1;
  }
  //cahr
  //float
}