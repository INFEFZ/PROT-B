#include "input.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int input_read_line(char* buf, size_t n) {
    if (!fgets(buf, (int)n, stdin)) return 0;
    size_t len = strlen(buf);
    if (len && buf[len-1] == '\n') buf[len-1] = '\0';
    return 1;
}

static char to_upper_first(const char* s) {
    while (*s && isspace((unsigned char)*s)) s++;
    return (char)toupper((unsigned char)*s);
}

char input_read_menu_choice(void) {
    char buf[64];
    printf("\n=== Hauptmenü ===\n");
    printf("1) Classic 2D (10x10)\n");
    printf("2) Custom 2D (eigene Größe, Optionen)\n");
    printf("3) Cube 3D (10x10x10)\n");
    printf("4) Highscores anzeigen\n");
    printf("5) Highscores zurücksetzen\n");
    printf("E) Programm beenden\n");
    printf("Auswahl: ");
    if (!input_read_line(buf, sizeof buf)) return 0;
    char c = to_upper_first(buf);
    if (c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='E') return c;
    return 0;
}

int input_read_player_name(char* buf, size_t n) {
    printf("Bitte Spielername eingeben: ");
    if (!input_read_line(buf, n)) return 0;
    // trim spaces
    size_t len = strlen(buf);
    while (len && (buf[len-1]==' ' || buf[len-1]=='\t')) buf[--len] = '\0';
    return 1;
}

int input_read_direction_2d(Direction* d, int* quit) {
    char buf[64];
    printf("Bewegen (W/A/S/D) oder E für Ende: ");
    if (!input_read_line(buf, sizeof buf)) return 0;
    char c = (char)toupper((unsigned char)buf[0]);
    if (c=='E') { *quit = 1; return 1; }
    if (c=='W'){ *d = DIR_UP;    *quit=0; return 1; }
    if (c=='A'){ *d = DIR_LEFT;  *quit=0; return 1; }
    if (c=='S'){ *d = DIR_DOWN;  *quit=0; return 1; }
    if (c=='D'){ *d = DIR_RIGHT; *quit=0; return 1; }
    return 0;
}

int input_read_direction_3d(Direction* d, int* quit) {
    char buf[64];
    printf("Bewegen (W/A/S/D, R/F für Ebenen) oder E für Ende: ");
    if (!input_read_line(buf, sizeof buf)) return 0;
    char c = (char)toupper((unsigned char)buf[0]);
    if (c=='E') { *quit = 1; return 1; }
    if (c=='W'){ *d = DIR_UP;    *quit=0; return 1; }
    if (c=='A'){ *d = DIR_LEFT;  *quit=0; return 1; }
    if (c=='S'){ *d = DIR_DOWN;  *quit=0; return 1; }
    if (c=='D'){ *d = DIR_RIGHT; *quit=0; return 1; }
    if (c=='R'){ *d = DIR_UPZ;   *quit=0; return 1; }
    if (c=='F'){ *d = DIR_DOWNZ; *quit=0; return 1; }
    return 0;
}

int input_read_int(const char* prompt, int minv, int maxv, int* out) {
    char buf[128];
    while (1) {
        printf("%s [%d..%d] (E=abbrechen): ", prompt, minv, maxv);
        if (!input_read_line(buf, sizeof buf)) return 0;
        if (toupper((unsigned char)buf[0])=='E') return 0;
        int v; if (sscanf(buf, "%d", &v)==1 && v>=minv && v<=maxv) { *out=v; return 1; }
        printf("Ungültig.\n");
    }
}

int input_yes_no(const char* prompt, int default_yes) {
    char buf[64];
    printf("%s [%s]: ", prompt, default_yes? "J/n":"j/N");
    if (!input_read_line(buf, sizeof buf)) return default_yes;
    char c = (char)toupper((unsigned char)buf[0]);
    if (c=='\0') return default_yes;
    if (c=='J' || c=='Y') return 1;
    if (c=='N') return 0;
    return default_yes;
}
