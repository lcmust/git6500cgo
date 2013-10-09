/* filename: learn_c_mylib.c
 * compil: gcc -g -Wall -shared -fPIC learn_c_mylib.c -o ./lib/liblearn_c_mylib.so
 * update: 20131008-1445
 */
#include <stdio.h>
#include "learn_c_mylib.h"
int mylib_func1(void)
{
	printf("This is my lib func1<>\n");
	return 0;
}
