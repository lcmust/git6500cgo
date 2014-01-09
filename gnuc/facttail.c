/* filename: facttail.c
 * author: chengl6500
 * from: mawc_ch3_p50
 */
#include <stdio.h>
#include <stdlib.h>

int facttail(int n, int a)
{
	if (n < 0)
		return 0;
	else if (n == 0)
		return 1;
	else if (n == 1)
		return a;
	else
		return facttail(n-1, n*a);
}

int main(int argc, char *argv[])
{
	int number;
	int result;

	if (argc > 1)
		number = atoi(argv[1]);
	else
		number = 5;

	result = facttail(number, number-1);
	if (result)
		printf("the facttail(%d, %d) result=%d\n",
			   number, number - 1, result);

	return 0;
}
