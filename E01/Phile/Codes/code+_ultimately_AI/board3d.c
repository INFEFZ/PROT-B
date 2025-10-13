#include "board3d.h"
#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int idx(const Board3D* b, int x,int y,int z){ return z*b->h*b->w + y*b->w + x; }

void board3d_free(Board3D* b){
    if(b && b->cell){ free(b->cell); b->cell=NULL; b->w=b->h=b->d=0; }
}

void board3d_init_cube(Board3D* b){
    b->w=BOARD_W_DEFAULT; b->h=BOARD_H_DEFAULT; b->d=BOARD_D_DEFAULT;
    b->cell=(char*)malloc((size_t)(b->w*b->h*b->d));
    for(int z=0;z<b->d;z++)
        for(int y=0;y<b->h;y++)
            for(int x=0;x<b->w;x++)
                b->cell[idx(b,x,y,z)] = TOKEN_EMPTY;
    // same obstacles on each layer: reuse classic 2D mask positions
    int walls[][2] = {
        {0,6},
        {1,0},
        {2,0},{2,3},
        {3,4},{3,5},
        {4,0},{4,2},
        {5,0},{5,1},{5,3},{5,4},{5,5},{5,8},{5,9},
        {6,3},{6,6},
        {7,0},{7,5},{7,7},{7,8},
        {8,6},
        {9,2},{9,4},{9,9}
    };
    int n = (int)(sizeof(walls)/sizeof(walls[0]));
    for(int z=0;z<b->d;z++){
        for(int i=0;i<n;i++){
            int y=walls[i][0], x=walls[i][1];
            if (y>=0 && y<b->h && x>=0 && x<b->w)
                b->cell[idx(b,x,y,z)] = TOKEN_WALL;
        }
    }
    // place treasure at top layer, player at bottom
    b->cell[idx(b,1,1,0)] = TOKEN_PLAYER;
    b->cell[idx(b,b->w-2,b->h-2,b->d-1)] = TOKEN_TREASURE;
}

void board3d_draw_slice(const Board3D* b, int z){
    if (z<0) z=0; if(z>=b->d) z=b->d-1;
    printf("Cube Ebene z=%d (%dx%dx%d):\n", z,b->w,b->h,b->d);
    for(int y=0;y<b->h;y++){
        for(int x=0;x<b->w;x++){
            putchar(b->cell[idx(b,x,y,z)]);
            putchar(' ');
        }
        putchar('\n');
    }
}

int board3d_in_bounds(const Board3D* b, int x,int y,int z){
    return x>=0 && x<b->w && y>=0 && y<b->h && z>=0 && z<b->d;
}

char board3d_get(const Board3D* b, int x,int y,int z){ return b->cell[idx(b,x,y,z)]; }
void board3d_set(Board3D* b, int x,int y,int z, char v){ b->cell[idx(b,x,y,z)]=v; }

int board3d_find(const Board3D* b, char token, Pos3* out){
    for(int z=0;z<b->d;z++)
        for(int y=0;y<b->h;y++)
            for(int x=0;x<b->w;x++)
                if (board3d_get(b,x,y,z)==token){ out->x=x; out->y=y; out->z=z; return 1; }
    return 0;
}
