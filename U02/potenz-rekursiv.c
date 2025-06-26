#include <stdio.h>

int potenz(int x, int y)
{
  if (y == 0)
    return 1;
  return x * potenz(x, y - 1);
}

int main()
{
  int x, y;

  printf("Basis: ");
  scanf("%d", &x);

  printf("Exponent: ");
  scanf("%d", &y);

  printf("%d^%d = %d\n", x, y, potenz(x, y));

  return 0;
}
