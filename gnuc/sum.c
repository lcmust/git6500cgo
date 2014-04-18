// sum.c
#include <stdio.h>

int sum(int a, int b)
{
	int c;
	c = a + b;
	return c;
}

int main()
{
	int x, y, z;
	printf("\nEnter the first number:");
	scanf("%d", &x);
	printf("\nEnter the second number:");
	scanf("%d", &y);
	z = sum(x, y);
	printf("The sum is %d\n\n", z);

	return 0;
}


int abc()
{
	int a;
	int b;
	a = 10;
	b = 20;
	return a + b;
}
