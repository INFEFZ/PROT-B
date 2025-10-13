#ifndef LABYRINTH_H
#define LABYRINTH_H

// Größe des Labyrinths definieren
#define ROWS 8      // Anzahl der Zeilen
#define COLS 10     // Anzahl der Spalten

// Symbole im Labyrinth
#define PLAYER 'P'     // Spieler
#define TREASURE 'T'   // Schatz
#define EMPTY '.'      // Leeres Feld
#define OBSTACLE 'O'   // Hindernis

// Externe Variablen -> Labyrinth.c
extern char labyrinth[ROWS][COLS]; // Labyrinth-Array
extern int playerRow, playerCol;   // Position des Spielers
extern int treasureRow, treasureCol; // Position des Schatzes

// Funktionsdeklarationen

/*
 * Zeichnet das Labyrinth auf dem Bildschirm
 */
void drawLabyrinth();

/*
 * Platziert eine zufällige Position im Labyrinth )
 * row: Zeiger auf Zeilenvariable
 * col: Zeiger auf Spaltenvariable
 */
void placeRandom(int *row, int *col);

/*
 * Bewegt den Spieler basierend auf der Eingabe:
 * W = oben, S = unten, A = links, D = rechts
 */
void movePlayer(char input);

#endif
