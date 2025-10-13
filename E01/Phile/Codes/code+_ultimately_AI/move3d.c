#include "move3d.h"
#include "config.h"

static void dir_to_delta(Direction d, int* dx, int* dy, int* dz){
    *dx=0; *dy=0; *dz=0;
    if(d==DIR_UP) *dy=-1;
    else if(d==DIR_DOWN) *dy=1;
    else if(d==DIR_LEFT) *dx=-1;
    else if(d==DIR_RIGHT) *dx=1;
    else if(d==DIR_UPZ) *dz=-1;
    else if(d==DIR_DOWNZ) *dz=1;
}

MoveResult move3d_try(Board3D* b, Pos3* p, Direction dir){
    int dx,dy,dz; dir_to_delta(dir,&dx,&dy,&dz);
    int nx=p->x+dx, ny=p->y+dy, nz=p->z+dz;
    if(!board3d_in_bounds(b,nx,ny,nz)) return MOVE_BLOCKED;
    char target = board3d_get(b,nx,ny,nz);
    if (target==TOKEN_WALL) return MOVE_BLOCKED;
    if (target==TOKEN_TREASURE){
        board3d_set(b,p->x,p->y,p->z,TOKEN_EMPTY);
        board3d_set(b,nx,ny,nz,TOKEN_PLAYER);
        p->x=nx; p->y=ny; p->z=nz;
        return MOVE_WIN;
    }
    board3d_set(b,p->x,p->y,p->z,TOKEN_EMPTY);
    board3d_set(b,nx,ny,nz,TOKEN_PLAYER);
    p->x=nx; p->y=ny; p->z=nz;
    return MOVE_MOVED;
}
