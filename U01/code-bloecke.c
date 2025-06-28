#include <stdio.h>

void ausgabe(void)
{
  // welche Variablen stehen zur Verfügung?
  
  int lokaleZahl = 10;

  printf("Lokale Zahl ist: %d", lokaleZahl);
}

void main(void)
{
  int zahl1 = 1;

  // Funktion wird augerufen
  ausgabe();

  // Ein neuer Block beginnt
  {
    int zahl2 = 2;

    printf("Zahl1: %d, Zahl2: %d", zahl1, zahl2);
  }

  // Steht die Variable zahl1 noch zur Verfügung?
  // Steht die Variable zahl2 noch zur Verfügüng?
  
  printf("Ende");
}
