#include <stdio.h>
#include <stdlib.h>

union {
	int i;
	char x[4];
} a;

int main(void)
{
	a.x[0] = 257;
	a.x[1] = 0;
	a.x[2] = 1;
	a.x[3] = 0;

	printf("union a.i = %d\n", a.i);
	exit(0);
}
