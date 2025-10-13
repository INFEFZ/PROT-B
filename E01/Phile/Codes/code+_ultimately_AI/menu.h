#ifndef MENU_H
#define MENU_H
#include "types.h"

// returns selected GameMode or 0 for non-game action
GameMode menu_show_and_select(char* player_name, int name_len, int* show_scores, int* reset_scores, int* quit_program);

#endif
