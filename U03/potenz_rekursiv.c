#include <stdio.h>

float reku(float alpha, float beta, int hoch)
{
  if (hoch == 0)
  {
    return 1.0;
  }
  else
  {
    return (alpha + beta) * reku(alpha, beta, hoch - 1);
  }
}

void eingabe(float *ptr_alpha, float *ptr_beta, int *ptr_hoch)
{
  printf("\nGib einen Wert fuer a ein [float]: ");
  scanf("%f", ptr_alpha);

  printf("\nGib einen Wert fuer b ein [float]: ");
  scanf("%f", ptr_beta);

  printf("\nGib einen positiven Wert fuer n ein [int]: ");
  scanf("%d", ptr_hoch);
}

void main(void)
{
  float a;

  float b;
  float resultat_rekursiv;
  int n;

  eingabe(&a, &b, &n);
  printf("\n\na = %.2f, b = %.2f, n = %d", a, b, n);

  resultat_rekursiv = reku(a, b, n);
  printf("\nErgebnis rekursiv: %14.6f", resultat_rekursiv);
}
