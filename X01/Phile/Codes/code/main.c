/*

***********************************************************

Labyrinth Spiel

***********************************************************

###################################
Version: 1.6
Datum: 23.09.25
Entwickler: Philemon Ammann
###################################

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "labyrinth.h"
#include "move.h"

int main(){
    srand((unsigned)time(NULL));   // Random Seed initialisieren, sonst immer gleiche Zahlen
    labyBuild(); // Labyrinth erstellen
    printf("\nDas Spiel beginnt.\n"); // Spielstart ausgeben
    labyrinth(feld); // Labyrinth anzeigen
    eingabe();  // Eingabe des Spielers verarbeiten
  return 0;
}