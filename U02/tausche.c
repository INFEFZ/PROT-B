#include <stdio.h>
// Funktion zum Vertauschen zweier Ganzzahlen
void tausche(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void main(void)
{
  // Deklaration und Initialisierung der Ganzzahlen
  int x = 10;
  int y = 20;

  // Ausgabe der Werte vor dem Funktionsaufruf
  printf("Vor dem Tausch: x = %d, y = %d\n", x);

  // Aufruf der Vertauschungsfunktion
  tausche(&x, &y);

  // Ausgabe der Werte nach dem Funktionsaufruf
  printf("Nach dem Tausch: x = %d, y = %d\n", x);
}
