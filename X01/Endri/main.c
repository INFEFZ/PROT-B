/**
 * Labyrinth - Konsolenspiel in C
 * HF Elektrotechnik / IBZ – Praxisarbeit Programmiertechnik A & B
 *
 * Features:
 * - Zufälliges Labyrinth mit Hindernissen 'O'
 * - Spieler 'P' sammelt Schatz 'T'
 * - Steuerung mit W/A/S/D + Return
 * - Robuste Eingabeprüfung
 * - Dynamische Speicherverwaltung
 *
 * Build:
 *   make            # erstellt ./labyrinth
 *   ./labyrinth     # startet das Spiel
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "input.h"

static void print_intro(void) {
    puts("========================================");
    puts("         LABYRINTH: SCHATZSUCHE         ");
    puts("========================================");
    puts("Steuerung: W=hoch, A=links, S=runter, D=rechts (Enter drücken)");
    puts("Ziel: Erreiche den Schatz 'T'. Hindernisse sind 'O'.");
    puts("Viel Erfolg!\n");
}

int main(int argc, char **argv) {
    // Default-Parameter (können beim Start angepasst werden)
    int rows = 12;
    int cols = 24;
    int obstacle_percent = 18; // 18% der Felder sind Hindernisse

    if (argc == 4) {
        rows = atoi(argv[1]);
        cols = atoi(argv[2]);
        obstacle_percent = atoi(argv[3]);
        if (rows < 5) rows = 5;
        if (cols < 5) cols = 5;
        if (obstacle_percent < 0) obstacle_percent = 0;
        if (obstacle_percent > 40) obstacle_percent = 40;
    }

    srand((unsigned)time(NULL));

    Maze m = {0};
    if (!init_maze(&m, rows, cols, obstacle_percent)) {
        fprintf(stderr, "Fehler: Maze konnte nicht initialisiert werden.\n");
        return 1;
    }

    print_intro();
    draw_maze(&m);

    while (1) {
        Move mv = read_move_from_stdin();
        if (mv == MOVE_INVALID) {
            puts("Ungültige Eingabe. Bitte W/A/S/D verwenden und Enter drücken.");
            continue;
        }

        if (apply_move(&m, mv)) {
            clear_screen();
            draw_maze(&m);
            if (is_victory(&m)) {
                puts("\n🎉 Glückwunsch! Du hast den Schatz gefunden! 🎉");
                break;
            }
        } else {
            puts("Autsch! Da ist ein Hindernis oder die Wand. Versuch was anderes.");
        }
    }

    free_maze(&m);
    return 0;
}