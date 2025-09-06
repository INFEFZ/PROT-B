#include <stdio.h>
#include <stdlib.h>

void main()
{
  int n;
  printf("Geben Sie die Anzahl der Elemente ein: ");
  scanf("%d", &n);

  // Dynamische Speicherzuweisung für ein Array von n ganzen Zahlen
  int *arr = (int *)malloc(n * sizeof(int));

  // Überprüfen, ob malloc erfolgreich war
  if (arr == NULL)
  {
    printf("Speicher konnte nicht zugewiesen werden.\n");
    return 1;
  }

  // Eingabe von Elementen in das Array
  for (int i = 0; i < n; i++)
  {
    printf("Geben Sie Element %d ein: ", i + 1);
    scanf("%d", &arr[i]);
  }

  // Berechnung des Durchschnitts
  int summe = 0;
  for (int i = 0; i < n; i++)
  {
    summe += arr[i];
  }

  double durchschnitt = (double)summe / n;

  // Ausgabe des Durchschnittswerts
  printf("Der Durchschnittswert der Elemente ist: %.2f\n", durchschnitt);

  // Freigeben des dynamisch zugewiesenen Speichers
  free(arr);
}
