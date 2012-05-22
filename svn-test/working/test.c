/* filename: test.c
 * date: 20120510-1000
 * author: chengl6500
 */
#include <stdio.h>
#include <stdlib.h>

void inplace_swap(int *x, int *y)
{
	*y = *x ^ *y;
	*x = *x ^ *y;
	*y = *x ^ *y;
}

void reverse_array(int a[], int cnt)
{
	int first;
	int last;
	for(first = 0, last = cnt -1; first < last; first++, last--)
		inplace_swap(&a[first], &a[last]);
}

void printf_int_array(int a[], int cnt)
{
	int i;
	i = 0;
	for(; i < cnt; i++)
		printf("%d\t%p\t%d\n", i, &a[i], a[i]);
}

void init_array(int a[], int cnt)
{
	int i;
	i = 0;
	for(; i < cnt; i++)
		a[i] = rand();
}

int main(int argc, char *argv[])
{
	int a[] = {22, 9, 29, 40, 1, 90};
	printf("total is %d\n", sizeof(a)/4 );

	printf_int_array(a, sizeof(a)/4 );
	reverse_array(a, sizeof(a)/4);
	printf_int_array(a, sizeof(a)/4 );	

	init_array(a, sizeof(a)/4 );
	printf_int_array(a, sizeof(a)/4 );	
	reverse_array(a, sizeof(a)/4);
	printf_int_array(a, sizeof(a)/4 );	
	return 0;
}
