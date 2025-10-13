#ifndef SCORE_H
#define SCORE_H
#include "types.h"

typedef struct {
    char name[64];
    int mode;           // GameMode
    int games_played;
    int wins;
    int best_moves;     // minimal moves to win; -1 if none
} ScoreEntry;

void score_init(void);
void score_free(void);
void score_load(const char* path);
void score_save(const char* path);
void score_update(const char* name, int mode, int won, int moves_if_win);
void score_print_all(void);
void score_reset(const char* path);

#endif
