#include <stdlib.h>
#include <stdbool.h>
#include "game.h" // GameState, Pos, MoveDir
#include "maze.h" // g_maze, MAZE_ROWS/COLS, CELL_*, maze_* API

/*
    Game logic:
    - Build the maze and place player/treasure on empty cells.
    - Move the player by one tile if the target is inside bounds and not an obstacle.
    - Detect win when player and treasure positions match.

    Coordinate convention:
    - x = column index (0..MAZE_COLS-1)
    - y = row index    (0..MAZE_ROWS-1)
    - Access into the grid is g_maze[y][x].
*/

// Returns true if (x,y) is inside the maze.
static inline bool in_bounds(int x, int y) {
    return x >= 0 && x < MAZE_COLS && y >= 0 && y < MAZE_ROWS;
}

// Pick a random empty cell. Falls back to a linear scan if random tries fail.
// NOTE: In a pathological case (virtually full maze) this returns (0,0) even
//       if it is not empty; with sane obstacle densities this should not happen.
static Pos rand_empty_cell(void) {
    const int limit = 4 * MAZE_ROWS * MAZE_COLS;

    // Try random positions first.
    for (int tries = 0; tries < limit; ++tries) {
        int x = rand() % MAZE_COLS;
        int y = rand() % MAZE_ROWS;
        if (in_bounds(x, y) && maze_is_cell_empty(x, y)) {
            return (Pos){ .x = x, .y = y };
        }
    }

    // Fallback: first empty cell found by scanning.
    for (int y = 0; y < MAZE_ROWS; ++y) {
        for (int x = 0; x < MAZE_COLS; ++x) {
            if (maze_is_cell_empty(x, y)) {
                return (Pos){ .x = x, .y = y };
            }
        }
    }

    // Last resort (should not be reached with reasonable densities).
    return (Pos){ .x = 0, .y = 0 };
}

void game_init(GameState *gs, float obstacle_density) {
    if (!gs) return;

    // Build/reset the maze.
    maze_seed_random();
    maze_clear();
    maze_scatter_obstacles(obstacle_density);

    // Place player on an empty cell.
    gs->player = rand_empty_cell();
    g_maze[gs->player.y][gs->player.x] = CELL_PLAYER;

    // Place treasure on a different empty cell.
    do {
        gs->treasure = rand_empty_cell();
    } while (gs->treasure.x == gs->player.x && gs->treasure.y == gs->player.y);

    g_maze[gs->treasure.y][gs->treasure.x] = CELL_TREASURE;
}

bool game_try_move(GameState *gs, MoveDir dir) {
    if (!gs) return false;

    int dx = 0, dy = 0;

    // Translate direction to delta.
    switch (dir) {
        case MOVE_UP:    dy = -1; break;
        case MOVE_DOWN:  dy =  1; break;
        case MOVE_LEFT:  dx = -1; break;
        case MOVE_RIGHT: dx =  1; break;
    }

    const int nx = gs->player.x + dx;
    const int ny = gs->player.y + dy;

    // Reject out-of-bounds and blocked tiles.
    if (!in_bounds(nx, ny)) return false;
    if (g_maze[ny][nx] == CELL_OBSTACLE) return false;

    // Move: clear old footprint and set new one.
    // Note: If the player steps onto the treasure, we still draw 'P' here.
    //       Win detection is handled separately by game_is_won().
    g_maze[gs->player.y][gs->player.x] = CELL_EMPTY;
    gs->player.x = nx;
    gs->player.y = ny;
    g_maze[ny][nx] = CELL_PLAYER;

    return true;
}

bool game_is_won(const GameState *gs) {
    if (!gs) return false;
    return gs->player.x == gs->treasure.x && gs->player.y == gs->treasure.y;
}