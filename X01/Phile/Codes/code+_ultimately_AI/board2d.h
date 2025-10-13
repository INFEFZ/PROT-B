#ifndef BOARD2D_H
#define BOARD2D_H
#include "types.h"

typedef struct {
    int w, h;
    char** cell; // [h][w]
} Board2D;

void board2d_init_classic(Board2D* b);
int  board2d_init_custom(Board2D* b, int w, int h, double wall_density);
void board2d_free(Board2D* b);

void board2d_draw(const Board2D* b);
int  board2d_in_bounds(const Board2D* b, int x, int y);

int  board2d_place_random(Board2D* b, char token);
int  board2d_find(const Board2D* b, char token, Pos* out);

#endif
