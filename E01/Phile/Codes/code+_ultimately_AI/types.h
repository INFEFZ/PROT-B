#ifndef TYPES_H
#define TYPES_H

typedef struct { int x, y; } Pos;
typedef struct { int x, y, z; } Pos3;

typedef enum {
    DIR_UP, DIR_LEFT, DIR_DOWN, DIR_RIGHT,
    DIR_UPZ, DIR_DOWNZ,
    DIR_INVALID
} Direction;

typedef enum { MOVE_MOVED, MOVE_BLOCKED, MOVE_WIN } MoveResult;

// Expanded modes:
typedef enum {
    MODE_CLASSIC2D=1,             // fixed 10x10
    MODE_CLASSIC2D_TREASURE,      // classic + moving treasure
    MODE_CLASSIC2D_MONSTER,       // classic + monster
    MODE_CLASSIC2D_BOTH,          // classic + moving treasure + monster
    MODE_CUSTOM2D,                // user size + options
    MODE_CUBE3D,                  // 10x10x10
    MODE_CUBE3D_MONSTER           // 3D + monster that chases across layers
} GameMode;

#endif // TYPES_H
