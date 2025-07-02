#include <stdio.h>

float iter(float, float, int); /* Funktionsprototyp */

void eingabe(float *ptr_alpha, float *ptr_beta, int *ptr_hoch)
{
  printf("\nGib einen Wert fuer a ein [float]: ");
  scanf("%f", ptr_alpha);

  printf("\nGib einen Wert fuer b ein [float]: ");
  scanf("%f", ptr_beta);

  printf("\nGib einen positiven Wert fuer n ein [int]: ");
  scanf("%d", ptr_hoch);
}

int main(void)
{
  float a;
  float b;
  float resultat_iterativ;
  int n;

  eingabe(&a, &b, &n);
  printf("\n\na = %.2f, b = %.2f, n = %d", a, b, n);

  resultat_iterativ = iter(a, b, n);
  printf("\nErgebnis iterativ: %14.6f", resultat_iterativ);
  return 0;
}

float iter(float alpha, float beta, int hoch)
{
  float result = 1.0;
  int i;

  for (i = 0; i < hoch; i++)
  {
    result *= (alpha + beta);
  }

  return result;
}
