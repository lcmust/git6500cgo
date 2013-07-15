#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	union union_1 {
		short s;
		char c[sizeof(short)];
	} un;
	un.s = 0x0102;
//	print("%s:",CPU_VENDOR_OS);
	if (sizeof(short) == 2) {
		if (un.c[0] == 1 && un.c[1] == 2) {
			printf("\n%d\t%d\n", un.c[0], un.c[1]);
			printf("big-endian\n");
		}
		else if (un.c[0] == 2 && un.c[1] == 1) {
			printf("\n%d\t%d\n", un.c[0], un.c[1]);
			printf("little-endian\n");
		}
		else
			printf("unknown\n");
	} else
		printf("sizeof(short) == %d\n", sizeof(short));
	union union_1 un2 = {
		.s = 0x0304
	};
	printf("\n%d\t%d\n", un2.c[0], un2.c[1]);

	exit(0);
}
