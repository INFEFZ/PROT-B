#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *file;
  int int_value;
  unsigned int uint_value;
  char char_value;
  char str_value[100];
  double double_value;

  // Benutzer-Eingabe erfassen
  printf("Geben Sie eine Ganzzahl ein: ");
  scanf("%d", &int_value);
  printf("Geben Sie eine positive Ganzzahl ein: ");
  scanf("%u", &uint_value);
  printf("Geben Sie ein Zeichen ein: ");
  scanf(" %c", &char_value);
  printf("Geben Sie eine Zeichenkette ein: ");
  scanf("%s", str_value);
  printf("Geben Sie eine Gleitkommazahl ein: ");
  scanf("%lf", &double_value);

  // Datei öffnen
  file = fopen("output.txt", "w");
  if (file == NULL)
  {
    perror("Fehler beim Öffnen der Datei");
    return EXIT_FAILURE;
  }

  // Formatierte Daten in die Datei schreiben
  fprintf(file, "Ganzzahl (dezimal): %d\n", int_value);
  fprintf(file, "Positive Ganzzahl (dezimal): %u\n", uint_value);
  fprintf(file, "Positive Ganzzahl (oktale Darstellung): %o\n", uint_value);
  fprintf(file, "Positive Ganzzahl (hexadezimale Darstellung): %x\n", uint_value);
  fprintf(file, "Zeichen: %c\n", char_value);
  fprintf(file, "Zeichenkette: %s\n", str_value);
  fprintf(file, "Gleitkommazahl (dezimal): %f\n", double_value);
  fprintf(file, "Gleitkommazahl (exponential): %e\n", double_value);
  fprintf(file, "Gleitkommazahl (allgemeines Format): %g\n", double_value);

  // Datei schließen
  fclose(file);

  printf("Daten wurden in die Datei geschrieben.\n");
}
