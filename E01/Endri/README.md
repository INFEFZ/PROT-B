# Labyrinth – Konsolenspiel in C

Ein kleines Text-Adventure als Praxisarbeit (HF Elektrotechnik / IBZ – Programmiertechnik A & B).

## Features
- Zufälliges Labyrinth in einem 2D-Array
- Hindernisse `O`, Spieler `P`, Schatz `T`
- Steuerung mit `W/A/S/D` + Enter
- Robuste Eingabeprüfung
- Dynamische Speicherverwaltung, modulare Struktur

## Build & Run
```bash
make
./labyrinth               # Standardwerte
./labyrinth 15 30 20      # eigene Größe + Hindernis-Prozentsatz
```

## Projektstruktur
```
.
├── include
│   ├── game.h
│   ├── input.h
│   ├── maze.h
│   └── utils.h
├── src
│   ├── game.c
│   ├── input.c
│   ├── main.c
│   ├── maze.c
│   └── utils.c
└── Makefile
```

## Lizenz
MIT (für Ausbildungszwecke).