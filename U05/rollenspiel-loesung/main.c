#include <stdio.h>
#include <stdlib.h>
#include "character.h"
#include "monster.h"
#include "game.h"

int main() {
    Character player;
    Monster monsters[3];

    int numMonsters=3;

    printf("Willkommen zum Text-basierten RPG!\n");
    createCharacter(&player);

    createMonster(&monsters[0],"Monster 1",83,10);
    createMonster(&monsters[1],"Monster 2",50,5);
    createMonster(&monsters[2],"Monster 3",70,8);


    printf("Das Spiel beginnt!\n");
    startGame(&player, monsters, numMonsters);

    return 0;
}
