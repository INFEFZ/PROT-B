#include "maze.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Maze module

    Coordinate convention:
      - x = column index  (0 .. MAZE_COLS-1)
      - y = row index     (0 .. MAZE_ROWS-1)
      - Grid access is g_maze[y][x].

    Public API used by the game:
      - maze_seed_random()
      - maze_clear()
      - maze_scatter_obstacles(density)
      - maze_init(density)
      - maze_is_cell_empty(x, y)

    Optional helpers (can stay private to this file unless you add them to maze.h):
      - maze_add_borders()
      - maze_place_random(symbol)
      - maze_find(symbol)
      - maze_draw()
*/

// Global maze storage (row-major: g_maze[y][x]).
char g_maze[MAZE_ROWS][MAZE_COLS];

// Returns true if (x, y) is inside the grid.
static inline bool in_bounds(int x, int y) {
    return (x >= 0 && x < MAZE_COLS && y >= 0 && y < MAZE_ROWS);
}

// Seed the RNG once per process.
void maze_seed_random(void) {
    static int seeded = 0;
    if (!seeded) {
        srand((unsigned)time(NULL));
        seeded = 1;
    }
}

// Fill the entire grid with empty cells.
void maze_clear(void) {
    for (int y = 0; y < MAZE_ROWS; ++y) {
        for (int x = 0; x < MAZE_COLS; ++x) {
            g_maze[y][x] = CELL_EMPTY;
        }
    }
}

// Place a solid obstacle border around the maze (outermost ring).
void maze_add_borders(void) {
    for (int x = 0; x < MAZE_COLS; ++x) {
        g_maze[0][x] = CELL_OBSTACLE;
        g_maze[MAZE_ROWS - 1][x] = CELL_OBSTACLE;
    }
    for (int y = 0; y < MAZE_ROWS; ++y) {
        g_maze[y][0] = CELL_OBSTACLE;
        g_maze[y][MAZE_COLS - 1] = CELL_OBSTACLE;
    }
}

// Randomly scatter obstacles in the *inner* area (keeps borders clear).
void maze_scatter_obstacles(float density) {
    if (density < 0.0f) density = 0.0f;
    if (density > 0.9f) density = 0.9f;

    const int inner_h = MAZE_ROWS - 2;
    const int inner_w = MAZE_COLS - 2;
    const int inner_cells = inner_h * inner_w;
    const int to_place = (int)(inner_cells * density);

    int placed = 0;
    while (placed < to_place) {
        int x = 1 + rand() % (MAZE_COLS - 2); // avoid the outer border
        int y = 1 + rand() % (MAZE_ROWS - 2);
        if (g_maze[y][x] == CELL_EMPTY) {
            g_maze[y][x] = CELL_OBSTACLE;
            ++placed;
        }
    }
}

// Full initialization: clear, add borders, then scatter obstacles.
void maze_init(float density) {
    maze_clear();
    maze_add_borders();
    maze_scatter_obstacles(density);
}

// --- Placement & query helpers ---

// True if the cell is inside bounds and currently empty.
bool maze_is_cell_empty(int x, int y) {
    return in_bounds(x, y) && g_maze[y][x] == CELL_EMPTY;
}

// Place 'symbol' on a random empty inner cell; returns its position or {-1,-1} if none found.
Pos maze_place_random(char symbol) {
    Pos pos = (Pos){ -1, -1 };

    // Try random positions first.
    for (int tries = 0; tries < 10000; ++tries) {
        int x = 1 + rand() % (MAZE_COLS - 2);
        int y = 1 + rand() % (MAZE_ROWS - 2);
        if (g_maze[y][x] == CELL_EMPTY) {
            g_maze[y][x] = symbol;
            pos.x = x; pos.y = y;
            return pos;
        }
    }

    // Fallback: linear scan.
    for (int y = 1; y < MAZE_ROWS - 1; ++y) {
        for (int x = 1; x < MAZE_COLS - 1; ++x) {
            if (g_maze[y][x] == CELL_EMPTY) {
                g_maze[y][x] = symbol;
                pos.x = x; pos.y = y;
                return pos;
            }
        }
    }
    return pos; // {-1,-1} if no space was found
}

// Find the first occurrence of 'symbol'; returns {-1,-1} if not found.
Pos maze_find(char symbol) {
    for (int y = 0; y < MAZE_ROWS; ++y) {
        for (int x = 0; x < MAZE_COLS; ++x) {
            if (g_maze[y][x] == symbol) {
                return (Pos){ x, y };
            }
        }
    }
    return (Pos){ -1, -1 };
}

// Dump the maze to stdout, one row per line.
void maze_draw(void) {
    for (int y = 0; y < MAZE_ROWS; ++y) {
        for (int x = 0; x < MAZE_COLS; ++x) {
            putchar(g_maze[y][x]);
        }
        putchar('\n');
    }
}
