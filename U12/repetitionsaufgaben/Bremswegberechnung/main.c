#include <stdio.h>

void main(void)
{
     float a = 0;
     float t = 0;
     float s;

    printf("Geben Sie das gewünschte Verzögerung in m/s2 ein:");
    scanf("%f",&a);
    printf("Geben Sie das gewünschte Zeit in s ein:");
    scanf("%f",&t);

    s = (a * t * t) / 2;

    printf("Der Bremsweg ist %fm",s);
            
}