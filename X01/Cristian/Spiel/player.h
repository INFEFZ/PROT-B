#ifndef PLAYER_H
#define PLAYER_H
#include "config.h"

int movePlayer(int* x, int* y, char labyrinth[HEIGHT][WIDTH], int treasureX, int treasureY);
void placePlayer(int* x, int* y, char labyrinth[HEIGHT][WIDTH]);

#endif // PLAYER_H
