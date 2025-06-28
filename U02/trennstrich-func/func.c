#include <stdio.h>
#include "func.h"

void trennstriche80()
{
  for (int i = 0; i < 80; i++)
  {
    printf("-");
    // printf("%c", '-');
  }
  printf("\n");
}

void trennstriche(int anzahl)
{
  for (int i = 0; i < anzahl; i++)
  {
    printf("-");
    // printf("%c", '-');
  }
  printf("\n");
}
