#include "game.h"
#include "config.h"
#include "types.h"
#include "menu.h"
#include "input.h"
#include "score.h"
#include "board2d.h"
#include "move2d.h"
#include "board3d.h"
#include "move3d.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static void place_monster_if_needed(Board2D* b, int with_monster){
    if(with_monster){
        for (int k=0;k<1000;k++){
            int x = rand()%b->w, y=rand()%b->h;
            if (b->cell[y][x]==TOKEN_EMPTY){ b->cell[y][x]=TOKEN_MONSTER; return; }
        }
    }
}

static void play_classic2d_base(const char* name, int treasure_moves, int with_monster, int mode_for_score){
    Board2D b; board2d_init_classic(&b);
    Pos player; board2d_find(&b, TOKEN_PLAYER, &player);
    Pos treasure; board2d_find(&b, TOKEN_TREASURE, &treasure);
    Pos monster;
    place_monster_if_needed(&b, with_monster);
    int moves=0;
    board2d_draw(&b);
    while (1){
        Direction d=DIR_INVALID; int quit=0;
        if(!input_read_direction_2d(&d,&quit)) { printf("Ungültige Eingabe.\n"); continue; }
        if(quit){ printf("Runde beendet.\n"); score_update(name, mode_for_score, 0, 0); break; }
        MoveResult r = move2d_try(&b, &player, d);
        if (r==MOVE_BLOCKED){ printf("Blockiert.\n"); continue; }
        moves++;
        if (r==MOVE_WIN){ board2d_draw(&b); printf("Gewonnen in %d Zügen!\n", moves); score_update(name, mode_for_score, 1, moves); break; }

        if (treasure_moves){
            move2d_treasure_step(&b, &treasure);
            Pos tNow; if (board2d_find(&b, TOKEN_TREASURE, &tNow) && tNow.x==player.x && tNow.y==player.y){
                board2d_draw(&b); printf("Der Schatz kam zu dir! Sieg in %d Zügen.\n", moves);
                score_update(name, mode_for_score, 1, moves); break;
            }
        }

        if (with_monster){
            if (board2d_find(&b, TOKEN_MONSTER, &monster)){
                move2d_monster_step(&b, &monster, &player);
                Pos mNow; if (board2d_find(&b, TOKEN_MONSTER, &mNow) && mNow.x==player.x && mNow.y==player.y){
                    board2d_draw(&b); printf("Das Monster hat dich erwischt. Verloren.\n");
                    score_update(name, mode_for_score, 0, 0); break;
                }
            }
        }

        board2d_draw(&b);
    }
    board2d_free(&b);
}

static void play_custom2d(const char* name){
    int w,h;
    if(!input_read_int("Breite",5,100,&w)) { printf("Abgebrochen.\n"); score_update(name, MODE_CUSTOM2D, 0, 0); return; }
    if(!input_read_int("Höhe",5,100,&h))   { printf("Abgebrochen.\n"); score_update(name, MODE_CUSTOM2D, 0, 0); return; }
    int treasure_moves = input_yes_no("Soll sich der Schatz bewegen?", 0);
    int with_monster   = input_yes_no("Soll ein Monster jagen?", 0);
    double density = 0.25;
    Board2D b;
    if(!board2d_init_custom(&b,w,h,density)){ printf("Konnte Board nicht anlegen.\n"); score_update(name, MODE_CUSTOM2D, 0, 0); return; }
    place_monster_if_needed(&b, with_monster);
    Pos player; board2d_find(&b, TOKEN_PLAYER, &player);
    Pos treasure; board2d_find(&b, TOKEN_TREASURE, &treasure);
    Pos monster; // may not exist
    int moves=0;
    board2d_draw(&b);
    while (1){
        Direction d=DIR_INVALID; int quit=0;
        if(!input_read_direction_2d(&d,&quit)) { printf("Ungültige Eingabe.\n"); continue; }
        if(quit){ printf("Runde beendet.\n"); score_update(name, MODE_CUSTOM2D, 0, 0); break; }
        MoveResult r = move2d_try(&b, &player, d);
        if (r==MOVE_BLOCKED){ printf("Blockiert.\n"); continue; }
        moves++;
        if (r==MOVE_WIN){ board2d_draw(&b); printf("Gewonnen in %d Zügen!\n", moves); score_update(name, MODE_CUSTOM2D, 1, moves); break; }

        if (treasure_moves){
            move2d_treasure_step(&b, &treasure);
            Pos tNow; if (board2d_find(&b, TOKEN_TREASURE, &tNow) && tNow.x==player.x && tNow.y==player.y){
                board2d_draw(&b); printf("Der Schatz kam zu dir! Sieg in %d Zügen.\n", moves);
                score_update(name, MODE_CUSTOM2D, 1, moves); break;
            }
        }

        if (with_monster){
            if (board2d_find(&b, TOKEN_MONSTER, &monster)){
                move2d_monster_step(&b, &monster, &player);
                Pos mNow; if (board2d_find(&b, TOKEN_MONSTER, &mNow) && mNow.x==player.x && mNow.y==player.y){
                    board2d_draw(&b); printf("Das Monster hat dich erwischt. Verloren.\n");
                    score_update(name, MODE_CUSTOM2D, 0, 0); break;
                }
            }
        }

        board2d_draw(&b);
    }
    board2d_free(&b);
}

