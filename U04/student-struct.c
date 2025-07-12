#include <stdio.h>
#include <string.h>

// Definition der Struktur Student
struct Student
{
  int matrikelnummer;
  char name[50];
  float durchschnittsnote;
};

// Funktion zur Ausgabe der Studentendaten
void printStudent(struct Student s)
{
  printf("Matrikelnummer: %d\n", s.matrikelnummer);
  printf("Name: %s\n", s.name);
  printf("Durchschnittsnote: %.1f\n\n", s.durchschnittsnote);
}

// Funktion zur Erstellung eines neuen Studenten
struct Student createStudent(int matrikelnummer, char name[], float durchschnittsnote)
{
  struct Student s;
  s.matrikelnummer = matrikelnummer;
  strcpy(s.name, name);
  s.durchschnittsnote = durchschnittsnote;
  return s;
}

void main()
{
  // Array zur Speicherung von 3 Studenten
  struct Student studenten[3] = {0};

  // init
  for (int i = 0; i < 3; i++)
  {
    studenten[i].matrikelnummer = 0;
    studenten[i].name[0] = '\0';
    studenten[i].durchschnittsnote = 0.0;
  }

  // Informationen der Studenten ausfüllen
  studenten[0] = createStudent(12345, "Max Mustermann", 5.3);
  studenten[1] = createStudent(23456, "Julia Schmidt", 5.0);
  studenten[2] = createStudent(34567, "John Doe", 4.1);

  // Informationen der Studenten ausgeben
  for (int i = 0; i < 3; i++)
  {
    printStudent(studenten[i]);
  }
}
