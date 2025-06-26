#include <stdio.h>
#include "functions.h"

/*
tasks.json
"args": [
                "-fdiagnostics-color=always",
                "-g",
                "${fileDirname}/*.c",
                "${fileDirname}/*.h",
                "-o",
                "${fileDirname}/${fileBasenameNoExtension}"
            ],
*/
// gcc *.c -o main.exe & ./main.exe

void main(void)
{
  int a = 10,
      b = 20;

  int result = addiere(a, b);
  printf("addiere(): %d + %d = %d\n", a, b, result);
}
