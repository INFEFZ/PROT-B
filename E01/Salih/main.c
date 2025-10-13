#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "labyrinth.h"

int main(int argc, char** argv) {
    /* Zufallszahl-Seed */
    srand((unsigned)time(NULL));

    int rows = 10;
    int cols = 10;
    double ratio = 0.15;   /* 15% Hindernisse */

    /* Parameter aus Kommandozeile übernehmen */
    if (argc >= 3) {
        rows = atoi(argv[1]);
        cols = atoi(argv[2]);
    }
    if (argc >= 4) {
        ratio = atof(argv[3]);
    }

    /* Labyrinth erstellen */
    Maze* m = maze_create(rows, cols, ratio);
    if (!m) {
        fprintf(stderr, "Fehler: Labyrinth konnte nicht erstellt werden.\n");
        return 1;
    }

    /* Hauptspielschleife */
    while (1) {
        maze_clear_screen();
        maze_draw(m);

        if (maze_is_on_treasure(m)) {
            printf("\nHerzlichen Glückwunsch! Du hast alle Schätze gefunden!\n");
            printf("Enter zum Beenden...");
            getchar(); /* wartet auf Enter */
            break;
        }

        printf("\nBewege den Spieler (W/A/S/D), Q=Beenden: ");
        char ch = 0;
        if (scanf(" %c", &ch) != 1) break;
        if (ch == 'q' || ch == 'Q') break;

        (void)maze_move(m, ch);
    }

    /* Speicher freigeben */
    maze_free(m);
    return 0;
}
