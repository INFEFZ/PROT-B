#ifndef BOARD3D_H
#define BOARD3D_H
#include "types.h"

typedef struct {
    int w,h,d;
    char* cell; // flat: index = z*h*w + y*w + x
} Board3D;

void board3d_init_cube(Board3D* b);
void board3d_free(Board3D* b);
void board3d_draw_slice(const Board3D* b, int z);
int  board3d_in_bounds(const Board3D* b, int x,int y,int z);

char board3d_get(const Board3D* b, int x,int y,int z);
void board3d_set(Board3D* b, int x,int y,int z, char v);

int  board3d_find(const Board3D* b, char token, Pos3* out);

#endif
