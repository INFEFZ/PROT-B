#ifndef MAZE_H
#define MAZE_H

#include "game.h"

// Internal helpers split in separate module for clarity
void place_obstacles(Maze *m, int obstacle_percent);
void place_player_and_treasure(Maze *m);

#endif // MAZE_H