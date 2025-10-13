#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Labyrinth.h"
#include "Spieler.h"

// Spiel kann mit "make" compiliert und gestartet werden
// Farbige ausgabe wurde mit Google recherchiert


// Hauptprogramm
int main(void)
{
    srand((unsigned int)time(NULL));                        // Initialisiere Zufallsgenerator

    int zeilen = 10, spalten = 10, hindernisProzent = 20;   // Standardwerte

    printf("\n\n------- Labyrinth-Spiel -------\n\n");      // Titel des Spiels
    printf("Gib die Grösse des Feldes an (z.Bsp. 12 12). Leer lassen für Standardgrösse (10 x 10). \nWunschgrösse: ");      // Eingabeaufforderung

    int gelesen = 0;                                        // Variable, um zu überprüfen, ob eine gültige Größe eingegeben wurde
    char buf[64];                                           // Puffer für die Eingabe

    if (fgets(buf, sizeof(buf), stdin))                     // Lese die Eingabe
    {
        int z, s;                                           // Temporäre Variablen für Zeilen und Spalten
        if (sscanf(buf, "%d %d", &z, &s) == 2 && z >= 5 && z <= 99 && s >= 5 && s <= 99)        // Überprüfe, ob die Eingabe gültig ist
        {
            zeilen = z; spalten = s; gelesen = 1;           // Setze die Größe und markiere als gelesen
        }
    }

    if (gelesen)                                            // Wenn eine gültige Größe eingegeben wurde
    {
        printf("Eingelesene grösse des Labyrinths: %d x %d \n", zeilen, spalten);
    }

    if (!gelesen)                                           // Wenn keine gültige Größe eingegeben wurde
    {
        printf("Es wird die Standardgrösse %d x %d verwendet\n", zeilen, spalten);
    }



    printf("\n\nGewünschte Hindernisdichte in %% (10-50), Enter für Standardwert: ");       // Eingabeaufforderung für Hindernisdichte
if (fgets(buf, sizeof(buf), stdin))                         // Lese die Eingabe
{
    if (buf[0] != '\n')                                     // Prüfen, ob etwas eingegeben wurde
    {
        int p;
        if (sscanf(buf, "%d", &p) == 1 && p >= 10 && p <= 50)       // Gültige Eingabe. Wenn unter 10 Ist, wird 10 gesetzt. Wenn über 50, wird 50 gesetzt.
        {
            hindernisProzent = p;                           // Setze die Hindernisdichte
            printf("Hindernisdichte gesetzt auf: %d%%\n", hindernisProzent);        // Bestätigungsnachricht
        }
        else                                                // Ungültige Eingabe
        {
            printf("Ungültige Eingabe. Standardwert wird verwendet: %d%%\n", hindernisProzent);         // Fehlermeldung und Standardwert
        }
    }

    else                                                    // Benutzer hat nichts eingegeben
    {
        printf("Standardwert wird verwendet: %d%%\n", hindernisProzent);        // Bestätigungsnachricht für Standardwert
    }
}

    Labyrinth lab;                                          // Deklariere Labyrinth
    initialisiereLabyrinth(&lab, zeilen, spalten);          // Funktion zum Initialisieren des Labyrinths
    platziereHindernisse(&lab, hindernisProzent);           // Funktion zum Platzieren der Hindernisse
    platziereSchatz(&lab);                                  // Funktion zum Platzieren des Schatzes
    platziereSpieler(&lab);                                 // Funktion zum Platzieren des Spielers
    

// Hauptspielschleife

int zähler = 0;                                              // Zähler für die Anzahl der Züge
    for (;;)                                                 // Endlosschleife für das Spiel

    {
        char eingabe = '\0';                                 // Variable für die Benutzereingabe

        zeigeLabyrinth(&lab);                                // Zeige das Labyrinth an
        printf("\nSteuerung:\n W = Hoch \n A = Links \n S = Runter \n D = Rechts \n Q = Spiel abbrechen\n");        // Steuerungsanleitung
        printf("\nGib die Richtung deines nächsten Zugs ein: ");        // Eingabeaufforderung

        scanf(" %c", &eingabe);                              // Leerzeichen vor %c um Whitespace zu ignorieren. Lese die Eingabe

        int puffer;                                          // Variable zum Leeren des Eingabepuffers
        while ((puffer = getchar()) != '\n' && puffer != '\n')      // Eingabepuffer leeren


        {
        if (eingabe == '\0') continue;                      // Wenn keine Eingabe, erneut fragen
        }


        {
        if (eingabe == 'Q' || eingabe == 'q')               // Wenn 'Q' oder 'q' eingegeben wurde

            {
            printf("\033[1;31mSpiel abgebrochen. Bis zum nächsten Mal!\033[0m\n\n");        // Abbruchmeldung
            break;                                          // Beende die Schleife und somit das Spiel
            }
        }

        
        int res = spielerBewegen(&lab, eingabe, &zähler);   // Funktion zum Bewegen des Spielers, Ergebnis in res speichern
        if (res == 0)                                       // Ungültige Eingabe
       
        {
        printf("\033[1;31m\nUngültige Eingabe!\033[0m \nBitte W / A / S / D / Q eingeben\n");         // Fehlermeldung
        }

    else if (res == -1 || res == -2)                        // Ungültiger Zug (Wand oder Hindernis)

        {
                                                           // Hinweis wird in spielerBewegen() ausgegeben
        }


    else
    
        {
        if (schatzGefunden(&lab))                           // Wenn der Schatz gefunden wurde
        
            {
            zeigeLabyrinth(&lab);                           // Zeige das Labyrinth an


            // Glückwunsch-Nachricht mit Anzeige der benötigten Züge

            printf("\n\n\033[1;35m");
            printf("                   HERZLICHEN GLÜCKWUNSCH!\n");
            printf("-------------------------------------------------------------\n");
            printf("                   \\          |          / \n");
            printf("                    \\         |         / \n");
            printf("                     \\        |        / \n");
            printf("                      \\       |       / \n");
            printf("                       \\      |      / \n");
            printf("                        \\     |     / \n");
            printf("                         \\    |    / \n");
            printf("                          \\   |   / \n");
            printf("                           \\  |  / \n");
            printf("                            \\ | / \n");
            printf("                             \\|/ \n\n");
            printf("                             \\O/\n");
            printf("                              |\n");
            printf("                             / \\\n\n");            
            printf("               Du hast den  SCHATZ  gefunden!\n");
            printf("-------------------------------------------------------------\n");
            printf("                \033[1;33mAnzahl der benötigten Züge: %d\033[1;35m\n", zähler);
            printf("-------------------------------------------------------------\n");
            printf("\033[0m\n");
       

            break;                                          // Spiel beenden, wenn der Schatz gefunden wurde
            }
         }

    }

gibLabyrinthFrei(&lab);                                     // Funktion zum Freigeben des Labyrinths (Freigeben des malloc-Speichers)
return 0;                                                   // Beende das Programm
 
}

