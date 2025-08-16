#include <stdio.h>
#include "character.h"

void createCharacter(Character *character) {
    printf("Geben Sie den Namen Ihres Charakters ein: ");
    scanf("%s", character->name);
    character->health = 100;
    character->attack = 20;
    displayCharacter(character);
}

void displayCharacter(const Character *character) {
    printf("----Character------\n");
    printf("Name: %s\n", character->name);
    printf("Gesundheit: %d\n", character->health);
    printf("Angriff: %d\n", character->attack);
}
