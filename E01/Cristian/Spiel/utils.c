#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"
#include "config.h"

int randomInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void waitForKeyPress() {
    printf("Drücke Enter zum Fortfahren...");
    getchar();
    getchar();
}

void placeTreasure(int* x, int* y, char labyrinth[HEIGHT][WIDTH], int playerX, int playerY) {
    do {
        *x = randomInt(1, WIDTH - 2);
        *y = randomInt(1, HEIGHT - 2);
    } while (
        (labyrinth[*y][*x] == WALL_SYMBOL) || 
        (*x == playerX && *y == playerY)
    );
}