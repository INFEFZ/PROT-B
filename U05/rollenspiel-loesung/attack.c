#include <stdio.h>
#include "attack.h"

void performAttack(Character *attacker, Monster *defender, AttackType attackType) {
    int damage = 0;
     printf("----Kampf!!!!!------\n");
    switch (attackType) {
        case PHYSICAL:
            damage = attacker->attack;
            printf("%s greift %s mit einem physischen Angriff an!\n", attacker->name, defender->name);
            break;
        case MAGICAL:
            damage = attacker->attack * 2.0;
            printf("%s greift %s mit einem magischen Angriff an!\n", attacker->name, defender->name);
            break;
        case RANGED:
            damage = attacker->attack * 1.5;
            printf("%s greift %s mit einem Fernkampfangriff an!\n", attacker->name, defender->name);
            break;
        case POISON:
            damage = attacker->attack * 1.3;
            printf("%s greift %s mit einem Giftangriff an!\n", attacker->name, defender->name);
            break;
    }
  
    defender->health -= damage;
    printf("Schaden Monster: %d\n",damage);
}

void performMonsterAttack(Monster *attacker, Character *defender) {
    printf("%s greift %s an!\n", attacker->name, defender->name);
    defender->health -= attacker->attack;
    printf("Veränderung Gesundheit Character: -%d\n", attacker->attack);
    if (defender->health <= 0) {
        printf("%s wurde besiegt!\n", defender->name);
    }
}
