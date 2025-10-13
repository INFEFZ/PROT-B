#include "board2d.h"
#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static char** alloc_2d(int h, int w){
    char** rows = (char**)malloc(sizeof(char*)*h);
    if(!rows) return NULL;
    for(int i=0;i<h;i++){
        rows[i]=(char*)malloc((size_t)w);
        if(!rows[i]){ for(int k=0;k<i;k++) free(rows[k]); free(rows); return NULL; }
    }
    return rows;
}

static void free_2d(char** rows, int h){
    if(!rows) return;
    for(int i=0;i<h;i++) free(rows[i]);
    free(rows);
}

void board2d_free(Board2D* b){
    if(b && b->cell){
        free_2d(b->cell,b->h);
        b->cell=NULL; b->w=b->h=0;
    }
}

static void fill(Board2D* b, char c){
    for(int y=0;y<b->h;y++) for(int x=0;x<b->w;x++) b->cell[y][x]=c;
}

int board2d_in_bounds(const Board2D* b, int x, int y){
    return x>=0 && x<b->w && y>=0 && y<b->h;
}

void board2d_draw(const Board2D* b){
    printf("Labyrinth (%dx%d):\n", b->w,b->h);
    for(int y=0;y<b->h;y++){
        for(int x=0;x<b->w;x++){
            putchar(b->cell[y][x]);
            putchar(' ');
        }
        putchar('\n');
    }
}

int board2d_place_random(Board2D* b, char token){
    // place token on a random empty cell
    int attempts = b->w*b->h*4;
    while(attempts--){
        int x = rand()%b->w;
        int y = rand()%b->h;
        if(b->cell[y][x]==TOKEN_EMPTY){
            b->cell[y][x]=token;
            return 1;
        }
    }
    return 0;
}

int board2d_find(const Board2D* b, char token, Pos* out){
    for(int y=0;y<b->h;y++){
        for(int x=0;x<b->w;x++){
            if(b->cell[y][x]==token){ out->x=x; out->y=y; return 1; }
        }
    }
    return 0;
}

void board2d_init_classic(Board2D* b){
    b->w = BOARD_W_DEFAULT; b->h = BOARD_H_DEFAULT;
    b->cell = alloc_2d(b->h, b->w);
    fill(b, TOKEN_EMPTY);

    // Fixed obstacle layout (normalized to 'O')
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
    for(int i=0;i<n;i++){
        int y=walls[i][0], x=walls[i][1];
        if (y>=0 && y<b->h && x>=0 && x<b->w) b->cell[y][x]=TOKEN_WALL;
    }

    // treasure and player random (not on wall)
    board2d_place_random(b, TOKEN_TREASURE);
    board2d_place_random(b, TOKEN_PLAYER);
}

int board2d_init_custom(Board2D* b, int w, int h, double wall_density){
    if (w<5) w=5; if(h<5) h=5;
    if (wall_density<0.0) wall_density=0.0;
    if (wall_density>0.6) wall_density=0.6;
    b->w=w; b->h=h;
    b->cell=alloc_2d(h,w);
    if(!b->cell) return 0;
    fill(b, TOKEN_EMPTY);
    int cells = w*h;
    int nwalls = (int)(cells*wall_density);
    for(int i=0;i<nwalls;i++){
        int x=rand()%w, y=rand()%h;
        if (b->cell[y][x]==TOKEN_EMPTY) b->cell[y][x]=TOKEN_WALL;
        else i--;
    }
    // ensure at least one treasure and player
    board2d_place_random(b, TOKEN_TREASURE);
    board2d_place_random(b, TOKEN_PLAYER);
    return 1;
}
