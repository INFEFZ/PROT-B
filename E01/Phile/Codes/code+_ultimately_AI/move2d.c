#include "move2d.h"
#include "config.h"
#include <stdlib.h>

static void dir_to_delta(Direction d, int* dx, int* dy){
    *dx=0; *dy=0;
    if(d==DIR_UP) *dy=-1;
    else if(d==DIR_DOWN) *dy=1;
    else if(d==DIR_LEFT) *dx=-1;
    else if(d==DIR_RIGHT) *dx=1;
}

MoveResult move2d_try(Board2D* b, Pos* player, Direction dir){
    int dx,dy; dir_to_delta(dir,&dx,&dy);
    int nx = player->x + dx;
    int ny = player->y + dy;
    if(!board2d_in_bounds(b,nx,ny)) return MOVE_BLOCKED;
    char target = b->cell[ny][nx];
    if(target==TOKEN_WALL) return MOVE_BLOCKED;
    if(target==TOKEN_TREASURE){
        // move player onto treasure -> win
        b->cell[player->y][player->x] = TOKEN_EMPTY;
        b->cell[ny][nx] = TOKEN_PLAYER;
        player->x=nx; player->y=ny;
        return MOVE_WIN;
    }
    if(target==TOKEN_MONSTER){
        // block entering monster cell; catch is handled on monster step
        return MOVE_BLOCKED;
    }
    // empty -> move
    b->cell[player->y][player->x] = TOKEN_EMPTY;
    b->cell[ny][nx] = TOKEN_PLAYER;
    player->x=nx; player->y=ny;
    return MOVE_MOVED;
}

int move2d_treasure_step(Board2D* b, Pos* t){
    if (!board2d_find(b, TOKEN_TREASURE, t)) return 0;
    Direction dirs[4] = {DIR_UP, DIR_DOWN, DIR_LEFT, DIR_RIGHT};
    for (int i=0;i<4;i++){ int j = rand()%4; Direction tmp = dirs[i]; dirs[i]=dirs[j]; dirs[j]=tmp; }
    for (int k=0;k<4;k++){
        int dx=0,dy=0; dir_to_delta(dirs[k],&dx,&dy);
        int nx=t->x+dx, ny=t->y+dy;
        if(!board2d_in_bounds(b,nx,ny)) continue;
        char c=b->cell[ny][nx];
        if(c==TOKEN_EMPTY){
            b->cell[t->y][t->x]=TOKEN_EMPTY;
            b->cell[ny][nx]=TOKEN_TREASURE;
            t->x=nx; t->y=ny;
            return 1;
        }
    }
    return 0;
}

static int manhattan(int x1,int y1,int x2,int y2){ int dx=x1-x2; if(dx<0)dx=-dx; int dy=y1-y2; if(dy<0)dy=-dy; return dx+dy; }

int move2d_monster_step(Board2D* b, Pos* m, const Pos* player){
    if (!board2d_find(b, TOKEN_MONSTER, m)) return 0;
    Direction dirs[4]={DIR_UP,DIR_DOWN,DIR_LEFT,DIR_RIGHT};
    int bestd=999999, bestnx=m->x, bestny=m->y, found=0;
    for(int i=0;i<4;i++){
        int dx=0,dy=0; dir_to_delta(dirs[i],&dx,&dy);
        int nx=m->x+dx, ny=m->y+dy;
        if(!board2d_in_bounds(b,nx,ny)) continue;
        char c=b->cell[ny][nx];
        if(c==TOKEN_WALL || c==TOKEN_TREASURE) continue; // cannot step on wall or treasure
        int d=manhattan(nx,ny,player->x,player->y);
        if(d<bestd){ bestd=d; bestnx=nx; bestny=ny; found=1; }
    }
    if(!found) return 0;
    b->cell[m->y][m->x]=TOKEN_EMPTY;
    if (bestnx==player->x && bestny==player->y){
        b->cell[bestny][bestnx]=TOKEN_MONSTER;
        m->x=bestnx; m->y=bestny;
        return 1;
    }
    b->cell[bestny][bestnx]=TOKEN_MONSTER;
    m->x=bestnx; m->y=bestny;
    return 1;
}
