#include <stdio.h>
#include <stdlib.h>

int split(int sum, int *result) {
	result[0] = sum * 4 / 9;
	result[1] = sum - result[0];
}

int main()
{
	int a1[2];
	split(17, a1);
	printf("%d\t%d\n", a1[0], a1[1]);
	return 0;
}
