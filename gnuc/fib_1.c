#include <stdio.h>

int fib(int n)
{
	if (n < 2)
		return n;
	else
		return fib(n - 1) + fib(n - 2);
}

int main(void)
{
	int result = fib(41);
	if (result)
		printf("the fib(41) result= %d\n", result);
	return 0;
}
