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

int eingabeMonster(void) {
    find_player(&spielerX, &spielerY); // aktuelle Spielerposition ermitteln
    char c;
    printf("Bewege den Spieler ( A < / D > / W ^ / S ) - Spiel Abbrechen (E): ");
    scanf(" %1c", &c); // nur ein Zeichen einlesen
    // Eingabepuffer leeren
    if (c != '\n') { //der rest der hinter dem einen eichen ist, wird geloescht
        while (getchar() != '\n'); 
    }



    if (eingabe) { 
        if (c == 'E' || c == 'e') {
            printf("Spiel wurde vom Spieler abgebrochen.\n\n");
            _Exit(0);
        }
        else if(c == 'W' || c == 'A' || c == 'S' || c == 'D' || c == 'w' || c == 'a' || c == 's' || c == 'd') { // hier wird nur ermoeglicht, das auch kleine buchstaben erkannt werden
            if (c == 'W' || c == 'w') {
                moveMonster('W');
                labyrinth(feld);
                eingabeMonster();
                }
            else if (c == 'A' || c == 'a') {
                moveMonster('A');
                labyrinth(feld);
                eingabeMonster();
                }
            else if (c == 'S' || c == 's') { 
                moveMonster('S');
                labyrinth(feld);
                eingabeMonster();
                }
            else if (c == 'D' || c == 'd') { 
                moveMonster('D');
                labyrinth(feld);
                eingabeMonster();
                }
            else {
            printf("Eingabe ungültig. Bitte wiederholen.\n\n");
            eingabeMonster();
            }
            return 0;
    }
    else {
        printf("Eingabe ungültig. Bitte wiederholen.\n\n");
        eingabeMonster();
        }
    }
    return 0;
}



void pri_feldrand(){
    printf("Du kannst nicht aus dem Feld rauslaufen, bitte eine andere Richtung wählen.\n\n");
    eingabe();
}
void pri_hindernis(){
    printf("Hindernis im Weg, nehmen Sie einen anderen Weg.\n\n");
    eingabe();
}
void pri_schatz(){
    printf("Glückwunsch, du hast den Schatz erreicht.\n\n");
    _Exit(0);
}
void pri_monster(){
    printf("Oh nein, du bist dem Monster begegnet! Spiel vorbei.\n\n");
    _Exit(0);
}
void pri_feldPoint(){
    feld[spielerX][spielerY] = '.'; // alten Spielerpunkt löschen
}
void pri_feldPlayer(){
    feld[spielerX][spielerY] = 'P'; // neuen Spielerpunkt setzen
}

void move(char richtung){

    int nx = spielerX;
    int ny = spielerY;


    switch (richtung) {

    case 'W':
        // move up
        nx--;
        if (nx < 0 || nx >= 10) { // Spielrand prüfen
            pri_feldrand();
        }
        if (feld[nx][ny] == 'O') { // Hindernis prüfen
            pri_hindernis();
        }
        if (feld[nx][ny] == 'T') { // Schatz gefunden prüfen
            pri_schatz();
        }
        if (feld[nx][ny] == 'M') { // Monster getroffen prüfen
            pri_monster();
        }
        pri_feldPoint();
        spielerX--; // Spielerposition ändern
        pri_feldPlayer();
        break;

    case 'A':
        // move left
        ny--;
        if (ny < 0 || ny >= 10) { // Spielrand prüfen
            pri_feldrand();
        }
        if (feld[nx][ny] == 'O') { // Hindernis prüfen
            pri_hindernis();
        }
        if (feld[nx][ny] == 'T') { // Schatz gefunden prüfen
            pri_schatz();
        }
        if (feld[nx][ny] == 'M') { // Monster getroffen prüfen
            pri_monster();
        }
        pri_feldPoint();
        spielerY--; // Spielerposition ändern
        pri_feldPlayer();
        break;

    case 'S':
        // move down
        nx++;
        if (nx < 0 || nx >= 10) { // Spielrand prüfen
            pri_feldrand();
        }
        if (feld[nx][ny] == 'O') { // Hindernis prüfen
            pri_hindernis();
        }
        if (feld[nx][ny] == 'T') { // Schatz gefunden prüfen
            pri_schatz();
        }
        if (feld[nx][ny] == 'M') { // Monster getroffen prüfen
            pri_monster();
        }
        pri_feldPoint();
        spielerX++; // Spielerposition ändern
        pri_feldPlayer();
        break;

    case 'D':
        // move right
        ny++;
        if (ny < 0 || ny >= 10) { // Spielrand prüfen
            pri_feldrand();
        }
        if (feld[nx][ny] == 'O') { // Hindernis prüfen
            pri_hindernis();
        }
        if (feld[nx][ny] == 'T') { // Schatz gefunden prüfen
            pri_schatz();
        }
        if (feld[nx][ny] == 'M') { // Monster getroffen prüfen
            pri_monster();
        }
        pri_feldPoint();
        spielerY++; // Spielerposition ändern
        pri_feldPlayer();
        break;

    default:
        printf("Ungültige Richtung. Bitte W, A, S oder D eingeben.\n\n");
        eingabe();
        break;
    }
    return;
}


