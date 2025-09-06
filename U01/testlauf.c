#include <stdio.h>

int fak(int n)
{
  if (n == 0)
    return 1;
  return n * fak(n - 1);
}

int main() { printf("%d", fak(4)); }