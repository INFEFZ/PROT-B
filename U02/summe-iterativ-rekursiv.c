#include <stdio.h>

// Iterative Funktion zur Berechnung der Summe der ersten n natürlichen Zahlen
int summe_iterativ(int n)
{
  int summe = 0;
  for (int i = 1; i <= n; ++i)
  {
    summe += i;
  }

  return summe;
}

// Rekursive Funktion zur Berechnung der Summe der ersten n natürlichen Zahlen
int summe_rekursiv(int n)
{
  if (n == 0)
  {
    // Basisfall: Die Summe von 0 ist 0
    return 0;
  }
  else
  {
    // Rekursiver Aufruf
    return n + summe_rekursiv(n - 1);
  }
}

void main(void)
{
  int n;

  // Einlesen einer Ganzzahl vom Benutzer
  printf("Geben Sie eine Ganzzahl ein: ");
  scanf("%d", &n);

  // Überprüfen, ob die eingegebene Zahl negativ ist
  if (n < 0)
  {
    printf("Die Summe der ersten n natürlichen Zahlen ist für negative Zahlen nicht definiert.\n");
  }
  else
  {
    // Berechnung und Ausgabe der Summe (iterativ)
    int resultat_iterativ = summe_iterativ(n);
    printf("Iterative Lösung: Die Summe der ersten %d natürlichen Zahlen ist %d\n", n, resultat_iterativ);

    // Berechnung und Ausgabe der Summe (rekursiv)
    int resultat_rekursiv = summe_rekursiv(n);
    printf("Rekursive Lösung: Die Summe der ersten %d natürlichen Zahlen ist %d\n", n, resultat_rekursiv);
  }
}
