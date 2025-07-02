#include <stdio.h>

int main()
{
  float temperaturen[7];
  float summe = 0.0;
  float durchschnitt;
  float max = -1000.0, min = 1000.0; // Unrealistische Startwerte zum Vergleich

  // Temperaturen eingeben
  for (int i = 0; i < 7; i++)
  {
    printf("Geben Sie die Temperatur für Tag %d ein: ", i + 1);
    scanf("%f", &temperaturen[i]);

    summe += temperaturen[i];

    // Höchste Temperatur bestimmen
    if (temperaturen[i] > max)
    {
      max = temperaturen[i];
    }

    // Niedrigste Temperatur bestimmen
    if (temperaturen[i] < min)
    {
      min = temperaturen[i];
    }
  }

  // Durchschnitt berechnen
  durchschnitt = summe / 7.0;

  // Ausgabe der Temperaturen
  printf("\nEingegebene Temperaturen: ");
  for (int i = 0; i < 7; i++)
  {
    printf("%.1f ", temperaturen[i]);
  }

  // Statistiken ausgeben
  printf("\nDurchschnittstemperatur: %.2f\n", durchschnitt);
  printf("Höchste Temperatur: %.1f\n", max);
  printf("Niedrigste Temperatur: %.1f\n", min);

  return 0;
}
