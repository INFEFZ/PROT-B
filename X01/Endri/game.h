#ifndef GAME_H
#define GAME_H

#include <stdbool.h>

typedef struct {
    int rows;
    int cols;
    char **cells;     // dynamically allocated 2D grid
    int player_r;
    int player_c;
    int treasure_r;
    int treasure_c;
} Maze;

typedef enum {
    MOVE_UP,
    MOVE_LEFT,
    MOVE_DOWN,
    MOVE_RIGHT,
    MOVE_INVALID
} Move;

// Game setup & teardown
bool init_maze(Maze *m, int rows, int cols, int obstacle_percent);
void free_maze(Maze *m);

// Game rendering & logic
void draw_maze(const Maze *m);
bool apply_move(Maze *m, Move mv);
bool is_victory(const Maze *m);

// Input handling
Move parse_input(const char *line);

// Utils
void clear_screen(void);
int rand_range(int min_inclusive, int max_inclusive);

#endif // GAME_H