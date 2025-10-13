#ifndef MAZE_H
#define MAZE_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
    Maze module public API

    Coordinate convention:
      - Pos.x = column index  (0 .. MAZE_COLS-1)
      - Pos.y = row index     (0 .. MAZE_ROWS-1)
      - Grid access is g_maze[y][x].

    Cell semantics:
      - CELL_EMPTY    : free tile
      - CELL_OBSTACLE : impassable wall
      - CELL_PLAYER   : player marker (rendering convenience)
      - CELL_TREASURE : treasure marker (rendering convenience)
*/

// Maze dimensions and default obstacle density
#define MAZE_ROWS 12
#define MAZE_COLS 24
#define OBSTACLE_DENSITY 0.15f  // ~15% of inner cells become obstacles

// Cell types
#define CELL_EMPTY    '.'
#define CELL_OBSTACLE 'O'
#define CELL_PLAYER   'P'
#define CELL_TREASURE 'T'

// Position structure (grid coordinates)
typedef struct {
    int x, y;  // x = column, y = row
} Pos;

// Global maze grid storage (row-major: g_maze[y][x])
extern char g_maze[MAZE_ROWS][MAZE_COLS];

/* ---------- Maze operations ---------- */

/**
 * Seed the random number generator (safe to call multiple times).
 */
void maze_seed_random(void);

/**
 * Fill the entire grid with CELL_EMPTY.
 */
void maze_clear(void);

/**
 * Add a solid obstacle border around the outermost ring of the grid.
 * (Top/bottom rows and left/right columns become CELL_OBSTACLE.)
 */
void maze_add_borders(void);

/**
 * Scatter obstacles randomly in the inner area (borders excluded).
 * @param density  Fraction [0..0.9] of inner cells to turn into obstacles.
 */
void maze_scatter_obstacles(float density);

/**
 * Full initialization: clear grid, add borders, then scatter obstacles.
 * @param density  Passed through to maze_scatter_obstacles().
 */
void maze_init(float density);

/* ---------- Cell operations ---------- */

/**
 * Check whether a cell is inside bounds and currently CELL_EMPTY.
 */
bool maze_is_cell_empty(int x, int y);

/**
 * Place a symbol on a random empty inner cell (borders excluded).
 * Returns the position, or {-1,-1} if no suitable cell exists.
 */
Pos maze_place_random(char symbol);

/**
 * Search the grid for the first occurrence of 'symbol'.
 * Returns {-1,-1} if not found.
 */
Pos maze_find(char symbol);

/* ---------- Rendering helpers ---------- */

/**
 * Print the maze to stdout, one row per line.
 */
void maze_draw(void);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // MAZE_H
