#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10
#define OBSTACLE_COUNT 15

typedef struct { int row; int col; } Position;

typedef struct {
    char grid[ROWS][COLS];
    Position player;
    Position treasure;
} LabyrinthState;

bool positions_equal(Position a, Position b){ return a.row==b.row && a.col==b.col; }
int clamp(int v,int lo,int hi){ if(v<lo) return lo; if(v>hi) return hi; return v; }

void lab_clear(LabyrinthState* s){
    for(int r=0;r<ROWS;r++) for(int c=0;c<COLS;c++) s->grid[r][c]='.';
}
void lab_place_random(LabyrinthState* s, Position* out, char symbol){
    while(1){
        int r = rand()%ROWS, c = rand()%COLS;
        if(s->grid[r][c]=='.'){ out->row=r; out->col=c; s->grid[r][c]=symbol; return; }
    }
}
void place_obstacles(LabyrinthState* s){
    int placed=0; while(placed<OBSTACLE_COUNT){
        int r=rand()%ROWS, c=rand()%COLS;
        if(s->grid[r][c]=='.'){ s->grid[r][c]='O'; placed++; }
    }
}
void game_init(LabyrinthState* s){
    lab_clear(s);
    lab_place_random(s,&s->player,'P');
    lab_place_random(s,&s->treasure,'T');
    while(positions_equal(s->player,s->treasure)) lab_place_random(s,&s->treasure,'T');
    place_obstacles(s);
}
void game_draw(const LabyrinthState* s){
    printf("\n");
    for(int r=0;r<ROWS;r++){ for(int c=0;c<COLS;c++) printf("%c ", s->grid[r][c]); printf("\n"); }
    printf("\nLegende: P=Spieler  T=Schatz  O=Hindernis  .=frei\n");
}
bool game_step(LabyrinthState* s, char input){
    int dr=0, dc=0;
    if(input=='w'||input=='W') dr=-1;
    else if(input=='s'||input=='S') dr=1;
    else if(input=='a'||input=='A') dc=-1;
    else if(input=='d'||input=='D') dc=1;
    else return false;

    int nr = clamp(s->player.row+dr,0,ROWS-1);
    int nc = clamp(s->player.col+dc,0,COLS-1);
    if(s->grid[nr][nc]=='O'){ printf("Hindernis! Zug nicht moeglich.\n"); return false; }

    s->grid[s->player.row][s->player.col]='.';
    s->player.row=nr; s->player.col=nc;
    s->grid[nr][nc]='P';

    return positions_equal(s->player,s->treasure);
}

int main(void){
    srand((unsigned int)time(NULL));
    LabyrinthState state; game_init(&state);
    printf("Labyrinthspiel (W/A/S/D und Enter, q zum Beenden)\n");
    while(1){
        game_draw(&state);
        printf("Bewege den Spieler (W/A/S/D): ");
        char m; if(scanf(" %c",&m)!=1) break;
        if(m=='q'||m=='Q'){ printf("\nSpiel beendet.\n"); break; }
        if(game_step(&state,m)){
            game_draw(&state);
            printf("\nHerzlichen Glueckwunsch! Du hast den Schatz gefunden!\n");
            break;
        }
    }
    return 0;
}
