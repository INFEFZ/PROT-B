#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void main()
{
  FILE *file;
  int character;
  int lines = 0, words = 0, characters = 0;
  int word = 0;

  // Datei öffnen
  file = fopen("Beispieldatei.txt", "r");
  if (file == NULL)
  {
    perror("Fehler beim Öffnen der Datei");
  }

  // Datei lesen und Zeichen, Wörter und Zeilen zählen
  while ((character = fgetc(file)) != EOF)
  {
    characters++;
    if (character == '\n')
    {
      lines++;
    }
    
    if (character == ' ')
    {
      word = 0;
    }
    else if (!word)
    {
      word = 1;
      words++;
    }
  }

  // Ergebnisse ausgeben
  printf("Zeilen: %d\n", lines);
  printf("Wörter: %d\n", words);
  printf("Zeichen: %d\n", characters);

  // Datei schließen
  fclose(file);
}
