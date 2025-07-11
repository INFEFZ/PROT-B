#include <stdio.h>
#include <string.h>

// Definition der verschachtelten Struktur
struct Geburtsdatum
{
  int tag;
  int monat;
  int jahr;
};

// Definition der Hauptstruktur Student
struct Student
{
  char name[50];
  int matrikelnummer;
  float durchschnittsnote;
  struct Geburtsdatum geb;
};

// Funktionsdefinition zur Ausgabe
void druckeStudent(struct Student s)
{
  printf("Name: %s\n", s.name);
  printf("Matrikelnummer: %d\n", s.matrikelnummer);
  printf("Durchschnittsnote: %.2f\n", s.durchschnittsnote);
  printf("Geburtsdatum: %02d.%02d.%d\n", s.geb.tag, s.geb.monat, s.geb.jahr);
}

int main()
{
  // Initialisierung
  struct Student student1 = {
      "Anna Schreiber",
      123456,
      2.1,
      {15, 7, 2002}};

  // Ausgabe direkt
  printf("Direktausgabe:\n");
  printf("Name: %s\n", student1.name);
  printf("Matrikelnummer: %d\n", student1.matrikelnummer);
  printf("Durchschnittsnote: %.2f\n", student1.durchschnittsnote);
  printf("Geburtsdatum: %02d.%02d.%d\n", student1.geb.tag, student1.geb.monat, student1.geb.jahr);

  // Ausgabe über Funktion
  printf("\nAusgabe über Funktion:\n");
  druckeStudent(student1);

  // Ausgabe über Zeiger
  struct Student *ptr = &student1;
  printf("\nAusgabe über Zeiger:\n");
  printf("Name: %s\n", ptr->name);
  printf("Note: %.2f\n", ptr->durchschnittsnote);

  return 0;
}
