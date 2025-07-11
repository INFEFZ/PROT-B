#include <stdio.h>
#include <stdlib.h>
#include "character.h"
#include "monster.h"
#include "game.h"

void main()
{
  Character player;
  Monster monsters[3];
  int numMonster = 3;

  printf("Willkommen zum textbasierten Rollenspiel Spieler gegen Monster:\n");

  createCharacter(&player);

  createMonster(&monsters[0], "Monster 1", 83, 10);
  createMonster(&monsters[1], "Monster 2", 55, 5);
  createMonster(&monsters[3], "Monster 3", 70, 8);

  printf("Das Spiel beginnt....");

  startGame(&player, monsters, numMonster);
}