# Management Summary – Praxisarbeit Programmiertechnik (C)

Diese Arbeit hatte das Ziel, ein kleines, textbasiertes **Labyrinth-Spiel** in C zu entwickeln. Der Spieler (`P`) bewegt sich mit den Tasten **W/A/S/D** durch das Spielfeld, um den Schatz (`T`) zu erreichen. Hindernisse (`O`) blockieren den Weg. Damit sollten die wichtigsten Konzepte der Programmiertechnik praxisnah umgesetzt werden: **Datenstrukturen, Algorithmen, Speicherverwaltung, Modularisierung, Tests und Dokumentation**.

---

## Vorgehen & Qualitätssicherung
- **Datenmodell & Schnittstellen:** Zuerst wurden die C-Structs definiert, anschließend die Funktionen implementiert.  
- **Robustheit:** Alle Speicherbereiche werden korrekt freigegeben (`free`), Eingaben werden validiert, ungültige Bewegungen abgefangen.  
- **Tests:** Ein `Makefile` automatisiert Kompilierung und Tests. `make test` prüft Bewegungen, Kollisionsabfragen und Spielende.  
- **Dokumentation:** Diagramme veranschaulichen den Aufbau und die Abläufe.  

---

## Praxistauglichkeit & Nutzen
- **Einfach reproduzierbar:** Start mit `make` und `./labyrinth`.  
- **Modular & erweiterbar:** Durch klare Trennung von Header- und Implementierungsdateien.  
- **Lern- & Übungswert:** Gut geeignet als Vorlage für Übungen oder Prüfungen (z. B. zusätzliche Level, Punktezähler, grafische Erweiterungen).  

---

## Grenzen & Risiken
- Spiel ist bewusst **textbasiert** (keine grafische Darstellung).  
- Bei hoher Hindernisdichte kann das Spielfeld unübersichtlich werden.  
- Erweiterte Spielfunktionen (mehrere Level, Punktesystem) sind noch nicht umgesetzt.  

---

## Diagramme (Überblick)
Die Diagramme helfen, Aufbau und Ablauf des Programms verständlich darzustellen.  

- **Modul-Überblick** – Dateien & Abhängigkeiten.  
- **Datenmodell (C-Structs)** – Spieler, Schatz, Hindernisse.  
- **Übersicht Spiellogik** – Ablauf von Start bis Spielende.  
- **Übersicht Eingabe** – Tastensteuerung und Verarbeitung.  
- **Übersicht Spielfeld** – Darstellung des Grids.  
- **Übersicht Renderer** – Konsolenausgabe.  
- **Übersicht Zugauswertung** – Prüfung gültiger Züge & Siegbedingung.  

➡️ [Zu den Diagrammen (lokal)](./diagramme.md)  
➡️ [Zu den Diagrammen (GitHub)](https://github.com/SalihSan54/PROT-B/blob/main/Labyrinth/docs/diagramme.md)  

---

## Nächste Schritte (Roadmap)
- Einführung von Schwierigkeitsstufen und Punktesystem.  
- Erweiterung um mehrere Level.  
- Entwicklung einer grafischen Benutzeroberfläche.  
- Erweiterte Tests zur Stabilität und Robustheit.  

---

## Fazit
Das Projektziel – ein funktionierendes Konsolenspiel mit klarer Spiellogik, zuverlässiger Eingabeverarbeitung und verständlicher Dokumentation – wurde erreicht.  

Die Arbeit zeigt, dass sich mit **systematischem Vorgehen**, **Einsatz von Diagrammen** und **schrittweiser Umsetzung** ein vollständiges Programm entwickeln lässt, das sowohl technisch korrekt als auch gut nachvollziehbar dokumentiert ist.
