#include<stdio.h>
#include <stdlib.h>

int *lvret(void) {
    int ret = 5;
    return &ret;
}

void mod(void) {
    int a = 7;
}

int main(void)
{
    int *p = lvret();
    mod();
    printf("%d\n",*p);
}
