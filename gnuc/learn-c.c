/* filename: learn-c.c
 * project: learn-c
 * date: 20120124-1238
 * author: chengl6500
 */
#include "learn-c.h"

int main(void)
{
	int c;
	while((c = getchar()) != EOF) {
		putchar(c);
	}

	mylib_func1();

	printf("\nEND\n");
	exit(0);
}
