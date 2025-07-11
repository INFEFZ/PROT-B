#include <stdio.h>

void spiegle(void)
{
  int c = getchar();

  if (c != '\n')
  {
    spiegle();
  }

  putchar(c);
}

int main(void)
{
  printf("\n\n\n");
  spiegle();
  printf("\n\n\n");

  return 0;
}
