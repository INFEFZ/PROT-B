#include <stdio.h>
#include "player.h"
#include "config.h"
#include "utils.h"

extern int stepCount;

void placePlayer(int* x, int* y, char labyrinth[HEIGHT][WIDTH]) {
    do {
        *x = randomInt(1, WIDTH - 2);
        *y = randomInt(1, HEIGHT - 2);
    } while (labyrinth[*y][*x] == WALL_SYMBOL);
}

int movePlayer(int* x, int* y, char labyrinth[HEIGHT][WIDTH], int treasureX, int treasureY) {
    char input;
    printf("Bewege dich mit W (hoch), A (links), S (runter), D (rechts) oder R (neu starten): ");
    scanf(" %c", &input);

    if (input == 'R' || input == 'r') {
        return -1;
    }

    int newX = *x;
    int newY = *y;

    switch (input) {
        case 'W': case 'w': newY--; break;
        case 'S': case 's': newY++; break;
        case 'A': case 'a': newX--; break;
        case 'D': case 'd': newX++; break;
        default:
            printf("Ungültige Eingabe!\n");
            waitForKeyPress();
            return 1;
    }

    if (labyrinth[newY][newX] == WALL_SYMBOL) {
        printf("Wand im Weg!\n");
        waitForKeyPress();
        return 1;
    }

    *x = newX;
    *y = newY;
    stepCount++;

    if (*x == treasureX && *y == treasureY) {
        return 0;
    }

    return 1;
}
