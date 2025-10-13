# Diagramme

In diesem Abschnitt werden alle wichtigen Diagramme zum Labyrinth-Spiel dargestellt und erklärt. Die Abbildungen sind nummeriert und inhaltlich beschrieben.
---

## Modul-Überblick (Dateien & Abhängigkeiten)

```mermaid
flowchart LR
subgraph Projekt
    main["main.c"] --> api["labyrinth.h (API)"]
    api --> impl["labyrinth.c<br>(Implementierung)"]
    tests["tests/ (Autotests)"] --> api
    impl --> std["stdlib.h, stdio.h, rand()"]
    main --> io["stdio.h / I/O"]
end

classDef file fill:#eef6ff,stroke:#1e66f5,stroke-width:1px,color:#0b2b6b;
classDef sys  fill:#fff4e6,stroke:#e8590c,color:#5f3c00;

class main,api,impl,tests file;
class std,io sys;
```
Abb. 1 – Modul-Überblick: main.c spricht via labyrinth.h mit labyrinth.c; Tests hängen an der API; Nutzung von stdlib.h/stdio.h/rand().
--- 

## Datenmodell (C-Structs)

```mermaid
classDiagram
    class Position { 
        +int zeile 
        +int spalte 
    }

    class Spiel {
        +int zeilen
        +int spalten
        +float hinderungsrate
        +int zuege
        +char** raster
        +Position spieler
        +Position schatz
    }

    Spiel "1" o-- "1" Position : spieler
    Spiel "1" o-- "1" Position : schatz

```
Abb. 2 – Datenmodell: Game kapselt den Spielzustand (rows/cols/ratio/moves/grid/player/treasure). Pos beschreibt Koordinaten.
--- 

## Übersicht Spiellogik

```mermaid
flowchart TD
    start(["Start"]) --> init["Initialisierung Spiel"]
    init --> zufall["Zufallspositionen für Spieler und Schatz"]
    zufall --> spielfeld["Spielfeld erzeugen"]
    spielfeld --> schleife{"Spielzug möglich?"}
    schleife -->|Ja| eingabe["Eingabe verarbeiten"]
    eingabe --> pruefen{"Zug prüfen: gültig/blockiert"}
    pruefen -->|gültig| update["Position aktualisieren"]
    pruefen -->|blockiert| hinweis["Hinweis: ungültig"]
    update --> sieg{"Schatz erreicht?"}
    hinweis --> schleife
    sieg -->|Nein| schleife
    sieg -->|Ja| ende(["Spielende"])
```
Abb. 3 – Übersicht Spiellogik: Ablauf von Initialisierung über Spielfeld, Züge, Prüfung bis zum Spielende.
--- 

## Übersicht Eingabe

```mermaid
flowchart TD
    classDef default fill:#222,color:#fff,font-size:12px;

    start([Tasteneingabe W/A/S/D/Q]) --> normal["Normierte Eingabe"]
    normal --> pruefen{"Eingabe gültig?"}
    pruefen -->|Ja| weiter["Eingabe zurückgeben (W/A/S/D)"]
    pruefen -->|Q| ende([Spielende])
    pruefen -->|Nein| hinweis["Hinweis: ungültige Eingabe"]
    hinweis --> start
```
Abb. 4 – Übersicht Eingabe: Verarbeitung der Nutzereingabe.
W/A/S/D = gültige Spielzüge, Q = Spielende, ungültige Eingaben führen zu einer Wiederholung.
--- 

## Übersicht Spielfeld

```mermaid
flowchart TD
    start(["Initialisierung"]) --> grid["Spielfeld anlegen"]
    grid --> hindernisse["Hindernisse zufällig platzieren"]
    hindernisse --> posSpieler["Position Spieler setzen"]
    posSpieler --> posSchatz["Position Schatz setzen"]
    posSchatz --> fertig(["Spielfeld bereit"])
```
Abb. 5 – Übersicht Spielfeld: Ablauf der Spielfelderstellung mit Hindernissen, Spieler- und Schatz-Position.
--- 

## Übersicht Renderer

```mermaid
flowchart TD
    start(["Start"]) --> init["Init Renderer"]
    init --> grid["Daten laden"]
    grid --> draw["Spielfeld zeichnen"]
    draw --> output["Konsole Ausgabe"]
    output --> ende(["Fertig"])
```
Abb. 6 – Übersicht Renderer: Ablauf von Initialisierung über Laden der Spielfeld-Daten, Zeichnen mit Spieler/Schatz und Ausgabe auf der Konsole.
---

## Übersicht Zugauswertung

```mermaid
flowchart TD
    start(["Start"]) --> pruefen{"Zug möglich?"}
    pruefen -->|Ja| update["Position aktualisieren"]
    pruefen -->|Nein| hinweis["Hinweis: blockiert"]

    update --> sieg{"Schatz erreicht?"}
    sieg -->|Ja| erfolg["Herzlichen Glückwunsch<br/>alle Schätze gefunden"]
    erfolg --> ende(["Spielende"])
    sieg -->|Nein| start

    hinweis --> start

```
Abb. 7 – Übersicht Zugauswertung: Prüfung ob ein Zug möglich ist, Aktualisierung der Position oder Hinweis bei Blockade; Siegprüfung mit Erfolgsmeldung und Spielende.
--- 