#ifndef MOVE2D_H
#define MOVE2D_H
#include "types.h"
#include "board2d.h"

MoveResult move2d_try(Board2D* b, Pos* player, Direction dir);
int move2d_treasure_step(Board2D* b, Pos* treasure);
int move2d_monster_step(Board2D* b, Pos* monster, const Pos* player);

#endif
