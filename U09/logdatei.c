#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOG_FILE "logfile.txt"

// Funktion zum Erstellen eines Zeitstempels
void get_timestamp(char *buffer, size_t buffer_size)
{
  time_t now = time(NULL);
  struct tm *timeinfo = localtime(&now);
  strftime(buffer, buffer_size, "%Y-%m-%d %H:%M:%S", timeinfo);
}

// Funktion zum Schreiben eines Logeintrags
void write_log(const char *event)
{
  FILE *file = fopen(LOG_FILE, "a");
  if (file == NULL)
  {
    perror("Fehler beim Öffnen der Logdatei");
    exit(EXIT_FAILURE);
  }

  char timestamp[20];
  get_timestamp(timestamp, sizeof(timestamp));
  fprintf(file, "[%s] %s\n", timestamp, event);
  fclose(file);
}

// Funktion zum Lesen und Anzeigen der Logeinträge
void read_log()
{
  FILE *file = fopen(LOG_FILE, "r");
  if (file == NULL)
  {
    perror("Fehler beim Öffnen der Logdatei");
    exit(EXIT_FAILURE);
  }

  char line[256];
  while (fgets(line, sizeof(line), file))
  {
    printf("%s", line);
  }
  fclose(file);
}

void main()
{
  // Beispielereignisse in die Logdatei schreiben
  write_log("Programm gestartet");
  write_log("Erstes Ereignis");
  write_log("Zweites Ereignis");
  write_log("Programm beendet");

  // Logdatei lesen und anzeigen
  printf("Inhalt der Logdatei:\n");
  read_log();
}
