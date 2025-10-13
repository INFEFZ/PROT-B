# Dokumentation – Labyrinth (C)

## Management Summary

- **Summary als Markdown (Browser/GitHub):**  
  [Management Summary auf GitHub](https://github.com/SalihSan54/PROT-B/blob/main/Labyrinth/docs/management-summary.md)

- **Summary lokal im Repo:**  
  [management-summary.md](./management-summary.md)

---

## Praxisarbeit – Lösungsdokument

- **PDF (Browser/GitHub):**  
  [Lösungsdokument auf GitHub](https://github.com/SalihSan54/PROT-B/blob/main/Labyrinth/docs/L%C3%B6sungsdokument.pdf)

- **PDF lokal im Repo:**  
  [Lösungsdokument.pdf](./Lösungsdokument.pdf)

---

## Diagramme

- **Diagramme als Markdown (Browser/GitHub):**  
  [Diagramme auf GitHub](https://github.com/SalihSan54/PROT-B/blob/main/Labyrinth/docs/diagramme.md)

- **Diagramme lokal im Repo:**  
  [diagramme.md](./diagramme.md)

---

## Hinweis

- In **VS Code Codespaces** lassen sich PDFs im Editor nicht direkt anzeigen.  
- Deshalb ist die **Markdown-Version** bzw. die **GitHub-Links** die aktuell gültige Fassung.  

---

## Kurz-Anleitung (Build & Run)

```bash
# Kompilieren
make

# Standard: 10x10, ~15% Hindernisse
./labyrinth

# Beispiel mit Parametern (Zeilen, Spalten, Hindernis-Quote):
./labyrinth 12 12 0.2

# Tests ausführen
make test
