/****
   filename: static_times_char_in_string.c
   description: static how many times of every char in a string!
   input: a string
   output: every char, number(times)
   return: error(-1) / default(0)
   date: 20121228-1300
 ****/
#include <stdio.h>
#include <stdlib.h>

#define LEN 128
int out[LEN] = {0};

void calculate__(const char *str)
{
	const char *p = str;
	if (!p) {
		return;
	}
	while (*p) {
		out[(int)*p] += 1;
		p++;
	}
}

void showRs__(int *a, int len)
{
	int i = 0;
	int j = 0;
	for (; i < LEN; i++) {
		if (a[i] != 0) {
			j++;
			if (!((i + 1) % 8)) {
				putchar('\n');
			}
			printf("%x(%c) -> %d !", i, i, a[i]);
		}
	}
}

int main(int  argc, char **argv)
{
	if (argc < 2) {
		printf("Please input a string!\n");
		exit(-1);
	}
	calculate__(argv[1]);
	showRs__(out, LEN);
	return 0;
}
