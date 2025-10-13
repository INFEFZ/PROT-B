#include <assert.h>
#include <stdio.h>
#include "../labyrinth.h"

int main(void) {
    // --- Test 1: Bewegung in einem leeren Labyrinth ---
    Maze *m = maze_create(5, 5, 0.0);   // leeres Labyrinth (0% Hindernisse)
    assert(m);

    // Spieler muss nach rechts im Feld bleiben
    (void)maze_move(m, 'd');
    assert(m->player.col >= 0 && m->player.col < m->cols);
    assert(m->player.row >= 0 && m->player.row < m->rows);

    // Viele Links-Schritte -> am linken Rand stoppen
    for (int i = 0; i < 50; i++) (void)maze_move(m, 'a');
    assert(m->player.col == 0);

    // Viele Oben-Schritte -> am oberen Rand stoppen
    for (int i = 0; i < 50; i++) (void)maze_move(m, 'w');
    assert(m->player.row == 0);

    // Viele Unten-Schritte -> am unteren Rand stoppen
    for (int i = 0; i < 50; i++) (void)maze_move(m, 's');
    assert(m->player.row == m->rows - 1);

    maze_free(m);

    // --- Test 2: Hindernisse ---
    Maze *m2 = maze_create(5, 5, 0.5);  // 50% Hindernisse
    assert(m2);

    // Versuch: nach links bewegen -> Spieler bleibt gültig im Spielfeld
    (void)maze_move(m2, 'a');
    assert(m2->player.row >= 0 && m2->player.row < m2->rows);
    assert(m2->player.col >= 0 && m2->player.col < m2->cols);

    maze_free(m2);

    printf("Alle Tests erfolgreich bestanden! ✅\n");
    return 0;
}
