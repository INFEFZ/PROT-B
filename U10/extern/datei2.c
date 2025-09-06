#include <stdio.h>
#include "datei2.h"

// Definition der externen Variable (global)
int zahl;

// Definition der externen Funktion
void verdoppleZahl()
{
  // Zugriff auf die externe Variable
  zahl *= 2;
}
