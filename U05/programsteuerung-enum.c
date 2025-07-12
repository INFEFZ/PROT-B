#include <stdio.h>

// 1. Definition des Aufzählungstyps
enum GeraeteStatus
{
  AUS = 0,
  STANDBY = 1,
  AKTIV = 2,
  FEHLER = 3
};

int main()
{
  // 2. Initialisierung
  enum GeraeteStatus status = STANDBY;

  int eingabe;
  printf("Geben Sie den Gerätestatus ein (0=AUS, 1=STANDBY, 2=AKTIV, 3=FEHLER): ");
  scanf("%d", &eingabe);

  // 4. Umwandlung in enum (ohne Überprüfung auf Gültigkeit)
  status = (enum GeraeteStatus)eingabe;

  // 5. Ausgabe mit switch
  switch (status)
  {
  case AUS:
    printf("Gerät ist ausgeschaltet. (Wert: %d)\n", status);
    break;
  case STANDBY:
    printf("Gerät ist im Standby. (Wert: %d)\n", status);
    break;
  case AKTIV:
    printf("Gerät läuft. (Wert: %d)\n", status);
    break;
  case FEHLER:
    printf("Gerät hat einen Fehler! (Wert: %d)\n", status);
    break;
  default:
    printf("Ungültiger Statuswert!\n");
  }

  return 0;
}
