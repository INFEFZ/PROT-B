#include <stdio.h>
#include <stdlib.h> // for _Exit
#include "move.h"
#include "labyrinth.h"

// Spielerposition Variablen initialisieren/deklarieren
int spielerX = 0; // Startposition X
int spielerY = 0; // Startposition Y

// interne Spielerposition ermitteln
void find_player(int *x, int *y) { 
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (feld[i][j] == 'P') {
                *x = i; *y = j; // Spielerposition gefunden
                return;
            } 
        }
    }
    *x = 0; *y = 0; // falls Spieler nicht gefunden wird, setze auf (0,0)
}

int eingabe(void) {
    find_player(&spielerX, &spielerY); // aktuelle Spielerposition ermitteln
    char c;
    printf("Bewege den Spieler ( A < / D > / W ^ / S ) - Spiel Abbrechen (E): ");
    scanf(" %1c", &c); // nur ein Zeichen einlesen
    // Eingabepuffer leeren
    if (c != '\n') { //der rest der hinter dem einen eichen ist, wird geloescht
        while (getchar() != '\n'); 
    }

/*das meiste laeuft eigenltich hier ab, halt von der eingabe zur bewegunng, zum labyrinth ausgeben und wieder die eingabe fortsetzten.
mein ziel wahr es eigenlich mal moeglichst wenig rekursionen zu machen, aber hier ging es halt so schoen auf. einmal probiert ich es auch mit einer schleife aus,
aber das gefiehl mir nicht so. daher bin ich dann wieder zurueck auf mein usprung geagnen.
Nun besteht natürlich die gefahr von Overflow, aber dies denke ist bei so einem kleinen programm nicht problematisch, höchstens aus sauberkeitsgrïunden köontte man es machen
Daher habe ich das gelassen. Schönheits und peformence könnte man immernoch verbessern.*/

    if (eingabe) { 
        if (c == 'E' || c == 'e') {
            printf("Spiel wurde vom Spieler abgebrochen.\n\n");
            _Exit(0);
        }
        else if(c == 'W' || c == 'A' || c == 'S' || c == 'D' || c == 'w' || c == 'a' || c == 's' || c == 'd') { // hier wird nur ermoeglicht, das auch kleine buchstaben erkannt werden
            if (c == 'W' || c == 'w') {
                move('W');
                labyrinth(feld);
                eingabe();
                }
            else if (c == 'A' || c == 'a') {
                move('A');
                labyrinth(feld);
                eingabe();
                }
            else if (c == 'S' || c == 's') { 
                move('S');
                labyrinth(feld);
                eingabe();
                }
            else if (c == 'D' || c == 'd') { 
                move('D');
                labyrinth(feld);
                eingabe();
                }
            else {
            printf("Eingabe ungültig. Bitte wiederholen.\n\n");
            eingabe();
            }
            return 0;
    }
    else {
        printf("Eingabe ungültig. Bitte wiederholen.\n\n");
        eingabe();
        }
    }
    return 0;
}

void move(char richtung){

    int nx = spielerX;
    int ny = spielerY;

/*ja ich weiss, hier koennte man noch 2-3 funktionen generieren, die alles schmaeler machen,
ich habe es extra so gelassen, wie ich es zum ersten mal programmiert habe.*/
    switch (richtung) {

    case 'W':
        // move up
        nx--;
        if (nx < 0 || nx >= 10) { // Spielrand prüfen
            printf("Du kannst nicht aus dem Feld rauslaufen, bitte eine andere Richtung wählen.\n\n");
            eingabe();
        }
        if (feld[nx][ny] == 'O') { // Hindernis prüfen
            printf("Hindernis im weg, nehmen sie einen anderen Weg.\n\n");
            eingabe();
        }
        if (feld[nx][ny] == 'T') { // Schatz gefunden prüfen
            printf("Glückwunsch, du hast den Schatz erreicht.\n\n");
            _Exit(0);
        }
        feld[spielerX][spielerY] = '.'; // alten Spielerpunkt löschen
        spielerX--; // Spielerposition ändern
        feld[spielerX][spielerY] = 'P'; // neuen Spielerpunkt setzen
        break;

    case 'A':
        // move left
        ny--;
        if (ny < 0 || ny >= 10) { // Spielrand prüfen
            printf("Du kannst nicht aus dem Feld rauslaufen, bitte eine andere Richtung wählen.\n\n");
            eingabe();
        }
        if (feld[nx][ny] == 'O') { // Hindernis prüfen
            printf("Hindernis im weg, nehmen sie einen anderen Weg.\n\n");
            eingabe();
        }
        if (feld[nx][ny] == 'T') { // Schatz gefunden prüfen
            printf("Glückwunsch, du hast den Schatz erreicht.\n\n");
            _Exit(0);
        }
        feld[spielerX][spielerY] = '.'; // alten Spielerpunkt löschen
        spielerY--; // Spielerposition ändern
        feld[spielerX][spielerY] = 'P'; // neuen Spielerpunkt setzen
        break;

    case 'S':
        // move down
        nx++;
        if (nx < 0 || nx >= 10) { // Spielrand prüfen
            printf("Du kannst nicht aus dem Feld rauslaufen, bitte eine andere Richtung wählen.\n\n");
            eingabe();
        }
        if (feld[nx][ny] == 'O') { // Hindernis prüfen
            printf("Hindernis im weg, nehmen sie einen anderen Weg.\n\n");
            eingabe();
        }
        if (feld[nx][ny] == 'T') { // Schatz gefunden prüfen
            printf("Glückwunsch, du hast den Schatz erreicht.\n\n");
            _Exit(0);
        }
        feld[spielerX][spielerY] = '.'; // alten Spielerpunkt löschen
        spielerX++; // Spielerposition ändern
        feld[spielerX][spielerY] = 'P'; // neuen Spielerpunkt setzen
        break;

    case 'D':
        // move right
        ny++;
        if (ny < 0 || ny >= 10) { // Spielrand prüfen
            printf("Du kannst nicht aus dem Feld rauslaufen, bitte eine andere Richtung wählen.\n\n");
            eingabe();
        }
        if (feld[nx][ny] == 'O') { // Hindernis prüfen
            printf("Hindernis im weg, nehmen sie einen anderen Weg.\n\n");
            eingabe();
        }
        if (feld[nx][ny] == 'T') { // Schatz gefunden prüfen
            printf("Glückwunsch, du hast den Schatz erreicht.\n\n");
            _Exit(0);
        }
        feld[spielerX][spielerY] = '.'; // alten Spielerpunkt löschen
        spielerY++; // Spielerposition ändern
        feld[spielerX][spielerY] = 'P'; // neuen Spielerpunkt setzen
        break;

    default:
        printf("Ungültige Richtung. Bitte W, A, S oder D eingeben.\n\n");
        eingabe();
        break;
    }
    return;
}