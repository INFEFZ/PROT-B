#include <stdlib.h>
#include "maze.h"
#include "game.h"

void place_obstacles(Maze *m, int obstacle_percent) {
    int inner_cells = (m->rows - 2) * (m->cols - 2);
    int target = inner_cells * obstacle_percent / 100;
    int placed = 0;
    while (placed < target) {
        int r = rand_range(1, m->rows - 2);
        int c = rand_range(1, m->cols - 2);
        if (m->cells[r][c] == ' ') {
            m->cells[r][c] = 'O';
            placed++;
        }
    }
}

static void pick_empty_cell(const Maze *m, int *out_r, int *out_c) {
    while (1) {
        int r = rand_range(1, m->rows - 2);
        int c = rand_range(1, m->cols - 2);
        if (m->cells[r][c] == ' ') {
            *out_r = r;
            *out_c = c;
            return;
        }
    }
}

void place_player_and_treasure(Maze *m) {
    pick_empty_cell(m, &m->player_r, &m->player_c);
    pick_empty_cell(m, &m->treasure_r, &m->treasure_c);
    // Sicherstellen, dass Start nicht direkt auf Schatz liegt
    if (m->player_r == m->treasure_r && m->player_c == m->treasure_c) {
        pick_empty_cell(m, &m->treasure_r, &m->treasure_c);
    }
}