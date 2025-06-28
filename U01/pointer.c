#include <stdio.h>

void main(void)
{
  int zahl = 10;
  int *pzahl = NULL;

  pzahl = &zahl;
  printf("Adresse von zahl=%p, Pointer pzahl=%p\n", &zahl, pzahl);

  // Werte über Pointer setzen
  *pzahl = 10;

  printf("zahl=%d, p_zahl=%d\n", zahl, *pzahl);

  // Adresse von Zahl, dann auf Inhalt setzen
  *(&zahl) = 100;
  printf("zahl=%d\n", zahl);
}