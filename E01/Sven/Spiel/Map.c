#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Map.h"

// Globale Variable für die Map (Pointer auf Pointer)
char** map = NULL;

// Initialisiert das Map Modul (Zufallsgenerator)
void initMapModule() {
    srand(time(NULL));
}

// Speicher für die Map allozieren
void allocateMap(int Hoehe, int Breite) {
    map = (char**)malloc(Hoehe * sizeof(char*));          // Speicher für Zeilen reservieren
    for (int i = 0; i < Hoehe; i++) {
        map[i] = (char*)malloc(Breite * sizeof(char));   // Speicher für Spalten reservieren
    }
}

// Speicher für die Map freigeben
void freeMap(int Hoehe) {
    if (map != NULL) {
        for (int i = 0; i < Hoehe; i++) {
            free(map[i]);                               // Speicher für jede Zeile freigeben
        }
        free(map);                                      // Speicher für die Zeilenzeiger freigeben
        map = NULL;                                     // Pointer zurücksetzen
    }
}

// Routinen zum erstellen der Map
void createMap(int Hoehe, int Breite, char Hindernis, char Freiflaeche, int Werscheinlichkeit) {
    
    for (int h = 0; h < Hoehe; h++) {                    // Schleife für die Höhe    
        for (int b = 0; b < Breite; b++) {              // Schleife für die Breite
            if (rand() % 100 < Werscheinlichkeit) {     // Fülle die Map zu Werscheinlichkeit % mit inhalt aus Hindernis, sonst aus Freiflaeche
                map[h][b] = Hindernis;
            } else {
                map[h][b] = Freiflaeche;
            }
        }
    }
}

// Routinen zum plazieren des Spielers - Rückgabe der Position des Spielers
Position placePlayer(int Hoehe, int Breite, char Freiflaeche, char Spielers) {  

    int plaziert = 0;                                   // Marker ob plaziert
    Position pos;                                       // Position des Spielers initialisieren
   
    while (!plaziert) {                                 // Spieler plaziert?              
        int h = rand() % (Hoehe);                        // Zufallszahl für Höhe
        int b = rand() % (Breite);                      // Zufallszahl für Breite
        if (map[h][b] == Freiflaeche) {                 // Nur belegen wenn inhalt aus Position = char Freiflaeche
            map[h][b] = Spielers;                       // Spieler plazieren

            pos.x = h;                                  // Position speichern
            pos.y = b;

            plaziert = 1;                               // Schleife beenden
        
        }
    }
    return pos;
}

// Routinen zum plazieren des Schatzes - Rückgabe der Position des Schatzes
Position placeSchatz(int Hoehe, int Breite, char Hindernis, char Schatz, char Spielers) {  

    int plaziert = 0;                                   // Marker ob plaziert
    Position pos;                                       // Position des Schatzes initialisieren
   
    while (!plaziert) {                                 // Spieler plaziert?              
        int h = rand() % (Hoehe);                        // Zufallszahl für Höhe
        int b = rand() % (Breite);                      // Zufallszahl für Breite
        if (map[h][b] != Hindernis && map[h][b] != Spielers) { // Nur belegen wenn nicht Buchstabe i oder m
            map[h][b] = Schatz;                         // Schatz plazieren 

            pos.x = h;                                  // Position speichern
            pos.y = b;

            plaziert = 1;                               // Schleife beenden
        }
    }
    return pos;
}

// Routinen zum ausgeben der Map
void printMap(int Hoehe, int Breite) {
    printf("\n");                                       // Leere Zeile vor der Map    
    for (int i = 0; i < Hoehe; i++) {                    // Zeilen Schleife
        for (int j = 0; j < Breite; j++) {              // Spalten Schleife
            printf("%c ", map[i][j]);                   // Ausgabe Zeichen
        }
    printf("\n");                                       // Neue Zeile beginnen
    }
    printf("\n");                                       // Leere Zeile nach der Map
}

// Routinen zum updaten der Map (Bewegung des Spielers)
void updateMap(int Spieler_alt_Hoehe, int Spieler_alt_Breite, int Spieler_neu_Hoehe, int Spieler_neu_Breite, char Freiflaeche, char Spieler) {
    map[Spieler_alt_Hoehe][Spieler_alt_Breite] = Freiflaeche;     // Alte Position mit char Freifläche füllen
    map[Spieler_neu_Hoehe][Spieler_neu_Breite] = Spieler;        // Neue Position mit char Spieler füllen
}

// Kontrolliere/Mache die Bewegung des Spielers
int checkMap(int Hoehe, int Breite, int Spieler_alt_Hoehe, int Spieler_alt_Breite, int Spieler_neu_Hoehe, int Spieler_neu_Breite, char Hindernis, char Freiflaeche, char Spieler, char Schatz) {
    if (Spieler_neu_Hoehe < 0 || Spieler_neu_Hoehe >= Hoehe || Spieler_neu_Breite < 0 || Spieler_neu_Breite >= Breite) {                   // Ausserhalb der Map?
        return 0;                                                       // 0 == Bewegung nicht möglich Ausserhalb
    }
    else if (map[Spieler_neu_Hoehe][Spieler_neu_Breite] == Hindernis) { // Auf Hindernis?
        return 1;                                                       // 1 == Bewegung nicht möglich Hindernis
    }
    else if (map[Spieler_neu_Hoehe][Spieler_neu_Breite] == Schatz) {     // Auf Schatz? -> Map updaten
        updateMap( Spieler_alt_Hoehe, Spieler_alt_Breite, Spieler_neu_Hoehe, Spieler_neu_Breite, Freiflaeche, Spieler);
        return 2;                                                       // 2 == Spiel gewonnen
    } 
    else {                                                              // Kein Problem? -> Map updaten
        updateMap( Spieler_alt_Hoehe, Spieler_alt_Breite, Spieler_neu_Hoehe, Spieler_neu_Breite, Freiflaeche, Spieler);
        return 3;                                                       // 3 == Bewegung erfolgreich
    }
}