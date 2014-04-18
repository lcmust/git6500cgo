#include <stdio.h>
#include <string.h>

struct str {
	int len;
	char s[0];
};

struct foo {
	struct str *a;
};

int main(int argc, char **argv)
{
	int len = 10;
	struct str *str_line  = (struct str *)malloc(sizeof(struct str) + 10);
	str_line->len = len;
	memset(str_line->s, 'a', len);

	return 0;
}
