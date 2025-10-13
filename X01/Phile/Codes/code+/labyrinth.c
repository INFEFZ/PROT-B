#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "labyrinth.h"



char feld[10][10];

void labyBuild(){
   for(int i=0; i<10; i++) {        // initialisiere Feld
        for(int j=0; j<10; j++) {
            feld[i][j] = '.'; // . als Platzhalter
        }       
    }

    // Hindernisse platzieren, ganzes feld[10][10], random manuell

    
    feld[0][6] = 'O';

    feld[1][0] = 'O';

    feld[2][0] = 'O';   
    feld[2][3] = 'O';

    feld[3][4] = 'O';
    feld[3][5] = 'O';

    feld[4][0] = 'O';
    feld[4][2] = 'O';

    feld[5][0] = 'O';
    feld[5][1] = 'O';
    feld[5][3] = 'O';
    feld[5][4] = 'O';
    feld[5][5] = 'O';
    feld[5][8] = 'O';
    feld[5][9] = 'O';

    feld[6][3] = 'O';
    feld[6][6] = 'O';

    feld[7][0] = 'O';
    feld[7][5] = 'O';
    feld[7][6] = 'O';
    feld[7][7] = 'O';
    feld[7][8] = 'O';

    feld[8][6] = 'O';

    feld[9][2] = 'O';
    feld[9][4] = 'O';
    feld[9][9] = 'O';
    
/*
                {'.', '.', '.', '.', '.', '.', 'O', '.', '.', '.'},
                {'O', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                {'O', '.', '.', 'O', '.', '.', '.', '.', '.', '.'},
                {'.', '.', '.', '.', 'O', 'O', '.', '.', '.', '.'},
                {'O', '.', 'O', '.', '.', '.', '.', '.', '.', '.'},
                {'O', 'O', 'O', 'O', 'O', 'O', '.', '.', 'O', 'O'},
                {'.', '.', '.', 'O', '.', '.', 'O', '.', '.', '.'},
                {'O', '.', '.', '.', '.', 'O', 'O', 'O', 'O', '.'},
                {'.', '.', '.', '.', '.', '.', 'O', '.', '.', '.'},
                {'.', '.', 'O', '.', 'O', '.', '.', '.', '.', 'O'}
*/

    // Schatz random platzieren, nicht auf Hindernis
    int schatzX = rand() % 10;   // Zufallszahl 0-9
    int schatzY = rand() % 10;
    
    while(feld[schatzX][schatzY] == 'O') { // solange Hindernis, neu generieren
        schatzX = rand() % 10; 
        schatzY = rand() % 10;
    }
    feld[schatzX][schatzY] = 'T';  // T = (Schatz)

    // Spieler random platzieren, nicht auf Hindernis oder Schatz
    int spielerX = rand() % 10;
    int spielerY = rand() % 10;
    while(feld[spielerX][spielerY] == 'O' || feld[spielerX][spielerY] == 'T') { // solange Hindernis oder Schatz, neu generieren
        spielerX = rand() % 10;
        spielerY = rand() % 10;
    }
    feld[spielerX][spielerY] = 'P';  // P = Spieler
}


/*
Dieser Teile wurde zusaetzlich hinzugefuegt, um zu zeigen, das es manchmal nicht viel veraenderung brauch,
um sogar weiteres hineinzufuegen und ein neues labyrinth zu erstellen
*/

void labymonst(){
    labyBuild();
    // Monster random platzieren, nicht auf Hindernis, Schatz oder Spieler
    int monsterX = rand() % 10;
    int monsterY = rand() % 10;
    while(feld[monsterX][monsterY] == 'O' || feld[monsterX][monsterY] == 'T' || feld[monsterX][monsterY] == 'P') { // solange Hindernis oder Schatz oder Spieler, neu generieren
        monsterX = rand() % 10;
        monsterY = rand() % 10;
    }
    feld[monsterX][monsterY] = 'M';  // M = Monster
}


void labyrinth(char feld[10][10]){  // Gibt das Labyrinth aus
    printf("\nLabyrinth:\n");
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            printf("%c ", feld[i][j]);  // Feld ausgeben   
        }
        printf("\n");
    }
}