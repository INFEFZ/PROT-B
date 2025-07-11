#include <stdio.h>
#include <string.h>

#define MAX 100

int main()
{
  char s1[MAX];
  char s2[MAX];

  // Eingabe
  printf("Geben Sie die erste Zeichenkette ein: ");
  scanf(" %[^\n]", s1);

  printf("Geben Sie die zweite Zeichenkette ein: ");
  scanf(" %[^\n]", s2);

  // Längenvergleich
  if (strlen(s1) > strlen(s2))
  {
    printf("Die längere Zeichenkette ist: %s, Länge:%d.\n", s1, strlen(s1));
  }
  else if (strlen(s2) > strlen(s1))
  {
    printf("Die längere Zeichenkette ist: %s, Länge:%d.\n", s2, strlen(s2));
  }
  else
  {
    printf("Die Zeichenketten sind gleich lang: Zeichenkette:%s, Länge:%d", s1, strlen(s1));
  }

  return 0;
}
