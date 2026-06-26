#include <stdio.h>

void ausgabe(void)
{
  int lokaleZahl = 10;

  printf("Lokale Zahl ist: %d", lokaleZahl);
}

void main(void)
{
  int zahl1 = 1;

  {
    int zahl2 = 2;

    printf("Zahl1: %d, Zahl2: %d", zahl1, zahl2);
  }
}