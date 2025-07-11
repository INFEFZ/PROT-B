#ifndef CHARACTER_H
#define CHARACTER_H

typedef struct
{
    char name[50];
    int health;
    int attack;
    struct
    {
        unsigned int poisoned : 1;
        unsigned int stunned : 1;
    } status;
} Character;

void createCharacter(Character *character);
void displayCharacter(const Character *character);

#endif