static int move3d_monster_step(Board3D* b, Pos3* m, const Pos3* p){
    // Greedy 3D: move one step to reduce |dx|+|dy|+|dz|, avoiding walls/treasure
    if (!board3d_find(b, TOKEN_MONSTER, m)){
        for (int tries=0; tries<10000; ++tries){
            int x=rand()%b->w, y=rand()%b->h, z=rand()%b->d;
            if (board3d_get(b,x,y,z)==TOKEN_EMPTY){ board3d_set(b,x,y,z,TOKEN_MONSTER); m->x=x;m->y=y;m->z=z; break; }
        }
    }
    int bestd=1e9, bx=m->x, by=m->y, bz=m->z, found=0;
    int dxs[6]={ 0, 0,-1, 1, 0, 0};
    int dys[6]={-1, 1, 0, 0, 0, 0};
    int dzs[6]={ 0, 0, 0, 0,-1, 1};
    for(int i=0;i<6;i++){
        int nx=m->x+dxs[i], ny=m->y+dys[i], nz=m->z+dzs[i];
        if(!board3d_in_bounds(b,nx,ny,nz)) continue;
        char c=board3d_get(b,nx,ny,nz);
        if(c==TOKEN_WALL || c==TOKEN_TREASURE) continue;
        int dd = abs(nx-p->x) + abs(ny-p->y) + abs(nz-p->z);
        if(dd<bestd){ bestd=dd; bx=nx; by=ny; bz=nz; found=1; }
    }
    if(!found) return 0;
    board3d_set(b,m->x,m->y,m->z,TOKEN_EMPTY);
    board3d_set(b,bx,by,bz,TOKEN_MONSTER);
    m->x=bx; m->y=by; m->z=bz;
    return 1;
}

static void play_cube3d_base(const char* name, int with_monster, int mode_for_score){
    Board3D b; board3d_init_cube(&b);
    Pos3 player; board3d_find(&b, TOKEN_PLAYER, &player);
    Pos3 monster;
    int moves=0; int current_z = player.z;
    board3d_draw_slice(&b, current_z);
    while (1){
        Direction d=DIR_INVALID; int quit=0;
        if(!input_read_direction_3d(&d,&quit)) { printf("Ungültige Eingabe.\n"); continue; }
        if(quit){ printf("Runde beendet.\n"); score_update(name, mode_for_score, 0, 0); break; }
        MoveResult r = move3d_try(&b, &player, d);
        if (r==MOVE_BLOCKED){ printf("Blockiert.\n"); continue; }
        moves++;
        if (r==MOVE_WIN){ board3d_draw_slice(&b, player.z); printf("Gewonnen in %d Zügen!\n", moves); score_update(name, mode_for_score, 1, moves); break; }

        if (with_monster){
            move3d_monster_step(&b, &monster, &player);
            Pos3 mnow; if (board3d_find(&b, TOKEN_MONSTER, &mnow) && mnow.x==player.x && mnow.y==player.y && mnow.z==player.z){
                board3d_draw_slice(&b, player.z); printf("3D-Monster hat dich erwischt. Verloren.\n");
                score_update(name, mode_for_score, 0, 0); break;
            }
        }

        if (player.z != current_z){ current_z = player.z; }
        board3d_draw_slice(&b, current_z);
    }
    board3d_free(&b);
}

void game_run(void){
    char name[64] = {0};
    score_load(SCORE_FILE);
    int quit_program = 0;
    while (!quit_program){
        int show_scores=0, reset_scores=0;
        GameMode mode = menu_show_and_select(name, sizeof name, &show_scores, &reset_scores, &quit_program);
        if (quit_program) break;
        if (show_scores){ score_print_all(); continue; }
        if (reset_scores){ score_reset(SCORE_FILE); printf("Highscores zurückgesetzt.\n"); continue; }
        switch (mode){
            case MODE_CLASSIC2D:           play_classic2d_base(name, 0, 0, MODE_CLASSIC2D); break;
            case MODE_CLASSIC2D_TREASURE:  play_classic2d_base(name, 1, 0, MODE_CLASSIC2D_TREASURE); break;
            case MODE_CLASSIC2D_MONSTER:   play_classic2d_base(name, 0, 1, MODE_CLASSIC2D_MONSTER); break;
            case MODE_CLASSIC2D_BOTH:      play_classic2d_base(name, 1, 1, MODE_CLASSIC2D_BOTH); break;
            case MODE_CUSTOM2D:            play_custom2d(name); break;
            case MODE_CUBE3D:              play_cube3d_base(name, 0, MODE_CUBE3D); break;
            case MODE_CUBE3D_MONSTER:      play_cube3d_base(name, 1, MODE_CUBE3D_MONSTER); break;
            default: break;
        }
        score_save(SCORE_FILE);
    }
    score_save(SCORE_FILE);
    score_free();
    printf("Tschüss, %s!\n", name[0]?name:"Spieler");
}
