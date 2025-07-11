#include <stdio.h>
#include "attack.h"

void perfomAttack(Character *attacker, Monster *defender, AttackType attackType)
{
  int schaden;
  printf("----Kampf!!!----\n");
  switch (attackType)
  {
  case PHYSICAL:
    schaden = attacker->attack;
    break;
  case MAGICAL:
    schaden = attacker->attack * 1.5;
    break;
  case RANGED:
    schaden = attacker->attack;
    break;
  case POISON:
    schaden = attacker->attack;
    break;
  }

  defender->health -= schaden;
  printf("Schaden Monster: %d\n", schaden);
}

void performMonsterAttack(Monster *attacker, Character *defender)
{
}