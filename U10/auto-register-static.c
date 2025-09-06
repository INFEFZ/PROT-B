#include <stdio.h>

// Teil 1: Berechnung der Summe
void berechneSumme()
{
  int a = 5; // auto int a = 5; ist implizit
  int b = 3; // auto int b = 3; ist implizit
  int summe = a + b;
  printf("Die Summe von %d und %d ist: %d\n", a, b, summe);
}

// Teil 2: Berechnung der Fakultät mit register
int fakultaet(int n)
{
  register int i;
  int ergebnis = 1;
  for (i = 1; i <= n; i++)
  {
    ergebnis *= i;
  }

  return ergebnis;
}

// Teil 3: Verwendung von static
void zaehler()
{
  static int aufrufe = 0; // Variable behält ihren Wert zwischen den Aufrufen
  aufrufe++;

  printf("Die Funktion zaehler() wurde %d mal aufgerufen.\n", aufrufe);
}

void main()
{
  // Teil 1: Aufruf der Summe-Funktion
  berechneSumme();

  // Teil 2: Aufruf der Fakultät-Funktion
  int n = 5;
  int fakultaetErgebnis = fakultaet(n);
  printf("Die Fakultät von %d ist: %d\n", n, fakultaetErgebnis);

  // Teil 3: Mehrmaliges Aufrufen der zaehler-Funktion
  zaehler();
  zaehler();
  zaehler();
}
