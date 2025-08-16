#include <stdio.h>


// Funktion zur Berechnung der Fläche eines Kreises
float rechneFlaeche(float radius) {
    return 3.141592653 * radius * radius;
}

// Funktion zur Berechnung des Umfangs eines Kreises
float rechneUmfang(float radius) {
    return 2 * 3.141592653 * radius;
}

void main(void) {
    float radius;
    float flaeche; 
    float umfang;

    // Benutzer nach dem Radius fragen
    printf("Bitte geben Sie den Radius des Kreises ein: ");
    scanf("%f", &radius);

    // Fläche und Umfang berechnen
    flaeche = rechneFlaeche(radius);
    umfang = rechneUmfang(radius);

    // Ergebnisse ausgeben
    printf("Die Fläche des Kreises beträgt: %.2f\n", flaeche);
    printf("Der Umfang des Kreises beträgt: %.2f\n", umfang);
}
