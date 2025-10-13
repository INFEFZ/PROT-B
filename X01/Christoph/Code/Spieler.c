#include <stdio.h>
#include <stdlib.h>
#include "Spieler.h"
#include "Labyrinth.h"


// Funktion zum Bewegen des Spielers im Labyrinth
// Rückgabewerte:
//  1 : erfolgreicher Zug
//  2 : erfolgreicher Zug auf Schatzfeld
//  0 : ungültige Eingabe
// -1 : ungültiger Zug (ausserhalb des Labyrints)
// -2 : ungültiger Zug (Hindernis)
int spielerBewegen(Labyrinth *lab, char richtung, int *zähler)
{
    int nx = lab->spielerPosX;                                              // Neue X-Position
    int ny = lab->spielerPosY;                                              // Neue Y-Position
    
   
    switch (richtung)                                                       // Bestimme die neue Position basierend auf der Eingabe
    {
        case 'W' : case 'w' : nx--; break;                                  // Nach oben bewegen
        case 'S' : case 's' : nx++; break;                                  // Nach unten bewegen
        case 'A' : case 'a' : ny--; break;                                  // Nach links bewegen
        case 'D' : case 'd' : ny++; break;                                  // Nach rechts bewegen
        case 'Q' : case 'q' : exit(0) ; break;                              // Spiel beenden
        default  : return 0;                                                // ungültige Tasteneingabe
    }


    // Rand überprüfen
    if (nx < 0 || nx >= lab->zeilen || ny < 0 || ny >= lab->spalten)        // Außerhalb der Labyrinthgrenzen
    {
        printf("\033[1;31mBewegung ausserhalb des Labyrints!\033[0m\n");    // Fehlermeldung
        return -1;                                                          // Rückgabe -1 für ungültigen Zug
    }



    // Auf Hinderniss prüfen
    if (lab->feld [nx][ny] == 'O')                                          // Hindernis
    {
        printf("\033[1;31mDu bist auf ein Hindernis gestossen\033[0m\n");   // Fehlermeldung
        return -2;                                                          // Rückgabe -2 für ungültigen Zug
    }



// Altes Feld wieder freigeben
    lab->feld[lab->spielerPosX][lab->spielerPosY] = '.';                    // Setze das alte Feld auf frei ('.')

// Neue Position setzen
    lab->spielerPosX = nx;                                                  // Setze die neue X-Position
    lab->spielerPosY = ny;                                                  // Setze die neue Y-Position
    lab-> feld[nx][ny] = 'P';                                               // Platziere den Spieler an der neuen Position

    (*zähler)++;                                                            // Aktueller Zählerstand um 1 erhöhen



// Erfolg (2, falls theoretisch auf Schatzfeld gelandet)
    if (nx == lab->schatzPosX && ny == lab->schatzPosY) return 2;           // Schatz gefunden
    return 1;
}


// Funktion, um zu prüfen, ob der Schatz gefunden wurde
int schatzGefunden(const Labyrinth *lab)
{
    return (lab->spielerPosX == lab->schatzPosX && lab->spielerPosY == lab->schatzPosY); // Überprüfe, ob die Spielerposition mit der Schatzposition übereinstimmt
}