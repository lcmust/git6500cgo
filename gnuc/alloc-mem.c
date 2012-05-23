#include <stdlib.h>
#include <stdio.h>
#define NUM 20

int alloc_mem_1(int num)
{
//	int *q;
	return (int)malloc(num);
//	return (int)q;
}

int init_mem(int *tmp, int num)
{
	int i;
	int *p1;
	p1 = tmp;
	for(i = 0; i < num; i++) {
		*(p1 + i) = i;
//		printf("%d\t", p1[i]);
	}
	return 0;
}

int print_mem(const int *tmp, int num)
{
	int i;
	for(i = 0; i < num; i++) {
		printf("%d\t", tmp[i]);
	}
	return 0;
}

int main(void)
{
	int i;
	int handle;

	int *p1 = NULL;
	int *p2 = NULL;
	int *p3 = NULL;
	printf("1: test of alloc_mem_1() \n");
	handle = alloc_mem_1(NUM * sizeof(int));
	p1 = (int*)handle;
	printf("\naddress of:%p (no init)\n", (int)p1);
	print_mem(p1, NUM);

	init_mem(p1, NUM);
	printf("\ninit....p1\n");
	print_mem(p1, NUM);

	printf("\n");
	free(p1);
	p2 = (int *)alloc_mem_1(NUM * sizeof(int));
	printf("\ninit....p2\n");
	print_mem(p1, NUM);
	return 0;
}
