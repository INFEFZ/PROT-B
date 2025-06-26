#include <stdio.h>

void main(void)
{
  int zahl1 = 1;

  // Block
  {
    int zahl2 = 2;
    printf("Zahl1: %d Zahl2: %d", zahl1, zahl2);
  }
}
