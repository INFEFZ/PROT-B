#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monster.h"

void createMonster(Monster *monster,char name[],int health,int attack) {

    strcpy(monster->name,name);
    monster->health=health;
    monster->attack=attack;

}

void displayMonster(const Monster *monster) {
    printf("----Monster------\n");
    printf("Name: %s\n", monster->name);
    printf("Gesundheit: %d\n", monster->health);
    printf("Angriff: %d\n", monster->attack);
}
