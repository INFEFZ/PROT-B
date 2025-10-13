# Labyrinth (C)

Ein kleines Terminal-Spiel in C. Bewege dich mit **W/A/S/D** durch das Labyrinth.

---

## Voraussetzungen
- **C-Compiler** (z. B. `gcc` / Clang)
- **make** (GNU Make)

> **Linux/macOS:** Compiler & Make sind meist per Paketmanager installierbar.  
> **Windows:** z. B. mit **MSYS2/MinGW** oder **WSL** installieren.

---

## Schnellstart

```bash
# Projekt bauen
make

# Spiel starten
make run

# Build-Artefakte entfernen
make clean

Steuerung
W = hoch

A = links

S = runter

D = rechts

Enter = Eingabe bestätigen

Q = Spiel abbrechen

Projektstruktur
bash
.
├─ src/                  # C-Quellcode
├─ doc/                  # Dokumentation (PDF)
├─ logs/                 # Laufzeit-Logs
├─ .gitignore
├─ Makefile
└─ README.md
Logs
Laufzeitprotokolle werden in logs/ abgelegt (falls aktiviert).

Dokumentation
 doc/loesungsdokument.pdf