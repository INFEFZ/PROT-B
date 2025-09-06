#include <stdio.h>
#include "datei2.h"

int main()
{
  // Definition und Initialisierung der externen Variable
  zahl = 10;
  printf("Ursprünglicher Wert der Zahl: %d\n", zahl);

  // Aufruf der externen Funktion, die die externe Variable verwendet
  verdoppleZahl();
  printf("Verdoppelter Wert der Zahl: %d\n", zahl);

  return 0;
}
