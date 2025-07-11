#include <stdio.h>

void verdopple(int **ptr)
{
  **ptr *= 2;
}

int main()
{
  int a = 25;
  int *p1 = &a;
  int **p2 = &p1;

  // Ausgaben
  printf("Direkter Wert von a: %d\n", a);
  printf("Wert über *p1: %d\n", *p1);
  printf("Wert über **p2: %d\n", **p2);

  printf("Adresse von a: %p\n", (void *)&a);
  printf("Adresse von p1: %p\n", (void *)&p1);
  printf("Adresse von p2: %p\n", (void *)&p2);

  // Funktion aufrufen
  verdopple(p2);

  printf("Neuer Wert von a nach Verdopplung: %d\n", a);

  return 0;
}
