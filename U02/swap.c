#include <stdio.h>

void swap(int *pZahl1, int *pZahl2)
{
  int temp = *pZahl1;
  *pZahl1 = *pZahl2;
  *pZahl2 = temp;
}

void main(void)
{
  int Zahl1 = 10,
      Zahl2 = 20;

  printf("Vor Swap(): Zahl1=%d, Zahl2=%d\n", Zahl1, Zahl2);
  swap(&Zahl1, &Zahl2);
  printf("Nach Swap(): Zahl1=%d, Zahl2=%d\n", Zahl1, Zahl2);
}
