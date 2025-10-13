#ifndef MOVE3D_H
#define MOVE3D_H
#include "types.h"
#include "board3d.h"

MoveResult move3d_try(Board3D* b, Pos3* p, Direction dir);

#endif
