#include "labyrinth.h"
#include <stdio.h>
#include <stdlib.h>

/* Symbole für die Darstellung im Labyrinth */
static const char EMPTY  = '.';  // freies Feld
static const char OBST   = 'O';  // Hindernis
static const char PLAYER = 'P';  // Spieler
static const char TREAS  = 'T';  // Schatz

/* --------------------------------------------------------
   Hilfsfunktion: Hindernisse zufällig verteilen
   ratio = Anteil der Hindernisse im Spielfeld
   Es wird darauf geachtet, dass immer freie Felder bleiben.
-------------------------------------------------------- */
static void fill_obstacles(Maze* m, double ratio) {
    int free_cnt = 0;
    for (int r = 0; r < m->rows; r++) {
        for (int c = 0; c < m->cols; c++) {
            if (((double)rand() / RAND_MAX) < ratio) {
                m->cells[r][c] = OBST;
            } else {
                m->cells[r][c] = EMPTY;
                free_cnt++;
            }
        }
    }

    // Falls alles zu voll ist → alles freimachen
    if (free_cnt < 2) {
        for (int r = 0; r < m->rows; r++) {
            for (int c = 0; c < m->cols; c++) {
                m->cells[r][c] = EMPTY;
            }
        }
    }
}

/* --------------------------------------------------------
   Hilfsfunktion: zufällige freie Position finden
   (wird genutzt für Spieler und Schatz)
-------------------------------------------------------- */
static Position random_free(const Maze* m) {
    while (1) {
        int r = rand() % m->rows;
        int c = rand() % m->cols;
        if (m->cells[r][c] == EMPTY) {
            Position p = { r, c };
            return p;
        }
    }
}

/* --------------------------------------------------------
   Maze erzeugen:
   - Speicher anlegen
   - Hindernisse setzen
   - Spieler & Schatz platzieren
-------------------------------------------------------- */
Maze* maze_create(int rows, int cols, double obstacle_ratio) {
    if (rows < 3) rows = 3;
    if (cols < 3) cols = 3;
    if (obstacle_ratio < 0.0) obstacle_ratio = 0.0;
    if (obstacle_ratio > 0.6) obstacle_ratio = 0.6;

    Maze* m = (Maze*)malloc(sizeof(Maze));
    if (!m) return NULL;

    m->rows = rows;
    m->cols = cols;

    // Speicher für 2D-Array anlegen
    m->cells = (char**)malloc(rows * sizeof(char*));
    if (!m->cells) {
        free(m);
        return NULL;
    }
    for (int r = 0; r < rows; r++) {
        m->cells[r] = (char*)malloc(cols * sizeof(char));
        if (!m->cells[r]) {
            for (int i = 0; i < r; i++) free(m->cells[i]);
            free(m->cells);
            free(m);
            return NULL;
        }
    }

    // Hindernisse setzen
    fill_obstacles(m, obstacle_ratio);

    // Spieler und Schatz platzieren
    m->player = random_free(m);
    m->cells[m->player.row][m->player.col] = PLAYER;

    do {
        m->treasure = random_free(m);
    } while (m->treasure.row == m->player.row && m->treasure.col == m->player.col);

    m->cells[m->treasure.row][m->treasure.col] = TREAS;

    return m;
}

/* --------------------------------------------------------
   Speicher freigeben
-------------------------------------------------------- */
void maze_free(Maze* m) {
    if (!m) return;
    for (int r = 0; r < m->rows; r++) {
        free(m->cells[r]);
    }
    free(m->cells);
    free(m);
}

/* --------------------------------------------------------
   Labyrinth zeichnen
-------------------------------------------------------- */
void maze_draw(const Maze* m) {
    for (int r = 0; r < m->rows; r++) {
        for (int c = 0; c < m->cols; c++) {
            putchar(m->cells[r][c]);
            putchar(' ');
        }
        putchar('\n');
    }
}

/* --------------------------------------------------------
   Bildschirm löschen (Windows/Linux kompatibel)
-------------------------------------------------------- */
void maze_clear_screen(void) {
#ifdef _WIN32
    system("cls");
#else
    printf("\033[2J\033[H");
#endif
}

/* --------------------------------------------------------
   Hilfsfunktion: Prüft, ob eine Position im Spielfeld liegt
-------------------------------------------------------- */
static int in_bounds(const Maze* m, int r, int c) {
    return (r >= 0 && c >= 0 && r < m->rows && c < m->cols);
}

/* --------------------------------------------------------
   Spieler bewegen
   - Eingaben: W/A/S/D
   - Blockierte Felder (Hindernisse) werden ignoriert
-------------------------------------------------------- */
int maze_move(Maze* m, char input) {
    int dr = 0, dc = 0;
    if (input == 'w' || input == 'W') dr = -1;
    else if (input == 's' || input == 'S') dr = +1;
    else if (input == 'a' || input == 'A') dc = -1;
    else if (input == 'd' || input == 'D') dc = +1;
    else return 0;

    int nr = m->player.row + dr;
    int nc = m->player.col + dc;

    if (!in_bounds(m, nr, nc)) return 0;     // außerhalb des Spielfelds
    if (m->cells[nr][nc] == OBST) return 0;  // Hindernis blockiert

    // alte Zelle freigeben (außer Schatz-Zelle)
    if (!(m->player.row == m->treasure.row && m->player.col == m->treasure.col)) {
        m->cells[m->player.row][m->player.col] = EMPTY;
    }

    // neue Position setzen
    m->player.row = nr;
    m->player.col = nc;

    if (!(nr == m->treasure.row && nc == m->treasure.col)) {
        m->cells[nr][nc] = PLAYER;
    }

    return 1;
}

/* --------------------------------------------------------
   Prüfen, ob Spieler auf dem Schatz steht
-------------------------------------------------------- */
int maze_is_on_treasure(const Maze* m) {
    return (m->player.row == m->treasure.row &&
            m->player.col == m->treasure.col);
}
