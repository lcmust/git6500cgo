/* name:learn_c_mylib.c
 * compil: gcc -g -Wall -shared -fPIC learn_c_mylib.c -o ./lib/liblearn_c_mylib.so
 */
#include <stdio.h>
int mylib_func1(void)
{
	printf("This is my lib func1<>\n");
	return 0;
}
