#ifndef LABYRINTH_H
#define LABYRINTH_H
#include "config.h"

void initLabyrinth(char labyrinth[HEIGHT][WIDTH]);
void drawLabyrinth(char labyrinth[HEIGHT][WIDTH], int playerX, int playerY, int treasureX, int treasureY);

#endif // LABYRINTH_H
