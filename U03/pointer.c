#include <stdio.h>

int main()
{
  int x = 25;

  // 1. Pointer auf x
  int *px = &x;

  // 2. Adresse und Wert ausgeben
  printf("Adresse von x: %p\n", (void *)&x);
  printf("Wert von x über Pointer: %d\n", *px);

  // 3. Wert von x über Pointer ändern
  *px = 50;

  // 4. Neuen Wert ausgeben
  printf("Neuer Wert von x: %d\n", x);

  // 5. void-Pointer auf x
  void *vp = &x;
  printf("Wert von x über void*-Pointer: %d\n", *(int *)vp);

  return 0;
}
