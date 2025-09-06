#include <stdio.h>
#include <stdlib.h>

// Vergleichsfunktion für qsort
int compare(const void *a, const void *b)
{
  return (*(int *)a - *(int *)b);
}

// Funktion zum Drucken eines Arrays
void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

// Hauptprogramm zur Demonstration von qsort
void main()
{
  int arr[] = {10, 7, 8, 9, 1, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Unsortiertes Array: \n");
  printArray(arr, n);

  // Verwenden von qsort zum Sortieren des Arrays
  qsort(arr, n, sizeof(int), compare);

  printf("Sortiertes Array: \n");
  printArray(arr, n);
}