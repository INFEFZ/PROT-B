#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "labyrinth.h"
#include "move.h"

int main(){
  int modus;
    srand((unsigned)time(NULL));   // Random Seed initialisieren, sonst immer gleiche Zahlen
    printf("Willkommen zum Labyrinth Spiel!\n"); // Begrüssung ausgeben
    printf("Welches Labyrinth wollen sie spielen?\n");
    printf("\n1: Standart, 2: Monster\n");
    scanf("%d", &modus); // Modus abfragen
    if (modus != 1 && modus != 2){
        printf("Ungültige Eingabe. Bitte 1 oder 2 eingeben.\n");
        return 1;
    }
    switch (modus)
    {
    case 1:
        printf("Sie haben den Standart Modus gewählt.\n\n");
        labyBuild(); // Labyrinth erstellen
        printf("\nDas Spiel beginnt.\n"); // Spielstart ausgeben
        labyrinth(feld); // Labyrinth anzeigen
        eingabe();  // Eingabe des Spielers verarbeiten
        break;
    case 2:
        printf("Sie haben den Monster Modus gewählt.\n\n");
        labymonst(); // Labyrinth erstellen inklusive Monster
        printf("\nDas Spiel beginnt.\n"); // Spielstart ausgeben
        labyrinth(feld); // Labyrinth anzeigen
        eingabeMonster();  // Eingabe des Spielers verarbeiten
        break;
    default:
        printf("Ungültige Eingabe. Bitte 1 oder 2 eingeben.\n");
        return 1;
    }
  return 0;
}