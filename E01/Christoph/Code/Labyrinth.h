#ifndef LABYRINTH_STRUCT_H
#define LABYRINTH_STRUCT_H
#include "Labyrinth.h"

// Erzeugung Struktur Labyrinth
typedef struct
{
    int zeilen, spalten;
    char **feld;
    int spielerPosX, spielerPosY;
    int schatzPosX, schatzPosY;
} Labyrinth;




// Initialisierung der Labyrinth-Funktionen
void initialisiereLabyrinth(Labyrinth *lab, int zeilen, int spalten);

// Platziere Hindernisse
void platziereHindernisse(Labyrinth *lab, int hindernisProzent);

// Funktionen zum Platzieren von Spieler
void platziereSpieler(Labyrinth *lab);

// Funktionen zum Platzieren von Schatz
void platziereSchatz(Labyrinth *lab);

// Funktionen zum anzeigen des Labyrinths
void zeigeLabyrinth(const Labyrinth *lab);

// Zugewienen Speicher freigeben
void gibLabyrinthFrei(Labyrinth *lab);


#endif // LABYRINTH_H