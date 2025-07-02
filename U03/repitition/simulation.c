#include <stdio.h>

void einlesen(float *, float *); /* Funktionsprototyp */

int main(void)
{
  float a, b;

  einlesen(&a, &b);

  printf("\na ist %6.2f", a);
  printf("\nb ist %6.2f", b);

  return 0;
}

void einlesen(float *x, float *y)
{
  printf("\nGib einen float-Wert fuer a ein: ");
  scanf("%e", x);

  printf("\nGib einen float-Wert fuer b ein: ");
  scanf("%e", y);
}
