#ifndef INPUT_H
#define INPUT_H
#include <stddef.h>
#include "types.h"

int input_read_line(char* buf, size_t n);

// menu: returns '1','2','3','4','5','E' (uppercased), or 0 on EOF
char input_read_menu_choice(void);

// name input: trims newline
int input_read_player_name(char* buf, size_t n);

// 2D directions: WASD/E (uppercased), returns 1 if ok, 0 otherwise
int input_read_direction_2d(Direction* d, int* quit);

// 3D directions: WASD + R/F + E (uppercased), returns 1 if ok, 0 otherwise
int input_read_direction_3d(Direction* d, int* quit);

// integer input helper (>=min && <=max). returns 1 on success, 0 on cancel/EOF
int input_read_int(const char* prompt, int minv, int maxv, int* out);

int input_yes_no(const char* prompt, int default_yes);

#endif
