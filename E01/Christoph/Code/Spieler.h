#ifndef Spieler_h
#define Spieler_h
#include "Labyrinth.h"


/* 
Bewegt den Spieler um ein Feld auf Richtungstaste (W / A / S / D)
Rückgabewerte:
    0 = Ungültige Taste
    1 = Gültige Richtung, Bewegung erfolgreich
    2 = Kollision mit Hindernis
    3 = Kollision mit Rand
*/
int spielerBewegen(Labyrinth*lab, char Richtung, int *zähler);


// Prüft, Schatz und Spieler auf gleicher position sind
// Rückgabewerte:
// 0 = Nein
// 1 = Ja
int schatzGefunden(const Labyrinth*lab);


#endif // Spieler_h
