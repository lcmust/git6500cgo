#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int g_i = 10;

int *matvec(int *A, int *x, int n)
{
	int j;
	int *y = (int *)malloc(n * sizeof(int));
	memset(y, 0, n);
	for (j = 0; j < n; j++) {
		printf("\n is ok?? %d \t %d\n", A[j], x[j]);
		y[j] += A[j] * x[j];
	}
	return y;
}

int test1()
{
	g_i = 20;
	printf("in the test1: g_i = %d\n", g_i);
	return 0;
}

int main()
{

	printf("program begin:\n in the main: g_i = %d\n", g_i);
	test1();
	int array1[3] = { 7, 8, 9};
	int *p2;
	p2 = array1;
	int array2[] = {2,5,9};

	int *result = matvec(array1, array2, 3);
	printf("\n %d %d %d\n", result[0], result[1], result[2]);
	printf("program end:\n in the main: g_i = %d\n", g_i);

	exit(0);
}
