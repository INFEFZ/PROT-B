#include <stdio.h>

void trennstriche80()
{
  for (int i=0 ; i<80 ; i++) {
    printf("-");
    // printf("%c", '-');
  }
  printf("\n");
}

void trennstriche(int anzahl)
{
  for (int i=0 ; i<anzahl ; i++) {
    printf("-");
    // printf("%c", '-');
  }
  printf("\n");
}

void main(void)
{
  printf("Es werden 80-Trennstricht ausgegeben.\n");
  trennstriche80();

  int anzahlTrennstrichte = 40;
  printf("Es werden %d-Trennstricht ausgegeben.\n", anzahlTrennstrichte);
  trennstriche(anzahlTrennstrichte);

  printf("Wieviele Trennstriche wollen sie ausgeben:")  
  scanf("%d", &anzahlTrennstrichte);
  printf("Es werden %d-Trennstricht ausgegeben.\n", anzahlTrennstrichte);
  trennstriche(anzahlTrennstrichte);  
}