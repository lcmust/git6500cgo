#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

int main()
{

	char *addr1_p = "192.168.1.1";
	char *addr2_p;
	char addr2_[20];
	int addr1_int;
	int addr2_int;
	if (0 == inet_pton(AF_INET, addr1_p, &addr1_int)) {
		printf("\nerror of inet_pton\n");
	} else {
		printf("\naddr1_int:%x\n", addr1_int);
	}
	if (NULL != inet_ntop(AF_INET, &addr1_int, addr2_, sizeof(addr2_))) {
			printf("\naddr2_:%s\n", addr2_);
	}
	exit(0);
}
