#include "score.h"
#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { ScoreEntry* v; size_t n, cap; } VecScore;
static VecScore g_scores = {0};

static void vec_push(ScoreEntry s) {
    if (g_scores.n==g_scores.cap) {
        size_t nc = g_scores.cap? g_scores.cap*2:16;
        g_scores.v = (ScoreEntry*)realloc(g_scores.v, nc*sizeof(ScoreEntry));
        g_scores.cap = nc;
    }
    g_scores.v[g_scores.n++] = s;
}

void score_init(void){ g_scores.v=NULL; g_scores.n=0; g_scores.cap=0; }
void score_free(void){ free(g_scores.v); g_scores.v=NULL; g_scores.n=g_scores.cap=0; }

static int parse_line(char* line, ScoreEntry* out){
    // format: name;mode;games;wins;best_moves
    char* p=line;
    char* semi1=strchr(p,';'); if(!semi1) return 0; *semi1='\0';
    char* semi2=strchr(semi1+1,';'); if(!semi2) return 0; *semi2='\0';
    char* semi3=strchr(semi2+1,';'); if(!semi3) return 0; *semi3='\0';
    char* semi4=strchr(semi3+1,';'); if(!semi4) return 0; *semi4='\0';
    strncpy(out->name,p,sizeof out->name); out->name[sizeof out->name -1]='\0';
    out->mode = atoi(semi1+1);
    out->games_played = atoi(semi2+1);
    out->wins = atoi(semi3+1);
    out->best_moves = atoi(semi4+1);
    return 1;
}

void score_load(const char* path){
    score_init();
    FILE* f=fopen(path,"r");
    if(!f) return;
    char buf[256];
    while (fgets(buf,sizeof buf,f)){
        size_t len=strlen(buf);
        if(len && buf[len-1]=='\n') buf[len-1]='\0';
        ScoreEntry s;
        if(parse_line(buf,&s)) vec_push(s);
    }
    fclose(f);
}

static void write_entry(FILE* f, const ScoreEntry* s){
    fprintf(f, "%s;%d;%d;%d;%d\n", s->name, s->mode, s->games_played, s->wins, s->best_moves);
}

void score_save(const char* path){
    FILE* f=fopen(path,"w");
    if(!f) return;
    for(size_t i=0;i<g_scores.n;i++) write_entry(f,&g_scores.v[i]);
    fclose(f);
}

static ScoreEntry* find_entry(const char* name, int mode){
    for(size_t i=0;i<g_scores.n;i++){
        if(g_scores.v[i].mode==mode && strcmp(g_scores.v[i].name,name)==0) return &g_scores.v[i];
    }
    return NULL;
}

void score_update(const char* name, int mode, int won, int moves_if_win){
    ScoreEntry* s=find_entry(name,mode);
    if(!s){
        ScoreEntry neu;
        memset(&neu,0,sizeof neu);
        strncpy(neu.name,name,sizeof neu.name); neu.name[sizeof neu.name-1]='\0';
        neu.mode=mode; neu.games_played=0; neu.wins=0; neu.best_moves=-1;
        vec_push(neu);
        s=find_entry(name,mode);
    }
    s->games_played++;
    if(won){
        s->wins++;
        if(s->best_moves<0 || moves_if_win < s->best_moves) s->best_moves=moves_if_win;
    }
}

void score_print_all(void){
    printf("\n== Highscores ==\n");
    if(g_scores.n==0){ printf("(leer)\n"); return; }
    printf("%-20s %-5s %-6s %-6s %-10s\n", "Name", "Mode", "Games", "Wins", "BestMoves");
    for(size_t i=0;i<g_scores.n;i++){
        printf("%-20s %-5d %-6d %-6d %-10d\n",
            g_scores.v[i].name, g_scores.v[i].mode,
            g_scores.v[i].games_played, g_scores.v[i].wins,
            g_scores.v[i].best_moves);
    }
}

void score_reset(const char* path){
    score_free();
    FILE* f=fopen(path,"w");
    if(f) fclose(f);
}
