#include <stdio.h>


void main(void)
{
            float l = 0;//Länge -> Variablendeklaration
            float b = 0;//Breite -> Variablendeklaration
            float h = 0;//Höche -> Variablendeklaration
            float V;//Volumen wird berechnet

            printf("Geben Sie die Länge in m ein:");//Konsolenausgabe
            scanf("%f",&l);//Konsolen lesen und String2Double-Konvertierung
            printf("Geben Sie die Breite in m ein:");//Konsolenausgabe
            scanf("%f",&b);//Konsolen lesen und String2Double-Konvertierung
            printf("Geben Sie die Höhe in m ein:");//Konsolenausgabe
            scanf("%f",&h);//Konsolen lesen und String2Double-Konvertierung

            V = l * b * h;//Volumenberchnung (Braucht keine Klammer, da alle Multiplikation

            printf("Das Volumen ist %fm3.",V);
}