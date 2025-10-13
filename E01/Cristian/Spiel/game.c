#include <stdio.h>
#include "game.h"
#include "labyrinth.h"
#include "player.h"
#include "utils.h"
#include "config.h"

char labyrinth[HEIGHT][WIDTH];
int playerX, playerY;
int treasureX, treasureY;

int stepCount = 0;
int totalWins = 0;

void showWinScreen() {
    printf("\n");
    printf("+------------------------------------------------------------+\n");
    printf("  🎉Schatz gefunden!🎉\n");
    printf("  🚶Schritte gebraucht:     %3d\n", stepCount);
    printf("  🏆Siege in dieser Session:%3d\n", totalWins);
    printf("+------------------------------------------------------------+\n\n");
}

void initGame() {
    initLabyrinth(labyrinth);
    placePlayer(&playerX, &playerY, labyrinth);
    placeTreasure(&treasureX, &treasureY, labyrinth, playerX, playerY);
    stepCount = 0;
}

void startGame() {
    int running;
    char choice;

    do {
        initGame();
        running = 1;

        while (running > 0) {
            clearScreen();
            drawLabyrinth(labyrinth, playerX, playerY, treasureX, treasureY);
            running = movePlayer(&playerX, &playerY, labyrinth, treasureX, treasureY);

            if (running == -1) {
                printf("Spiel wird neu gestartet...\n");
                waitForKeyPress();
                break;
            }
        }

        if (running != -1) {
            totalWins++;
            showWinScreen();
            printf("Möchtest du nochmal spielen? (J/N): ");
            scanf(" %c", &choice);
        } else {
            choice = 'J';
        }

    } while (choice == 'J' || choice == 'j');
}
