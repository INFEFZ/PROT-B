#include <stdio.h>
#include "game.h"
#include "attack.h"

void selectAttack(AttackType *attackType)
{
  int wahl;

  printf("Wähle die Angriffsart:\n");
  printf("1: Physisch");
  printf("2:Magisch");
  printf("3: Fernkampfangriff");
  printf("4: Giftangriff");
  do
  {
    printf("Geben Sie die Angriffart ein:");
    scanf("%d", &wahl);
  } while (wahl < 1 || wahl > 4);

  *attackType = (AttackType)(wahl);
}

void startGame(Character *player, Monster *monsters, int numMonsters)
{
}
