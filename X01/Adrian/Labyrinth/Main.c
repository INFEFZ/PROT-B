#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Labyrinth.h"

int main() {
    char input;
    srand(time(NULL));

    // Labyrinth initialisieren
    drawLabyrinth(); // Wenn drawLabyrinth() auch init macht, sonst init manuell
    placeRandom(&playerRow, &playerCol);
    labyrinth[playerRow][playerCol] = PLAYER;

    placeRandom(&treasureRow, &treasureCol);
    labyrinth[treasureRow][treasureCol] = TREASURE;

    // Begrüßung nur einmal
    printf("Willkommen in meinem Labyrinth!\n");
    printf("Findest du den Schatz? (T).\n");
    printf("Steuerung: W A S D\n\n");

    printf("Drücke Enter, um zu starten...");
    getchar(); // wartet auf Enter

    while(1) {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        drawLabyrinth();
        printf("Steuerung: W A S D\n"); // optional nochmal anzeigen
        printf("Eingabe: ");
        scanf(" %c", &input);
        movePlayer(input);

        if(playerRow == treasureRow && playerCol == treasureCol) {
            drawLabyrinth();
            printf("\nSuper! Du hast den Schatz gefunden!\n");
            break;
        }
    }

    return 0;
}
