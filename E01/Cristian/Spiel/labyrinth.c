#include <stdio.h>
#include "labyrinth.h"
#include "config.h"

void initLabyrinth(char labyrinth[HEIGHT][WIDTH]) {
    // Alles leer machen
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            labyrinth[i][j] = EMPTY_SYMBOL;
        }
    }

    // Randwände setzen
    for (int i = 0; i < WIDTH; i++) {
        labyrinth[0][i] = WALL_SYMBOL;
        labyrinth[HEIGHT - 1][i] = WALL_SYMBOL;
    }
    for (int i = 0; i < HEIGHT; i++) {
        labyrinth[i][0] = WALL_SYMBOL;
        labyrinth[i][WIDTH - 1] = WALL_SYMBOL;
    }

     // Zusätzliche Hindernisse im Labyrinth
    labyrinth[1][3] = WALL_SYMBOL;
    labyrinth[1][4] = WALL_SYMBOL;

    labyrinth[2][1] = WALL_SYMBOL;
    labyrinth[2][5] = WALL_SYMBOL;
    labyrinth[2][7] = WALL_SYMBOL;

    labyrinth[3][3] = WALL_SYMBOL;
    labyrinth[3][5] = WALL_SYMBOL;
    labyrinth[3][7] = WALL_SYMBOL;

    labyrinth[4][1] = WALL_SYMBOL;
    labyrinth[4][3] = WALL_SYMBOL;

    labyrinth[5][3] = WALL_SYMBOL;
    labyrinth[5][5] = WALL_SYMBOL;
    labyrinth[5][7] = WALL_SYMBOL;

    labyrinth[6][1] = WALL_SYMBOL;
    labyrinth[6][5] = WALL_SYMBOL;
    labyrinth[6][6] = WALL_SYMBOL;
    labyrinth[6][7] = WALL_SYMBOL;

    labyrinth[7][2] = WALL_SYMBOL;
    labyrinth[7][3] = WALL_SYMBOL;
    labyrinth[7][4] = WALL_SYMBOL;
    labyrinth[7][5] = WALL_SYMBOL;
}

void drawLabyrinth(char labyrinth[HEIGHT][WIDTH], int playerX, int playerY, int treasureX, int treasureY) {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            if (i == playerY && j == playerX) {
                printf(ANSI_COLOR_RED "%c " ANSI_COLOR_RESET, PLAYER_SYMBOL);
            } else if (i == treasureY && j == treasureX) {
                printf(ANSI_COLOR_BLUE "%c " ANSI_COLOR_RESET, TREASURE_SYMBOL);
            } else {
                printf("%c ", labyrinth[i][j]);
            }
        }
        printf("\n");
    }
}

