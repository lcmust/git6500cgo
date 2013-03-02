#include <stdlib.h>
#include <stdio.h>
#define NUM 20

int alloc_mem_1(int num)
{
//	int *q;
	return (int)malloc(num);
//	return (int)q;
}

int alloc_mem_2(int **tmp, int num)
{
	*tmp = malloc(num);
	return 0;

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
	int *p_tmp;
	p_tmp = tmp;
	for(i = 0; i < num; i++) {
		printf("%d\t", *((p_tmp) +i ) );
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
	printf("address of:%p (no init)\n", (int)p1);
	printf("\nprint....p1\n");
	print_mem(p1, NUM);
	printf("\ninit....p1......");
	init_mem(p1, NUM);
	printf("\nprint....p1\n");
	print_mem(p1, NUM);
//	free(p1);
	alloc_mem_2(&p2, (NUM * sizeof(int)));
	printf("\nprint....p2\n");
	print_mem(p2, NUM);
	printf("\ninit....p2......");
	init_mem(p2, NUM);
	printf("\nprint....p2\n");
	print_mem(p2, NUM);

	free(p2);
	return 0;
}
