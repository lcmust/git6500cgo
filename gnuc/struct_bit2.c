#include <stdio.h>

struct sbit {
	int a:3;
	int b:2;
	int c:3;
};

int main(int argc,  char *argv[])
{
	struct sbit s;
	char *c = (char *)&s;
	*c = 0x99;

	printf("s.a: %d, s.b: %d, s.c: %d\n", s.a, s.b, s.c);
	printf("s.a: %x, s.b: %x, s.c: %x\n", s.a, s.b, s.c);
	return 0;
}

