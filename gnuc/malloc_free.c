#include<stdio.h>
#include <stdlib.h>

int *lvret(void) {
    int ret = 5;
    return &ret;
}

int main(void) {
    int *p = lvret();
    printf("%d\n",*p);
}
