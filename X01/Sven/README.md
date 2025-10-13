# Projektarbeit_2D_Konsolenspiel
Projektarbeit_Abschlussarbeit_Programmiertechnik_A/B

# Labyrinthspiel in C

Willkommen im Labyrinth!  
In diesem textbasierten Konsolenspiel steuerst du einen Abenteurer durch ein Labyrinth voller Hindernisse, auf der Suche nach einem Schatz.

Das Spiel wurde im Rahmen der **Praxisarbeit Programmiertechnik A & B (HF Elektrotechnik)** entwickelt und demonstriert den praktischen Umgang mit:

- Datenstrukturen (2D-Array)
- Benutzereingaben und Spielsteuerung
- Modularer Aufbau in C
- Dynamische Platzierung von Spieler und Schatz
- Zufallszahlen und einfache Spielmechanik

## Spielmechanik

- Du siehst ein Labyrinth in der Konsole
- Du steuerst den Spieler `P` mit **W A S D**
- Der Schatz `T` ist irgendwo versteckt
- Hindernisse `O` blockieren deinen Weg
- Wenn du den Schatz erreichst → **Gewinn!**

## Steuerung && Anzeige (Konfigurierbar [main.c (6-27)])
- **W / w** : hoch
- **A / a** : links
- **S / s** : runter
- **D / d** : rechts
- **1**     : Restart
- **0**     : Beenden

- **P**     : Spieler
- **T**     : Schatz
- **O**     : Hindernis
- **.**     : Freifläche

- **12**    : Hindernis_Warscheinlichkeit_in_%

- **15**    : Map_Breite
- **15**    : Map_Höhe

## Projektstruktur

```plaintext
.
├── main.c / main.o
├── Map.c / Map.h / Map.o
├── Makefile
├── labyrinth
├── README.md
└── Dokumentation/
    └── Lösungsdokument.pdf
```
## Lizenz

Dieses Projekt wurde im Rahmen der HF Elektrotechnik erstellt und darf mit Nahmensnennung frei verwendet werden.

## Voraussetzungen
- GCC (C11)
- Terminal (UTF-8)

## Build
```sh
make                                // Konsoleneingabe für Gameerstellung / Neukalibrierung / Updateübernahme
```

## Ausführen
```sh
cd Spiel                            // Ordner öffnen
./labyrinth                         // Konsoleneingabe für Gamestart
```

