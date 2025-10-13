#include <stdio.h>
#include <stdlib.h>
#include "Labyrinth.h"

// Labyrinth-Array
char labyrinth[ROWS][COLS] = {
    {'O','.','.','.','.','.','.','.','.','.'},
    {'.','O','O','.','.','.','.','.','O','.'},
    {'.','.','.','.','.','.','.','.','.','.'},
    {'.','.','O','O','O','.','.','.','.','.'},
    {'.','.','.','.','O','.','.','.','.','.'},
    {'.','.','.','.','.','O','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.'},
    {'O','.','.','.','.','.','.','.','.','O'}
};

// Spieler- und Schatzposition
int playerRow, playerCol;
int treasureRow, treasureCol;

// Funktion: Zeichnet das Labyrinth auf dem Bildschirm
void drawLabyrinth() {
    // Bildschirm löschen, abhängig vom Betriebssystem
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", labyrinth[i][j]);
        }
        printf("\n"); // Zeilenumbruch
    }
}

// Funktion: Platziert eine zufällige Position im Labyrinth
void placeRandom(int *row, int *col) {
    do {
        *row = rand() % ROWS;
        *col = rand() % COLS;
    } while (labyrinth[*row][*col] == OBSTACLE || 
             labyrinth[*row][*col] == PLAYER || 
             labyrinth[*row][*col] == TREASURE);
}

// Funktion: Bewegt den Spieler basierend auf der Eingabe
void movePlayer(char input) {
    int newRow = playerRow;
    int newCol = playerCol;

    // Prüfen der Eingabe und neue Position berechnen
    if (input == 'w' || input == 'W') newRow--;       // nach oben
    else if (input == 's' || input == 'S') newRow++;  // nach unten
    else if (input == 'a' || input == 'A') newCol--;  // nach links
    else if (input == 'd' || input == 'D') newCol++;  // nach rechts
    else return; // ungültige Eingabe, keine Bewegung

    // Prüfen, ob neue Position gültig ist und kein Hindernis
    if (newRow >= 0 && newRow < ROWS &&
        newCol >= 0 && newCol < COLS &&
        labyrinth[newRow][newCol] != OBSTACLE) {
        
        labyrinth[playerRow][playerCol] = EMPTY; // alte Position leeren
        playerRow = newRow;
        playerCol = newCol;
        labyrinth[playerRow][playerCol] = PLAYER; // Spieler setzen
    }
}
