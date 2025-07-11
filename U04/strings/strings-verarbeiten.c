#include <stdio.h>
#include <string.h>

#define MAX 100

// Hilfsfunktion zum Entfernen des Zeilenumbruchs '\n'
void entferne_zeilenumbruch(char *str)
{
  size_t len = strlen(str);

  if (len > 0 && str[len - 1] == '\n')
  {
    str[len - 1] = '\0';
  }
}

int main()
{
  char s1[MAX];
  char s2[MAX];

  // Eingabe
  printf("Geben Sie den ersten String ein: ");
  fgets(s1, MAX, stdin);
  entferne_zeilenumbruch(s1);

  printf("Geben Sie den zweiten String ein: ");
  fgets(s2, MAX, stdin);
  entferne_zeilenumbruch(s2);

  // Ausgabe
  printf("String 1: %s\n", s1);
  printf("String 2: %s\n", s2);

  // Vergleich
  if (strcmp(s1, s2) == 0)
  {
    printf("Die Strings sind gleich.\n");
  }
  else
  {
    printf("Die Strings sind verschieden.\n");
  }

  // Verkettung
  strcat(s1, s2); // Achtung: s1 muss gross genug sein!
  printf("Verketteter String: %s\n", s1);

  // Länge
  printf("Länge des neuen Strings: %lu\n", strlen(s1));

  return 0;
}
