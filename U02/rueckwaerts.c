#include <stdio.h>

void rueckwaerts(char *str)
{
  if (*str == '\0')
    return;

  rueckwaerts(str + 1);
  putchar(*str);
}

int main()
{
  char eingabe[100];

  printf("Text: ");
  fgets(eingabe, sizeof(eingabe), stdin);

  printf("Rueckwaerts: ");
  rueckwaerts(eingabe);

  printf("\n");

  return 0;
}