#include <stdio.h>

// Funktion zum Vertauschen von zwei Werten
void swap(int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

// Funktion zur Durchführung von Selection Sort
void selectionSort(int arr[], int n)
{
  int i, j, min_idx;
  // Ein Element nach dem anderen im unsortierten Array verschieben
  for (i = 0; i < n - 1; i++)
  {
    // Das kleinste Element im unsortierten Array finden
    min_idx = i;
    for (j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[min_idx])
        min_idx = j;
    }

    // Das gefundene kleinste Element mit dem ersten Element vertauschen
    swap(&arr[min_idx], &arr[i]);
  }
}

// Funktion zum Drucken eines Arrays
void printArray(int arr[], int size)
{
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

// Hauptprogramm zur Demonstration von Selection Sort
void main()
{
  int arr[] = {64, 25, 12, 22, 11};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("Unsortiertes Array: \n");
  printArray(arr, n);

  selectionSort(arr, n);
  printf("Sortiertes Array: \n");
  printArray(arr, n);
}