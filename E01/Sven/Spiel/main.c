#include <stdio.h>                      // Standard Ein/Ausgabe
#include <stdlib.h>                     // Standard Bibliothek

#include "Map.h"                        // Map Modul

#define Spieler 'P'                     // Char für Spieler
#define Schatz 'T'                      // Char für Schatz
#define Hindernis 'O'                   // Char für Hindernis
#define Freiflaeche '.'                 // Char für freie Fläche
#define Restart '1'                     // Char für Restart
#define Abbruch '0'                     // Char für Abbruch

#define Hoch1 'w'                       // Char 1 für Hoch
#define Runter1 's'                     // Char 1 für Runter
#define Links1 'a'                      // Char 1 für Links
#define Rechts1 'd'                     // Char 1 für Rechts

#define Hoch2 'W'                       // Char 2 für Hoch
#define Runter2 'S'                     // Char 2 für Runter
#define Links2 'A'                      // Char 2 für Links
#define Rechts2 'D'                     // Char 2 für Rechts

#define WarscheinlichkeitHindernis 12   // Warscheinlichkeit eines Hindernisses in Prozent

#define Hoehe 15                        // Höhe der Map - Positiv < 1
#define Breite 15                       // Breite der Map - Positiv < 1


int runGame();                          // Prototyp der runGame Funktion

char input;                             // Zwischenspeicher für die Eingabe


int main() {
// Startnachricht
    printf("\nWillkommen zum Schatzsuchspiel!\n");
    printf("Ziel: Finde den Schatz '%c' auf der Karte.\n", Schatz);
    printf("Steuere den Spieler '%c' durch Eingabe von '%c/%c' (Hoch), '%c/%c' (Links), '%c/%c' (Runter), '%c/%c' (Rechts).\n", Spieler, Hoch1, Hoch2, Links1, Links2, Runter1, Runter2, Rechts1, Rechts2);
    printf("Vermeide Hindernisse '%c'.\n", Hindernis);
    printf("Gib '%c' ein um das Spiel zu beenden oder '%c' um neu zu starten.\n", Abbruch, Restart);
    printf("Viel Erfolg!\n");

    initMapModule();                    // Initialisiert das Map Modul (Zufallsgenerator)
    allocateMap(Hoehe, Breite);         // Map-Speicher Reservieren bei Programmstart


    int restart = 0;

        while (1) {                     // Spiel ausführen solange(1)
            restart = runGame();        // runGame Ausführen und Return abwarten
            if (restart != 0) break;    // Restarten bei Return(0)
        }
    
    freeMap(Hoehe);                     // Speicher Freigeben - Bei Programmende
    
    return 0;                           // Alle Instanzen beenden
}




int runGame() {

// Map erstellen/befüllen
    createMap(Hoehe, Breite, Hindernis, Freiflaeche, WarscheinlichkeitHindernis); 

    Position player = placePlayer(Hoehe, Breite, Freiflaeche, Spieler); // Spieler plazieren und Position speichern
        printf("Spieler ist auf Position %d - %d.\n", player.x+1, player.y+1);

    Position schatz = placeSchatz(Hoehe, Breite, Hindernis, Schatz, Spieler); // Schatz plazieren und Position speichern
        printf("Schatz ist auf Position %d - %d.\n", schatz.x+1, schatz.y+1);

        // Karte ausgeben
        printMap(Hoehe, Breite); 

    while (1) {

        // Eingabe(n) des Spielers anfragen und Speichern
        printf( "Bewege den Spieler mit\n"
        "( %c/%c - Auf || %c/%c - Links || %c/%c - Ab || %c/%c - Rechts )\n"
        "( %c = Spiel Beenden || %c = Restart): \n\n",
        Hoch1, Hoch2, Links1, Links2, Runter1, Runter2, Rechts1, Rechts2, Abbruch, Restart);
        scanf(" %c", &input); // Leerzeichen vor %c ignoriert Whitespaces wie '\n'

        // Position des Spielers zwischenspeichern für Bearbeitung bewegung
        Position newPos = player;

        // Eingabe verarbeiten
        if      (input == Hoch1   || input == Hoch2  )  newPos.x--;
        else if (input == Runter1 || input == Runter2)  newPos.x++;
        else if (input == Links1  || input == Links2 )  newPos.y--;
        else if (input == Rechts1 || input == Rechts2)  newPos.y++;

        else if (input == Abbruch) {  // Abbruch Funktion
            printf("\nSpiel wird beendet.\n\n");
            return 1;   // Beende alle Instanzen
        }

        else if (input == Restart) {  // Restart Funktion
            printf("\nSpiel wird neu gestartet.\n\n");
            break;   // Startet die aktuelle Main Instanz neu
        }
        
        
        else {                        // letzte option - Ungültige Eingabe
            printf("\nUngültige Eingabe!\n\n");
            continue;
        }

        // Switch für die Reaktion auf die Bewegung 
        switch (checkMap(Hoehe, Breite, player.x, player.y, newPos.x, newPos.y, Hindernis, Freiflaeche, Spieler, Schatz)) {
            case 0: // Fehler Rand
                printf("\nUngültiger Zug! Rand. \n");
                printMap(Hoehe, Breite);                    // Karte ausgeben
                continue;                                   // Weiter
            case 1: // Fehler Hinderniss
                printf("\nUngültiger Zug! Hindernis. < %c >\n", Hindernis);
                printMap(Hoehe, Breite);                    // Karte ausgeben
                continue;                                   // Weiter
            case 2: // Gewonnen
                printMap(Hoehe, Breite);                    // Karte ausgeben
                printf("Herzlichen Glückwunsch! Du hast den Schatz gefunden!\n\n");
                return 1;                                   // Beendet alle Instanzen
            case 3: // Bewegung erfolgreich
                printMap(Hoehe, Breite);                    // Karte ausgeben
                player.x = newPos.x;                        // Update Spieler Position
                player.y = newPos.y;                        // Update Spieler Position
                continue;                                   // Weiter
        }
    }
    return 0;
}
