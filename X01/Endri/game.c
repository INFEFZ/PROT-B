#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "game.h"
#include "maze.h"

#ifdef _WIN32
#include <windows.h>
#endif

bool init_maze(Maze *m, int rows, int cols, int obstacle_percent) {
    if (!m) return false;
    m->rows = rows;
    m->cols = cols;
    m->cells = (char**)malloc(rows * sizeof(char*));
    if (!m->cells) return false;
    for (int r = 0; r < rows; ++r) {
        m->cells[r] = (char*)malloc(cols * sizeof(char));
        if (!m->cells[r]) return false;
        memset(m->cells[r], ' ', cols);
    }

    // Rand als Wände (optional visuell)
    for (int c = 0; c < cols; ++c) {
        m->cells[0][c] = 'O';
        m->cells[rows-1][c] = 'O';
    }
    for (int r = 0; r < rows; ++r) {
        m->cells[r][0] = 'O';
        m->cells[r][cols-1] = 'O';
    }

    place_obstacles(m, obstacle_percent);
    place_player_and_treasure(m);
    return true;
}

void free_maze(Maze *m) {
    if (!m || !m->cells) return;
    for (int r = 0; r < m->rows; ++r) {
        free(m->cells[r]);
    }
    free(m->cells);
    m->cells = NULL;
}

void draw_maze(const Maze *m) {
    if (!m) return;
    for (int r = 0; r < m->rows; ++r) {
        for (int c = 0; c < m->cols; ++c) {
            if (r == m->player_r && c == m->player_c) {
                putchar('P');
            } else if (r == m->treasure_r && c == m->treasure_c) {
                putchar('T');
            } else {
                putchar(m->cells[r][c]);
            }
        }
        putchar('\n');
    }
}

bool apply_move(Maze *m, Move mv) {
    if (!m) return false;
    int nr = m->player_r;
    int nc = m->player_c;

    switch (mv) {
        case MOVE_UP:    nr -= 1; break;
        case MOVE_LEFT:  nc -= 1; break;
        case MOVE_DOWN:  nr += 1; break;
        case MOVE_RIGHT: nc += 1; break;
        default: return false;
    }

    // Bounds check
    if (nr < 0 || nr >= m->rows || nc < 0 || nc >= m->cols) {
        return false;
    }
    // Hindernis?
    if (m->cells[nr][nc] == 'O') {
        return false;
    }

    // valide Bewegung
    m->player_r = nr;
    m->player_c = nc;
    return true;
}

bool is_victory(const Maze *m) {
    return m && (m->player_r == m->treasure_r) && (m->player_c == m->treasure_c);
}

void clear_screen(void) {
#ifdef _WIN32
    system("cls");
#else
    // ANSI Clear
    printf("\033[2J\033[H");
#endif
}

int rand_range(int min_inclusive, int max_inclusive) {
    int span = max_inclusive - min_inclusive + 1;
    if (span <= 0) return min_inclusive;
    return min_inclusive + (rand() % span);
}