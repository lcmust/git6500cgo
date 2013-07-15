#include <stdio.h>
#include <stdlib.h>

unsigned short csum(unsigned short *buffer, int size)
{
	register long cksum  = 0;
	while (size > 1) {
		cksum += *buffer++;
		size -= sizeof(unsigned short);
	}

	if (size > 0)
		cksum += *(unsigned char *)buffer;
	while (cksum >> 16)
		cksum = (cksum & 0xffff) + (cksum >> 16);
	//	printf("\t<%d>", cksum);

	return ~cksum;
}

int main(void)
{
	char *name1 = "123";
	char *name2 = "124";
	char *name3 = "2233";
	char *name4 = "3233";

	unsigned short tmp1;
	unsigned short tmp2;
	unsigned long test1 = 1234;
	//	printf("\t%x\t%x\t%x\t%x\t%x", test1, (test1 & 0xffff), (test1 & 0xffff + test1 >> 16), test1 >> 16, test1 >> 8);
	//	printf("\n%x", 0x5678 + 0x1234);

	printf("\n	    %s:%d\n", name1, csum(name1, sizeof(name1)));
	printf("\n	    %s:%d\n", name2, csum(name2, sizeof(name2)));
	printf("\n	    %s:%d\n", name3, csum(name3, sizeof(name3)));
	printf("\n	    %s:%d\n", name4, csum(name4, sizeof(name4)));

	printf("\n");
	exit(0);
}
