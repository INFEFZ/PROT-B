#include <stdio.h>
#include <string.h>

// Funktion zum Kopieren einer Zeichenkette
void copyString(char destination[], const char source[])
{
  strcpy(destination, source);
}

// Funktion zum Vergleichen zweier Zeichenketten
int compareStrings(const char str1[], const char str2[])
{
  return strcmp(str1, str2);
}

void main()
{
  char source[100], destination[100];

  // Einlesen der Zeichenkette vom Benutzer
  // %*[^\n] scans everything until a \n, but doesn't scan in the \n
  printf("Geben Sie eine Zeichenkette ein (maximal 100 Zeichen):\n");
  scanf(" %[^\n]", source);

  // Kopieren der Zeichenkette
  copyString(destination, source);

  // Vergleichen der Zeichenketten
  int result = compareStrings(source, destination);

  // Ausgabe der Quell- und Ziel-Zeichenkette sowie des Vergleichsergebnisses
  printf("Quell-Zeichenkette: %s\n", source);
  printf("Ziel-Zeichenkette: %s\n", destination);
  if (result == 0)
  {
    printf("Die Zeichenketten sind gleich. Die Kopie war erfolgreich.\n");
  }
  else
  {
    printf("Die Zeichenketten sind unterschiedlich. Die Kopie war nicht erfolgreich.\n");
  }
}
