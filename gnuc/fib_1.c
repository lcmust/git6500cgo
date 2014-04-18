/* filename: fib_1.c
 * author: chengl6500
 * compile: gcc -g -Wall fib_1.c -o ./bin/fib_1
 * update:
 */
#include <stdio.h>
#include <stdlib.h>

int fib(int n)
{
	if (n < 2)
		return n;
	else
		return fib(n - 1) + fib(n - 2);
}

int main(int argc, char *argv[])
{
    int number;
    int result;

    if (argc > 1)
        number = atoi(argv[1]);
    else
        number = 5;

	result = fib(number);

	if (result)
		printf("the fib(%d) result= %d\n", number, result);

	return 0;
}

int test()
{
	int a;
	a = 0;
	for (a = 0; a < 100; a++) {
		;
	}
	return a;
}
