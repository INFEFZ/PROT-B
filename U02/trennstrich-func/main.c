#include <stdio.h>
#include "func.h"

void main(void)
{
  printf("Es werden 80-Trennstricht ausgegeben.\n");
  trennstriche80();

  int anzahlTrennstrichte = 40;
  printf("Es werden %d-Trennstricht ausgegeben.\n", anzahlTrennstrichte);
  trennstriche(anzahlTrennstrichte);

  printf("Wieviele Trennstriche wollen sie ausgeben:");
  scanf("%d", &anzahlTrennstrichte);
  printf("Es werden %d-Trennstricht ausgegeben.\n", anzahlTrennstrichte);
  trennstriche(anzahlTrennstrichte);
}