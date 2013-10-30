/* filename: learn_c_mylib.c
 * compil: gcc -g -Wall -shared -fPIC learn_c_mylib.c -o ./lib/liblearn_c_mylib.so
 * update: 20131008-1445
 */
#include <stdio.h>
#include "learn_c_mylib.h"
#include "show_bytes.h"
int mylib_func1(void)
{
	printf("This is my lib func1<<<<<<<<<\n");
	int a, a2;
	int shift_no;
	a = 0;
	printf("please input a digital:");
	scanf("%d", &a);
	printf("shift no:");
	scanf("%d", &shift_no);
	printf("your input is:%d, will left shift:%d\n", a, shift_no);
	show_bytes((byte_pointer)&a, sizeof(a));
	a2 = a << shift_no;
	printf("%d left shift 5 is:%d\n", a, a2);
	show_bytes((byte_pointer)&a2, sizeof(a2));
	printf("This is my lib func1>>>>>>>>>>\n");
	return 0;
}
