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

// Funktion zum Drucken eines Arrays
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void arrayCopy(int arrsrc[], int arrdest[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arrdest[i] = arrsrc[i];
    }
}

// selection sort

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

// quicksort

// Vergleichsfunktion für qsort
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

#define MAX_SIZE 1024

void main()
{
    int arrSort[MAX_SIZE] = {0};
    int arr[MAX_SIZE] = {0};

    // anzahl elemente ermitteln
    int size = sizeof(arr) / sizeof(arr[0]);

    // zufalls zahlen eintragen
    generateRandomArray(arr, size);

    // array kopieren
    arrayCopy(arr, arrSort, size);

    clock_t start = clock();
    selectionSort(arrSort, size);
    clock_t end = clock();

    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("%s took %f seconds to sort the array.\n", "selectionSort", timeTaken);

    // array kopieren
    arrayCopy(arr, arrSort, size);

    start = clock();
    qsort(arrSort, size, sizeof(int), compare);
    end = clock();

    timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("%s took %f seconds to sort the array.\n", "quicksort", timeTaken);
}