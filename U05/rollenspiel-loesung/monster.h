#ifndef MONSTER_H
#define MONSTER_H


typedef struct {
    char name[50];
    int health;
    int attack;
} Monster;

void createMonster(Monster *monster,char name[],int health,int attack);
void displayMonster(const Monster *monster);

#endif
