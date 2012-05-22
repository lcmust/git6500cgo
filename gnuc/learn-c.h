/* filename: learn-c.h
 * project: learn-c
 * date: 20120124-1240
 * author: chengl6500
 */
#include <stdio.h>
#include <stdlib.h>

struct name_st {
	char *name;
	int age;
	char *birthday;
	char *other;
};

int mylib_func1(void);
