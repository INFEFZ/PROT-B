#ifndef labyrinth_h
#define labyrinth_h
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

extern char feld[10][10];

void labyBuild(void);
/*
Erstellt ein 10x10 Labyrinth mit Hindernissen, einem Schatz und einem Spieler
Hindernisse = 'O' 
Schatz = 'T'
Spieler = 'P'               
*/  
void labyrinth(char feld[10][10]);
// Gibt das Labyrinth aus

#endif