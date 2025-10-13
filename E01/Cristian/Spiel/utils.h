#ifndef UTILS_H
#define UTILS_H
#include "config.h"

int randomInt(int min, int max);
void clearScreen();
void waitForKeyPress();
void placeTreasure(int* x, int* y, char labyrinth[HEIGHT][WIDTH], int playerX, int playerY);

#endif // UTILS_H
