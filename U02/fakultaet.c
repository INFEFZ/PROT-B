#include <stdio.h>

int fakultaet(int n)
{
  if (n <= 1)
    return 1;
  return n * fakultaet(n - 1);
}

int main()
{
  int n;

  printf("Geben Sie eine Zahl ein: ");
  scanf("%d", &n);

  printf("%d! = %d\n", n, fakultaet(n));
  return 0;
}