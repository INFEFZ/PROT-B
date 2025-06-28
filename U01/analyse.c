#include <stdio.h>

/*
main - der Wert von x ist 5
f1 - der Wert von x ist 4
f2 - der Wert von x ist 7
main - der Wert von x ist 6
*/
int x = 5;

void function1(int *u)
{
  int x = 4;
  *u = 6;
  printf("f1 - der Wert von x ist %d\n", x);
}

void function2(int x)
{
  printf("f2 - der Wert von x ist %d\n", x);
}

int main(void)
{
  int z1, z2;

  printf("main - der Wert von x ist %d\n", x);

  function1(&x);
  function2(7);

  printf("main - der Wert von x ist %d\n", x);

  return 0;
}