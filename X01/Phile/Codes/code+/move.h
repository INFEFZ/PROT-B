#ifndef move_h
#define move_h
#include "labyrinth.h"
#include <stdio.h>

int eingabe(void);
/* 
Funktion um die Eingabe des Spielers zu verarbeiten
W = oben
A = links
S = unten
D = rechts
E = Spiel beenden
*/

int eingabeMonster(void);
/* 
Funktion um die Eingabe des Spielers zu verarbeiten inklusive Monsterbewegung
W = oben
A = links
S = unten
D = rechts
E = Spiel beenden
*/

void move(char richtung); // move in field


void moveMonster(char richtung); // move in field with monster


         
#endif