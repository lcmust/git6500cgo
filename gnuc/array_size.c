#include <stdio.h>

int main(void)
{
	char arr[22] = {1};
	printf("The address of arr is %p\n", arr);
	printf("The address of arr+1 is %p\n", arr + 1);
	printf("The address of &arr+1 is %p\n", &arr + 1);

	int n;
	n = *(&arr + 1) - arr;
	printf("The size of arr is %d\n", n);
	printf("The size of '&arr + 1':%p - '&arr':%p = %d", &arr + 1,
		   &arr, &arr + 1 - &arr);
	int a1 = (int)(&arr + 1);
	int a2 = (int)(&arr);
	printf("*(&arr + 1) - arr = %d\n", a1  - a2);

	printf("*(&arr + 1) = %x\n", *(&arr + 1));
	printf("arr = %x\n", arr);

	printf("test: 0xff - 0xf0 = %d\n", 0xff - 0xf0);

	return 0;
}
