#include <stdio.h>
#include <stdlib.h>

void str_append(char *str_append, char *str_from)
{
	while (*(str_append++) != '\0');
	str_append--;
	while (*(str_from) != '\0')
		*(str_append++) = *(str_from++);
	*str_append = '\0';
	return;
}

int main(void)
{
	char name[40] = "a1b2c3";
	char *address = "long jin road 23";
	printf("name: %s\n", name);
	printf("address: %s\n", address);
	str_append(name, address);
	printf("name: %s\n", name);
	printf("address: %s\n", address);
	str_append(name, address);
	printf("name: %s\n", name);
	printf("address: %s\n", address);

	return 0;
}
