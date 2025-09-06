#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funktion zur Generierung eines Arrays zufälliger Zahlen
void generateRandomArray(int *array, int size)
{
  for (int i = 0; i < size; i++)
  {
    array[i] = rand() % 100; // Zahlen zwischen 0 und 99
  }
}

// Vergleichsfunktion für qsort
int compare(const void *a, const void *b)
{
  return (*(int *)a - *(int *)b);
}

// Funktion zum Messen der Laufzeit
void measureTime(void (*sortFunction)(void *, size_t, size_t, int (*)(const void *, const void *)), int *array, int size, const char *sortName)
{
  int arrayCopy[size];
  for (int i = 0; i < size; i++)
  {
    arrayCopy[i] = array[i];
  }

  clock_t start = clock();
  sortFunction(arrayCopy, size, sizeof(int), compare);
  clock_t end = clock();

  double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("%s took %f seconds to sort the array.\n", sortName, timeTaken);
}

void measureTimeSelectionSort(void (*sortFunction)(int *, int), int *array, int size, const char *sortName)
{
  int arrayCopy[size];
  for (int i = 0; i < size; i++)
  {
    arrayCopy[i] = array[i];
  }

  clock_t start = clock();
  sortFunction(arrayCopy, size);
  clock_t end = clock();

  double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("%s took %f seconds to sort the array.\n", sortName, timeTaken);
}

// Hilfsfunktion zum Tauschen von Elementen
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Selection-Sort-Algorithmus
void selectionSort(int *array, int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    int minIndex = i;
    for (int j = i + 1; j < size; j++)
    {
      if (array[j] < array[minIndex])
      {
        minIndex = j;
      }
    }
    swap(&array[minIndex], &array[i]);
  }
}

void main()
{
  const int size = 1000; // Größe des Arrays
  int array[size];

  // Generiere ein Array zufälliger Zahlen
  generateRandomArray(array, size);

  // Messe die Laufzeit von qsort
  measureTime(qsort, array, size, "qsort");

  // Messe die Laufzeit von Selection-Sort
  measureTimeSelectionSort(selectionSort, array, size, "Selection-Sort");
}
