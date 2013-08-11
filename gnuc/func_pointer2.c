#include <stdio.h>
#include <stdlib.h>

void add(char *name, int x, int y);
void add(char *name, int x, int y)
{
  printf("%s gives: %d\n", name, x + y);
}

int main()
{
  void (*add1Ptr)(char *, int, int) = add;
  void (*add2Ptr)(char *, int, int) = *add;
  void (*add3Ptr)(char *, int, int) = &add;
  void (*add4Ptr)(char *, int, int) = **add;
  void (*add5Ptr)(char *, int, int) = ***add;

  void (*something)() = add;
  something("aaa", 3, 4);
  
  (*add1Ptr)("add1Ptr", 10, 2);
  (*add2Ptr)("add2Ptr", 10, 2);
  (*add3Ptr)("add3Ptr", 10, 2);
  (*add4Ptr)("add4Ptr", 10, 2);
  (*add5Ptr)("add5Ptr", 10, 2);

  add1Ptr("add1PtrFunc", 10, 2);
  add2Ptr("add2PtrFunc", 10, 2);
  add3Ptr("add3PtrFunc", 10, 2);
  add4Ptr("add4PtrFunc", 10, 2);
  add5Ptr("add5PtrFunc", 10, 2);

  printf("func of add's address is: %p\n", add);
  printf("func of add's address is: %p\n", &add);
  printf("func of add's address is: %p\n", *add);
  printf("func of add's address is: %p\n", **add);
  printf("func of add's address is: %p\n", ***add);
  
  exit(0);
}
