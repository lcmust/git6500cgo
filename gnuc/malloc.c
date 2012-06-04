#include <stdio.h>
#include <stdlib.h>

int *matvec(int *A, int *x, int n)
{
	int j;
	printf("\n is ok??\n");
	int *y = (int *)malloc(n * sizeof(int));
	memset(y, 0, n);
	for (j = 0; j < n; j++) {
		printf("\n is ok?? %d \t %d\n", A[j], x[j]);
		y[j] += A[j] * x[j];
	}
	return y;
}

int main()
{

	int array1[3] = { 7, 8, 9};
	int *p2;
	p2 = array1;
	int array2[] = {2,5,9};

	int *result = matvec(array1, array2, 3);
	printf("\n %d %d %d\n", result[0], result[1], result[2]);

	exit(0);
}
