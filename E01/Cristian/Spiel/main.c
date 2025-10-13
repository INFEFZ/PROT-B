#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "utils.h"

int main() {
    srand(time(NULL));

    char choice;
    do {
        clearScreen();
        printf("+------------------------+\n");
        printf("|  LABYRINTH-GAME-CUBI   |\n");
        printf("|  1 = Spiel starten     |\n");
        printf("|  2 = Beenden           |\n");
        printf("+------------------------+\n");
        printf("Deine Wahl: ");
        scanf(" %c", &choice);

        if (choice == '1') {
            startGame();
        } else if (choice == '2') {
            printf("Spiel wird beendet. Auf Wiedersehen!\n");
        } else {
            printf("Ungültige Eingabe!\n");
        }

    } while (choice != '2');

    return 0;
}
