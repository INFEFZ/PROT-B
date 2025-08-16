#ifndef ATTACK_H
#define ATTACK_H

#include "character.h"
#include "monster.h"

typedef enum {
    PHYSICAL,
    MAGICAL,
    RANGED,
    POISON
} AttackType;

void performAttack(Character *attacker, Monster *defender, AttackType attackType);
void performMonsterAttack(Monster *attacker, Character *defender);

#endif
