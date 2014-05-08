#include <stdio.h>

void main(int argc, char *argv[])
{
	FILE *fi, *fo;
	char *cp;
	int c;

	if ((cp = argv[1]) && *cp != '\0') {
		if ((fi = fopen(argv[2], "rb")) != NULL) {
			if ((fo = fopen(argv[3], "wb")) != NULL) {
				while ((c = getc(fi)) != EOF) {
					if (! *cp) {
						cp = argv[1];
						printf("\tNEW:%c", *cp);
					} else {
						printf("\t%c", *cp);
					}
					c ^= *(cp++);
					putc(c, fo);
				}
				printf("\n%s -> %d", argv[3], fileno(fo));
				fclose(fo);
			}
			printf("\n%s -> %d", argv[2], fileno(fi));
			fclose(fi);
		}
	}
}
	
