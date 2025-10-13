# Management Summary


**Zweck & Kontext.**  
Die Arbeit demonstriert den Transfer der Inhalte aus Programmiertechnik A/B in eine praxistaugliche Konsolenanwendung: ein textbasiertes Labyrinth-Spiel in C. Ziel war eine saubere Umsetzung mit nachvollziehbarem Design, reproduzierbarem Build und überprüfbaren Tests.

**Lösung in Kürze.**  
Die Applikation ist modular aufgebaut (`maze`, `game`, `main`) und arbeitet auf einem 12×24-Raster mit den Symbolen `P` (Spieler), `T` (Schatz), `O` (Hindernis) und `.` (leer). Die Steuerung erfolgt über **W/A/S/D** (jeweils mit Enter). Nach jedem gültigen Zug wird das Labyrinth **neu gezeichnet**. Die Siegbedingung ist erfüllt, sobald der Spieler die Schatz-Zelle betritt. Eingaben werden validiert, Rand- und Hinderniskollisionen blockieren Bewegungen. Der Build erfolgt reproduzierbar via **Makefile** (C11, `-Wall -Wextra -O2`), entwickelt auf **Windows 11** mit **MSYS2 MinGW64** und **GCC 15.2.0**.

**Ergebnisse & Nachweis.**  
Alle Muss-Anforderungen wurden erfüllt. Die Akzeptanztests **T01–T09** (Start, Bewegung, Blockade, Randprüfung, ungültige Eingaben, Case-Insensitivity, Sieg, Quit) sind bestanden; Screenshots und Logs sind im Repository abgelegt. Diagramme (Flowchart) und eine knappe Projektdokumentation liegen bei.

**Aufwand & Learnings.**  
Der Aufwand lag **im Rahmen der Vorgabe (≈ 25–30 h)**. Wesentliche Lerngewinne: **Makefile-Grundlagen** (Targets, Pattern-Rules, Dependenz-Tracking mit `-MMD -MP`), bewusster Einsatz von **Compiler-Flags**, saubere **Modularisierung in C** (Trennung Header/Implementierung), robuste **Konsolen-I/O** (zeilenweise Eingabe, Entprellen), sowie **Determinismus** für reproduzierbare Tests.

**Empfehlung / Nächste Schritte.**  
Parametrisierung von Rastergrösse/Hindernisdichte (CLI-Optionen), einfache **Testautomatisierung** (Eingabe-Skripte, Golden-Files), Prüfung der **Portabilität** (Terminals ohne ANSI-Escapes) und optionale Erweiterungen (Schwierigkeitsgrade, Pfadfinde-Logik).