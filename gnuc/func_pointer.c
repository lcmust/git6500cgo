#include <stdio.h>
#include <stdlib.h>

int add(int x, int y);
int subtract(int x, int y);
int doath(int (*mathop)(int, int), int x, int y);

int add(int x, int y)
{
	return x + y;
}

int subtract(int x, int y)
{
	return x - y;
}

int domath(int (*mathop)(int, int), int x, int y)
{
	//return (*mathop)(x, y);
	return mathop(x, y);
}

int main()
{
	int a;
	a = domath(add, 10, 2);
	printf("Add gives: %d\n", a);

	int b;
	b = domath(subtract, 10, 3);
	printf("Subtract gives: %d\n", b);

	int (*mathopPtr)(int, int);
	mathopPtr = add;
	int c;
	c = domath(mathopPtr, 123, 45);
	printf("add gives: %d\n", c);

	exit(0);
}