void moveMonsterRandom(){
    // Monster bewegt sich zufällig in eine der vier Richtungen (W, A, S, D)
    int direction = rand() % 4; // Zufallszahl zwischen 0 und 3
    int mx = 0, my = 0;

    // aktuelle Monsterposition finden
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (feld[i][j] == 'M') {
                mx = i; my = j;
                break;
            } 
        }
    }

    int new_mx = mx;
    int new_my = my;

    switch (direction) {
        case 0: new_mx--; break; // W
        case 1: new_my--; break; // A
        case 2: new_mx++; break; // S
        case 3: new_my++; break; // D
    }

    // Prüfen ob die neue Position gültig ist
    if (new_mx >= 0 && new_mx < 10 && new_my >= 0 && new_my < 10 &&
        feld[new_mx][new_my] != 'O' && feld[new_mx][new_my] != 'T' && feld[new_mx][new_my] != 'P') {
        feld[mx][my] = '.'; // alten Monsterpunkt löschen
        feld[new_mx][new_my] = 'M'; // neuen Monsterpunkt setzen
    }
}

void moveMonster(char richtung){
   
    int nx = spielerX;
    int ny = spielerY;


    switch (richtung) {

    case 'W':
        // move up
        nx--;
        if (nx < 0 || nx >= 10) { // Spielrand prüfen
            pri_feldrand();
        }
        if (feld[nx][ny] == 'O') { // Hindernis prüfen
            pri_hindernis();
        }
        if (feld[nx][ny] == 'T') { // Schatz gefunden prüfen
            pri_schatz();
        }
        pri_feldPoint();
        spielerX--; // Spielerposition ändern
        pri_feldPlayer();
        moveMonsterRandom();
        break;

    case 'A':
        // move left
        ny--;
        if (ny < 0 || ny >= 10) { // Spielrand prüfen
            pri_feldrand();
        }
        if (feld[nx][ny] == 'O') { // Hindernis prüfen
            pri_hindernis();
        }
        if (feld[nx][ny] == 'T') { // Schatz gefunden prüfen
            pri_schatz();
        }
        pri_feldPoint();
        spielerY--; // Spielerposition ändern
        pri_feldPlayer();
        moveMonsterRandom();
        break;

    case 'S':
        // move down
        nx++;
        if (nx < 0 || nx >= 10) { // Spielrand prüfen
            pri_feldrand();
        }
        if (feld[nx][ny] == 'O') { // Hindernis prüfen
            pri_hindernis();
        }
        if (feld[nx][ny] == 'T') { // Schatz gefunden prüfen
            pri_schatz();
        }
        pri_feldPoint();
        spielerX++; // Spielerposition ändern
        pri_feldPlayer();
        moveMonsterRandom();
        break;

    case 'D':
        // move right
        ny++;
        if (ny < 0 || ny >= 10) { // Spielrand prüfen
            pri_feldrand();
        }
        if (feld[nx][ny] == 'O') { // Hindernis prüfen
            pri_hindernis();
        }
        if (feld[nx][ny] == 'T') { // Schatz gefunden prüfen
            pri_schatz();
        }
        pri_feldPoint();
        spielerY++; // Spielerposition ändern
        pri_feldPlayer();
        moveMonsterRandom();
        break;

    default:
        printf("Ungültige Richtung. Bitte W, A, S oder D eingeben.\n\n");
        eingabe();
        break;
    }
    return;
}

