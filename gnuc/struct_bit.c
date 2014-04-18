#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>

struct fbit {
	unsigned flag:1;
	unsigned ex:7;
	unsigned dec:24;
};

int main(int argc,  char *argv[])
{
	// int f = atoi(argv[1]);
	// float f = atoi(argv[1]);
	float f = 2.34;
	struct fbit fbit_test;
	fbit_test = *(struct fbit *)&f;
	printf("%x %x %x\n", fbit_test.flag, fbit_test.ex, fbit_test.dec);
	printf("%d %d %d\n", fbit_test.flag, fbit_test.ex, fbit_test.dec);
	fbit_test.flag = 2;
	fbit_test.ex = 3;
	fbit_test.dec = 4;
	printf("%d %d %d\n", fbit_test.flag, fbit_test.ex, fbit_test.dec);
	printf("%f\n", f);
	return 0;
}

