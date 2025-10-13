#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include "maze.h"  // Pos, MAZE_ROWS/COLS, CELL_*, g_maze, maze_* API

#ifdef __cplusplus
extern "C" {
#endif

/*
    GameState and API

    Coordinate convention:
      - Pos.x = column index (0..MAZE_COLS-1)
      - Pos.y = row index    (0..MAZE_ROWS-1)
      - Grid access is g_maze[y][x].

    Rendering responsibility:
      - game.c updates g_maze to place 'P' (player) and 'T' (treasure).
      - Stepping onto the treasure is allowed; the tile will show 'P'.
      - Win detection is handled by game_is_won().
*/

// Holds current player and treasure positions (grid coordinates).
typedef struct {
    Pos player;
    Pos treasure;
} GameState;

// 4-way movement directions (one tile per move).
typedef enum {
    MOVE_UP,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT
} MoveDir;

/**
 * Initialize the maze and game state.
 * - Seeds RNG, clears the grid, scatters obstacles (0.0 .. 0.9 recommended),
 *   then places player and treasure on empty cells (different tiles).
 *
 * @param gs                 Pointer to game state (must not be NULL).
 * @param obstacle_density   Fraction of cells to become obstacles.
 */
void game_init(GameState *gs, float obstacle_density);

/**
 * Check win condition.
 * @return true if player position equals treasure position.
 */
bool game_is_won(const GameState *gs);

/**
 * Try to move the player by one tile in the given direction.
 * - Move succeeds only if the target cell is inside bounds and not an obstacle.
 * - On success, updates g_maze to reflect the new player position.
 *
 * @return true if the player moved; false if blocked.
 */
bool game_try_move(GameState *gs, MoveDir dir);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // GAME_H