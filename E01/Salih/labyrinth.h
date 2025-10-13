#ifndef LABYRINTH_H
#define LABYRINTH_H

/* Position im Labyrinth (Koordinaten) */
typedef struct {
    int row;   // Zeile
    int col;   // Spalte
} Position;

/* Datenstruktur für das Labyrinth */
typedef struct {
    int rows, cols;       // Dimensionen des Labyrinths
    char **cells;         // Dynamisches 2D-Array für Spielfelder
    Position player;      // Aktuelle Position des Spielers
    Position treasure;    // Position des Schatzes
} Maze;

/* === Funktionen zur Erzeugung und Freigabe === */

/**
 * Erzeugt ein neues Labyrinth mit der gegebenen Größe und Hindernisrate.
 * rows  = Anzahl Zeilen
 * cols  = Anzahl Spalten
 * obstacle_ratio = Anteil der Hindernisse (z. B. 0.15 für 15%)
 * Rückgabe: Pointer auf Maze-Struktur oder NULL bei Fehler
 */
Maze* maze_create(int rows, int cols, double obstacle_ratio);

/**
 * Gibt den Speicher eines Labyrinths wieder frei.
 */
void maze_free(Maze* m);

/* === Funktionen zur Anzeige und Steuerung === */

/**
 * Zeichnet das Labyrinth auf die Konsole.
 */
void maze_draw(const Maze* m);

/**
 * Löscht den Bildschirm (Konsolenausgabe zurücksetzen).
 */
void maze_clear_screen(void);

/* === Spiellogik === */

/**
 * Bewegt den Spieler im Labyrinth basierend auf einer Eingabe.
 * Eingaben: 'W' = hoch, 'A' = links, 'S' = runter, 'D' = rechts
 * Rückgabe: 1 = Bewegung erfolgreich, 0 = blockiert oder ungültig
 */
int maze_move(Maze* m, char direction);

/**
 * Prüft, ob der Spieler auf der Schatz-Position steht.
 * Rückgabe: 1 = Spieler auf Schatz, 0 = noch nicht
 */
int maze_is_on_treasure(const Maze* m);

#endif
