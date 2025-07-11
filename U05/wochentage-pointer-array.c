#include <stdio.h>
#include <string.h>

void drucke_tag_info(char *tag)
{
  printf("Tag: %s\n", tag);
  printf("Erster Buchstabe: %c\n", tag[0]);
  printf("Länge: %lu\n\n", strlen(tag));
}

int main()
{
  // Array von Pointern auf Strings
  char *tage[] = {
      "Montag",
      "Dienstag",
      "Mittwoch",
      "Donnerstag",
      "Freitag"};

  int anzahl = sizeof(tage) / sizeof(tage[0]);

  // Ausgabe der Liste
  for (int i = 0; i < anzahl; i++)
  {
    printf("%d: %s (Länge: %lu)\n", i + 1, tage[i], strlen(tage[i]));
  }

  printf("\n--- Detailausgabe ---\n");

  // Funktionsaufruf
  for (int i = 0; i < anzahl; i++)
  {
    drucke_tag_info(tage[i]);
  }

  return 0;
}
