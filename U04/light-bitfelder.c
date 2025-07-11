#include <stdio.h>

// Definition der Struktur SmartLight mit Bitfeldern
struct SmartLight
{
  unsigned int brightness : 4; // 4 Bits für die Helligkeit (0-15)
  unsigned int color : 3;      // 3 Bits für die Farbe (0-7)
  unsigned int isOn : 1;       // 1 Bit für den Status (an/aus)
  unsigned int mode : 2;       // 2 Bits für den Modus (0-3)
};

// Funktion zur Ausgabe des Status einer Leuchte
void printLightStatus(struct SmartLight light)
{
  printf("Helligkeit: %u\n", light.brightness);
  printf("Farbe: %u\n", light.color);
  printf("Status: %s\n", light.isOn ? "An" : "Aus");

  switch (light.mode)
  {
  case 0:
    printf("Modus: Normal\n");
    break;
  case 1:
    printf("Modus: Nachtmodus\n");
    break;
  case 2:
    printf("Modus: Party-Modus\n");
    break;
  case 3:
    printf("Modus: Lesemodus\n");
    break;
  default:
    printf("Modus: Unbekannt\n");
    break;
  }
}

// Funktion zur Erstellung einer neuen Leuchte
struct SmartLight createLight(unsigned int brightness, unsigned int color, unsigned int isOn, unsigned int mode)
{
  struct SmartLight light;
  light.brightness = brightness;
  light.color = color;
  light.isOn = isOn;
  light.mode = mode;
  return light;
}

void main()
{
  // Array zur Speicherung von 5 Leuchten
  struct SmartLight lights[5];

  // Informationen der Leuchten ausfüllen
  lights[0] = createLight(10, 3, 1, 2); // Helligkeit: 10, Farbe: 3, Status: An, Modus: Party-Modus
  lights[1] = createLight(5, 1, 0, 1);  // Helligkeit: 5, Farbe: 1, Status: Aus, Modus: Nachtmodus
  lights[2] = createLight(8, 4, 1, 0);  // Helligkeit: 8, Farbe: 4, Status: An, Modus: Normal
  lights[3] = createLight(12, 2, 0, 3); // Helligkeit: 12, Farbe: 2, Status: Aus, Modus: Lesemodus
  lights[4] = createLight(15, 6, 1, 3); // Helligkeit: 15, Farbe: 6, Status: An, Modus: Lesemodus

  // Informationen der Leuchten ausgeben
  for (int i = 0; i < 5; i++)
  {
    printf("Leuchte %d:\n", i + 1);
    printLightStatus(lights[i]);
    printf("\n");
  }
}
