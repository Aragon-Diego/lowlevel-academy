#include <stdio.h>
#include <stdbool.h>

#define MAX_EMPLOYEES 1000


union myunion_u {
	int x;
	char c;
	short s;
};

int main() {
	union myunion_u u;
	u.x = 0x41424344;
	printf("%hx %hhx\n", u.s, u.c);
}
