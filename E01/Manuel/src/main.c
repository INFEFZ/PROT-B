#include <stdio.h>
#include "maze.h"
#include "game.h"

/*
    Simple console front-end for the maze game.

    Controls:
      - Use W/A/S/D (case-insensitive) to move the player 'P'.
      - Press 'q' or 'Q' to quit.
    Note:
      - Input is read via getchar(), so you must press ENTER after each key.
      - The grid is printed using g_maze[row][col] = g_maze[y][x].
*/

// Print the current maze to stdout (row-major: y outer, x inner).
static void print_maze(void) {
    for (int y = 0; y < MAZE_ROWS; ++y) {
        for (int x = 0; x < MAZE_COLS; ++x) {
            putchar(g_maze[y][x]);
        }
        putchar('\n');
    }
}

int main(void) {
    GameState gs;
    // Initialize the maze and place player/treasure using the configured density.
    game_init(&gs, OBSTACLE_DENSITY);

    for (;;) {
        // Clear screen and move cursor to top-left (ANSI escape sequence).
        printf("\x1b[2J\x1b[H");
        print_maze();

        // Win condition: player and treasure share the same cell.
        if (game_is_won(&gs)) {
            puts("\n Congratulations, you found the treasure! \n");
            break;
        }

        // Read a command from the user (requires pressing ENTER with getchar()).
        puts("\nMove with [W/A/S/D], quit with [q]:");
        int c = getchar();
        if (c == 'q' || c == 'Q') break;

        // Attempt a move (case-insensitive checks).
        if (c == 'w' || c == 'W') game_try_move(&gs, MOVE_UP);
        else if (c == 's' || c == 'S') game_try_move(&gs, MOVE_DOWN);
        else if (c == 'a' || c == 'A') game_try_move(&gs, MOVE_LEFT);
        else if (c == 'd' || c == 'D') game_try_move(&gs, MOVE_RIGHT);

        // Flush the rest of the line so the next getchar() gets a fresh key.
        while (c != '\n' && c != EOF) c = getchar();
    }
    return 0;
}
