#include <stdio.h>

long counter = 0;

void func(void)
{
  int c[1024];

  counter++;
  printf("counter=%ld\n", counter);
  func();
}

int main(void)
{
  printf("\n\n\n");
  func();
  printf("\n\n\n");

  return 0;
}
