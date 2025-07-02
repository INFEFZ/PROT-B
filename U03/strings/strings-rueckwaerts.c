#include <stdio.h>
#include <string.h>

#define MAX 100

void ausgabe_mit_array(char str[])
{
  size_t len = strlen(str);
  char ausgabe[len];

  for (size_t i = len; i > 0; i--)
  {
    ausgabe[len - i] = str[i - 1];
  }

  printf("Rückwärts mit Arry: %s\n", ausgabe);
}

void ausgabe_mit_pointer(char *ptr)
{
  size_t len = strlen(ptr);
  char ausgabe[len];

  for (size_t i = len; i > 0; i--)
  {
    ausgabe[len - i] = *(ptr + i - 1);
  }

  printf("Rückwärts mit Pointer: %s\n", ausgabe);
}

int main()
{
  char eingabe[MAX];

  // Eingabe
  printf("Geben Sie den String ein: ");
  scanf(" %[^\n]", eingabe);
  // fgets(s, MAX, stdin);

  // ausgabe mit array
  ausgabe_mit_array(eingabe);

  // ausgabe mit array
  ausgabe_mit_pointer(eingabe);

  return 0;
}
