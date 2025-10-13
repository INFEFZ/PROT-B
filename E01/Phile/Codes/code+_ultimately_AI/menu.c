#include "menu.h"
#include "input.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

GameMode menu_show_and_select(char* player_name, int name_len, int* show_scores, int* reset_scores, int* quit_program){
    if (!player_name[0]){
        if(!input_read_player_name(player_name, (size_t)name_len)){
            *quit_program=1; return 0;
        }
    }
    while(1){
        printf("\n=== Hauptmenü ===\n");
        printf("1) Classic 2D (10x10)\n");
        printf("2) Classic 2D + beweglicher Schatz\n");
        printf("3) Classic 2D + Monster\n");
        printf("4) Classic 2D + Schatz & Monster\n");
        printf("5) Custom 2D (eigene Größe, Optionen)\n");
        printf("6) Cube 3D (10x10x10)\n");
        printf("7) Cube 3D + Monster\n");
        printf("8) Highscores anzeigen\n");
        printf("9) Highscores zurücksetzen\n");
        printf("E) Programm beenden\n");
        printf("Auswahl: ");
        char buf[64];
        if (!input_read_line(buf, sizeof buf)) { *quit_program=1; return 0; }
        char c = (char)toupper((unsigned char)buf[0]);
        switch(c){
            case '1': return MODE_CLASSIC2D;
            case '2': return MODE_CLASSIC2D_TREASURE;
            case '3': return MODE_CLASSIC2D_MONSTER;
            case '4': return MODE_CLASSIC2D_BOTH;
            case '5': return MODE_CUSTOM2D;
            case '6': return MODE_CUBE3D;
            case '7': return MODE_CUBE3D_MONSTER;
            case '8': *show_scores=1; return 0;
            case '9': *reset_scores=1; return 0;
            case 'E': *quit_program=1; return 0;
            default:  printf("Ungültige Auswahl.\n"); break;
        }
    }
}
