#include <stdio.h>
#include <stdlib.h>

void main()
{
  FILE *file;
  int int_value;
  unsigned int uint_value;
  char char_value;
  char str_value[100];
  double double_value;

  // Datei öffnen
  file = fopen("input.txt", "r");
  if (file == NULL)
  {
    perror("Fehler beim Öffnen der Datei");
  }

  // Formatierte Daten aus der Datei lesen
  fscanf(file, "Ganzzahl (dezimal): %d\n", &int_value);
  fscanf(file, "Positive Ganzzahl (dezimal): %u\n", &uint_value);
  fscanf(file, "Positive Ganzzahl (oktale Darstellung): %o\n", &uint_value);
  fscanf(file, "Positive Ganzzahl (hexadezimale Darstellung): %x\n", &uint_value);
  fscanf(file, "Zeichen: %c\n", &char_value);
  fscanf(file, "Zeichenkette: %s\n", str_value);
  fscanf(file, "Gleitkommazahl (dezimal): %lf\n", &double_value);
  fscanf(file, "Gleitkommazahl (exponential): %le\n", &double_value);
  fscanf(file, "Gleitkommazahl (allgemeines Format): %lg\n", &double_value);

  // Datei schließen
  fclose(file);

  // Eingelesene Daten ausgeben
  printf("Eingelesene Daten:\n");
  printf("Ganzzahl (dezimal): %d\n", int_value);
  printf("Positive Ganzzahl (dezimal): %u\n", uint_value);
  printf("Zeichen: %c\n", char_value);
  printf("Zeichenkette: %s\n", str_value);
  printf("Gleitkommazahl (dezimal): %f\n", double_value);
  printf("Gleitkommazahl (exponential): %e\n", double_value);
  printf("Gleitkommazahl (allgemeines Format): %g\n", double_value);
}
