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

void move(char richtung); // move in field
/* 
Funktion um den Spieler im Labyrinth zu bewegen
richtung = W/A/S/D (von der Eingabe)
W = oben
A = links
S = unten
D = rechts
E = Spiel beenden
*/
         
#endif