#ifndef MAP_H
#define MAP_H

// Struktur für die Position
typedef struct { 
    int x;
    int y;
} Position;

/**
* Initialisiert das Map Modul
* Muss vor allen anderen Funktionen aufgerufen werden
*/
void initMapModule();

/**
 * Speicher allozieren für die Map
 * 
 * @param Hoehe      Anzahl Zeilen
 * @param Breite    Anzahl Spalten
 */
void allocateMap(int Hoehe, int Breite);

/**
 * Speicher freigeben für die Map
 * 
 * @param Hoehe      Anzahl Zeilen
 */
void freeMap(int Hoehe);

/**
 * Erstellt eine Karte mit den Dimensionen Höhe und Breite
 * Füllt das Array zu Werscheinlichkeit in % mit dem inhalt von 'Hindernis' 
 * Füllt den rest mit dem inhalt von 'Freiflaeche'
 * 
 * @param Hoehe                  Grösse des Arrays - map[Höhe][Breite] 
 * @param Breite                Anz. Zeichen im Array - map[Höhe][Breite]
 * @param Hindernis             Inhalt für Hindernisse auf der Map - m% Wahrscheinlichkeit
 * @param Freiflaeche           Inhalt für Freiflaeche auf der Map
 * @param Werscheinlichkeit     Prozentualer Anteil an Hindernissen
 */
void createMap(int Hoehe, int Breite, char Hindernis, char Freiflaeche, int Werscheinlichkeit);

/**
 * Nimmt die Karte mit den Dimensionen Höhe und Breite
 * Generiert die Position der Spielers zufällig 
 * Plaziert den Spieler wenn da kein Hindernis oder Schatz ist
 * Giebt die Position des Spielers zurück
 * 
 * @param Hoehe                  Grösse des Arrays - map[Höhe][Breite] 
 * @param Breite                Anz. Zeichen im Array - map[Höhe][Breite]
 * @param Freiflaeche           Inhalt für Freiflaeche auf der Map
 * @param Spielers              Inhalt des Spielers auf der Map
 */
Position placePlayer(int Hoehe, int Breite, char Freiflaeche, char Spielers);

/**
 * Nimmt die Karte mit den Dimensionen Höhe und Breite
 * Generiert die Position der Schatzes zufällig 
 * Plaziert den Schatz wenn da kein Hindernis oder Spieler ist
 * Giebt die Position des Schatzes zurück
 * 
 * @param Hoehe                  Grösse des Arrays - map[Höhe][Breite] 
 * @param Breite                Anz. Zeichen im Array - map[Höhe][Breite]
 * @param Hindernis             Inhalt für Hindernis auf der Map
 * @param Schatz                Inhalt des Schatz auf der Map
 * @param Spielers              Inhalt des Spielers auf der Map
 * 
 */
Position placeSchatz(int Hoehe, int Breite, char Hindernis, char Schatz, char Spielers);

/**
 * Gibt ein Char Array mit den Dimensionen Höhe * Breite auf der Konsole aus
 * Höhe = Zeilen
 * Breite = Spalten
 * 
 * @param Hoehe                  Grösse des Arrays - map[Höhe][Breite] 
 * @param Breite                Anz. Zeichen im Array - map[Höhe][Breite]
 */
void printMap(int Hoehe, int Breite);

/**
 * Updatet die Map - ohne Ausgabe
 * 
 * @param Spieler_alt_Hoehe       Spielerposition vor der Bewegung 
 * @param Spieler_alt_Breite     Spielerposition vor der Bewegung
 * @param Spieler_neu_Hoehe       Spielerposition nach der Bewegung
 * @param Spieler_neu_Breite     Spielerposition nach der Bewegung
 * 
 * @param Freiflaeche             Inhalt für die alte Position (Freifläche)
 * @param Spieler                Inhalt für die neue Position (Spieler)
 */
void updateMap(int Spieler_alt_Hoehe, int Spieler_alt_Breite, int Spieler_neu_Hoehe, int Spieler_neu_Breite, char Freiflaeche, char Spieler);


/**
 * Kontrolle ob bewegung möglich -> ausserhalb der Map (return 0)
 * Kontrolle ob bewegung möglich -> Hindernis (return 1)
 * Kontrolle ob Spieler auf Schatz ist (return 2)
 * Map updaten - ohne Ausgabe (return 3)
 * 
 * @param Hoehe                   Grösse des Arrays - map[Höhe][Breite] 
 * @param Breite                 Anz. Zeichen im Array - map[Höhe][Breite]
 * 
 * @param Spieler_alt_Hoehe       Spielerposition vor der Bewegung 
 * @param Spieler_alt_Breite     Spielerposition vor der Bewegung
 * @param Spieler_neu_Hoehe       Spielerposition nach der Bewegung
 * @param Spieler_neu_Breite     Spielerposition nach der Bewegung
 * 
 * @param Hindernis              Inhalt für die alte Position (Hindernis)
 * @param Freiflaeche             Inhalt für die alte Position (Freifläche)
 * @param Spieler                Inhalt für die neue Position (Spieler)
 * @param Schatz                 Inhalt für die neue Position (Schatz)
 */
int checkMap(int Hoehe, int Breite, int Spieler_alt_Hoehe, int Spieler_alt_Breite, int Spieler_neu_Hoehe, int Spieler_neu_Breite, char Hindernis, char Freiflaeche, char Spieler, char Schatz);

#endif // MAP_H ENDE