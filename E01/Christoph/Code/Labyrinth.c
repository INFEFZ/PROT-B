#include <stdio.h>
#include <stdlib.h>
#include "Labyrinth.h"


// Funktion zum Initialisieren des Labyrinths
void initialisiereLabyrinth(Labyrinth *lab, int zeilen, int spalten)
{
    lab->zeilen = zeilen;                                                       // Zeilenanzahl setzen
    lab->spalten = spalten;                                                     // Spaltenanzahl setzen

    lab-> feld = (char **)malloc(zeilen * sizeof(char *));                      // Speicher für Zeilen reservieren
    for (int i = 0; i < zeilen; i++)
    
    {
        lab->feld[i] = (char *)malloc(spalten * sizeof(char));                  // Speicher für Spalten reservieren
        for (int j = 0; j < spalten; j++) 
        
        {
            lab->feld[i][j] = '.';                                              // Leeres Feld initialisieren
        }

    }


    lab->spielerPosX = lab->spielerPosY = -1;                                   // Spielerposition initialisieren
    lab->schatzPosX = lab->schatzPosY = -1;                                     // Schatzposition initialisieren


}


// Funktion um Hinderniss zu platzieren
void platziereHindernisse(Labyrinth *lab, int hindernisProzent)
{
if (hindernisProzent < 0) hindernisProzent = 0;                                 // Begrenzung auf 0%
if (hindernisProzent > 80) hindernisProzent = 80;                               // Begrenzung auf 80% (Labyrinth soll lösbar sein)


int HindAnzahlSoll = (lab->zeilen * lab->spalten * hindernisProzent) / 100;     // Berechne die Anzahl der Hindernisse basierend auf dem Prozentsatz


for (int HindAnzahlIst = 0; HindAnzahlIst < HindAnzahlSoll;)                    // for (int anzahlIst = 0; anzahlIst < anzahl ++anzahlIst)



    {
        int r = rand() % lab->zeilen;                                           // Zufällige Zeile
        int c = rand() % lab->spalten;                                          // Zufällige Spalte

        if (lab->feld[r][c] == '.')                                             // Nur platzieren, wenn das Feld frei ist
        {
            lab->feld[r][c] = 'O';                                              // Hinderniss platzieren
            HindAnzahlIst++;                                                    // HindernissAnzahlIst um 1 erhöhen

        }

    }

}



// Funktionen zum Platzieren von Spieler
void platziereSpieler(Labyrinth *lab)
{
    int r, c;                                                                   // Zufällige Position für den Spieler
    do                                                                          // Schleife, um eine freie Position zu finden
    {
        r = rand() % lab->zeilen;                                               // Zufällige Zeile
        c = rand() % lab->spalten;                                              // Zufällige Spalte
    }

    while (lab->feld[r][c] != '.');                                             // Wiederhole, bis ein freies Feld gefunden wird
    lab->spielerPosX = r;                                                       // Setze die Spielerposition
    lab->spielerPosY = c;                                                       // Setze die Spielerposition
    lab->feld[r][c] = 'P';                                                      // Platziere den Spieler im Labyrinth
}


// Funktionen zum Platzieren von Schatz
void platziereSchatz(Labyrinth *lab)
{
    while (1)                                                                   // Endlosschleife, bis ein freies Feld gefunden wird
    {
        int r = rand() % lab->zeilen;                                           // Zufällige Zeile
        int c = rand() % lab->spalten;                                          // Zufällige Spalte

        if (lab->feld[r][c] == '.')                                             // Nur platzieren, wenn das Feld frei ist
        {
            lab->feld[r][c] = 'T';                                              // Schatz platzieren
            lab->schatzPosX = r;                                                // Setze die Schatzposition
            lab->schatzPosY = c;                                                // Setze die Schatzposition
            break;                                                              // Beende die Schleife, wenn der Schatz platziert wurde
        }
    }
}



//Farbig
//zeigeLabyrinth
void zeigeLabyrinth(const Labyrinth *lab)
{
    // Zeige Legende
    printf("-------------------------------------------------------------\n");
    printf("\nLegende:\n");
    printf(" \033[1;32mP\033[0m = Spieler\n");              // Zeige Spieler in Grün
    printf(" \033[1;34mT\033[0m = Schatz\n");               // Zeige Schatz in Blau
    printf(" \033[1;31mO\033[0m = Hindernis\n");            // Zeige Hindernis in Rot
    printf(" . = frei\n\n");


    // Zeige das Labyrinth mit Farben an

    for (int i = 0; i < lab->zeilen; ++i)                   // Gehe jede Zeile durch
    {
        for (int j = 0; j < lab->spalten; ++j)              // Gehe jede Spalte durch
        {
            char feld = lab->feld[i][j];                    // Aktuelles Feld
            switch (feld)                                   // Wähle die Farbe basierend auf dem Feldtyp
            {
                case 'P':
                    printf("\033[1;32m%c\033[0m ", feld);   // Grün
                    break;
                case 'T':
                    printf("\033[1;34m%c\033[0m ", feld);   // Blau
                    break;
                case 'O':
                    printf("\033[1;31m%c\033[0m ", feld);   // Rot
                    break;
                default:
                    printf("%c ", feld);                    // Normal
                    break;
            }
        }
        printf("\n");
    }
}




// Zugewiesenen Speicher freigeben
void gibLabyrinthFrei(Labyrinth *lab)
{
    if (!lab || !lab->feld) return;                         // Überprüfe, ob lab oder lab->feld NULL ist
    for (int i = 0; i < lab->zeilen; ++i)                   // Gehe jede Zeile durch
    {
        free(lab->feld[i]);                                 // Speicher für jede Zeile freigeben
    }

    free(lab->feld);                                        // Speicher für das Feld freigeben
    lab->feld = NULL;                                       // Setze den Zeiger auf NULL, um Dangling Pointer zu vermeiden
}
