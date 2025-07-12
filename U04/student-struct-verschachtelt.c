#include <stdio.h>
#include <string.h>

// Definition der verschachtelten Struktur
struct Geburtsdatum
{
  int tag;
  int monat;
  int jahr;
};

// Definition der Struktur Student
struct Student
{
  int matrikelnummer;
  char name[50];
  float durchschnittsnote;
  struct Geburtsdatum geburtsdatum;
};

// Funktion zur Ausgabe der Studentendaten
void printStudent(struct Student s)
{
  printf("Matrikelnummer: %d\n", s.matrikelnummer);
  printf("Name: %s\n", s.name);
  printf("Durchschnittsnote: %.1f\n\n", s.durchschnittsnote);
  printf("Geburtsdatum: %02.02d.%d\n\n", s.geburtsdatum.tag, s.geburtsdatum.monat, s.geburtsdatum.jahr);
}

// Funktion zur Erstellung eines neuen Studenten
struct Student createStudent(int matrikelnummer, char name[], float durchschnittsnote, int tag, int monat, int jahr)
{
  struct Student s;
  s.matrikelnummer = matrikelnummer;
  strcpy(s.name, name);
  s.durchschnittsnote = durchschnittsnote;
  s.geburtsdatum.tag = tag;
  s.geburtsdatum.monat = monat;
  s.geburtsdatum.jahr = jahr;

  return s;
}

struct Geburtsdatum createGeburtstag(int tag, int monat, int jahr)
{
  struct Geburtsdatum gdatum = {tag, monat, jahr};
  return gdatum;
}

void main()
{
  // Array zur Speicherung von 3 Studenten
  struct Student studenten[3] = {0};

  // Informationen der Studenten ausfüllen
  studenten[0] = createStudent(12345, "Max Mustermann", 5.3, 1, 3, 1999);
  studenten[1] = createStudent(23456, "Julia Schmidt", 5.0, 10, 4, 2000);
  studenten[2] = createStudent(34567, "John Doe", 4.1, 20, 5, 2002);

  // Informationen der Studenten ausgeben
  for (int i = 0; i < 3; i++)
  {
    printStudent(studenten[i]);
  }
}
