/* filename: learn_c_mylib.c
 * compil: gcc -g -Wall -shared -fPIC learn_c_mylib.c -o ./lib/liblearn_c_mylib.so
 * update: 20131008-1445
 */
#include <stdio.h>
#include "show_bytes.h"
#include "learn_c_mylib.h"

int mylib_func1(void)
{
	printf("(mylib_func1)__________\n");
	int a, a2, shift_no;
	a = 0;
	a2 = 0;
	shift_no = 0;
	
	printf("please input a digital:");
	scanf("%d", &a);
	printf("please input a digital of shift:");
	scanf("%d", &shift_no);
	show_bytes((byte_pointer)&a, sizeof(a));
	a2 = a << shift_no;
	printf("%d left shift %d is:%d\n", a, shift_no, a2);
	show_bytes((byte_pointer)&a2, sizeof(a2));
	printf("(mylib_func1)===============\n");
	return 0;
}
