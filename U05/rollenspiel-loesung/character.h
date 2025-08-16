#ifndef CHARACTER_H
#define CHARACTER_H

typedef struct {
    char name[50];
    int health;
    int attack;
} Character;

void createCharacter(Character *character);
void displayCharacter(const Character *character);

#endif
