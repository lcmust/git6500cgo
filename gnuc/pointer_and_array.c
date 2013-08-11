#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int numbers[5] = {1, 2, 3, 4, 5};

	int *ptr1 = numbers;
	int val1 = numbers[0];

	int *ptr2 = &numbers[0];
	int val2 = *(&numbers[0]);

	int *ptr3 = numbers + 0;
	int val3 = *(numbers + 0);

	printf("*ptr1 = %p\n", (void *)ptr1);
	printf("*ptr2 = %p\n", (void *)ptr2);
	printf("*ptr3 = %p\n", (void *)ptr3);

	printf("val1 = %d\n", val1);
	printf("val2 = %d\n", val2);
	printf("vla3 = %d\n", val3);

	exit(0);

}
