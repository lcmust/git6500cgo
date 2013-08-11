#include <stdio.h>
#include <stdlib.h>

void swap(int *nums);

void swap(int *nums)
{
	int tmp = *(nums);
	int *next = nums + 1;
	*nums = *next;
	*next = tmp;
}

int main(void)
{
	int nums[3] = {1, 2};
	printf("before swap nums[0] = %d\n", nums[0]);
	printf("before swap nums[1] = %d\n", nums[1]);

	swap(nums);
	printf("after swap nums[0] = %d\n", nums[0]);
	printf("after swap nums[1] = %d\n", nums[1]);

	exit(0);
}
