/* filename: learn_c.h
 * project: learn_c
 * date: 20120124-1240
 * author: chengl6500
 */
#ifndef LEARN_C_H
#define LEARN_C_H

#define Free(ptr) \
	do { \
	if (NULL != ptr) \
		free(ptr); \
	ptr = NULL; \
	} while (0)

struct name_st {
	char *name;
	int age;
	char *birthday;
	char *other;
};

int mylib_func1(void);

#endif  // LEARN_C_H
