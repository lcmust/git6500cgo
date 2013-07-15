#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	union {
		int s;
		char c[sizeof(int)];
	} un;
	un.s = 0x01020304;
//	print("%s:",CPU_VENDOR_OS);
	if (sizeof(int) == 4) {
		if (un.c[0] == 1 && un.c[1] == 2 && un.c[2] == 3 && un.c[3] == 4)
			printf("big-endian\n");
		else if (un.c[0] == 4 && un.c[1] == 3 && un.c[2] == 2 && un.c[3] == 1)
			printf("little-endian\n");
		else
			printf("unknown\n");
	} else
		printf("sizeof(int) == %d\n", sizeof(int));

	printf("un.c[0]  == %d\n", un.c[0]);
	printf("un.c[1]  == %d\n", un.c[1]);
	printf("un.c[2]  == %d\n", un.c[2]);
	printf("un.c[3]  == %d\n", un.c[3]);
	printf("sizeof(int) == %d\n", sizeof(int));
	printf("sizeof(short) == %d\n", sizeof(short));
	exit(0);
}
