#include <stdio.h>

// 1. Definition des enum-Typs
enum AmpelPhase 
{
    ROT = 0,
    ROT_GELB = 1,
    GRUEN = 2,
    GELB = 3
};

// 2. Funktion zur Berechnung der nächsten Phase
enum AmpelPhase naechstePhase(enum AmpelPhase aktuelle) 
{
    switch (aktuelle) {
        case ROT:       return ROT_GELB;
        case ROT_GELB:  return GRUEN;
        case GRUEN:     return GELB;
        case GELB:      return ROT;
        default:        return ROT; // Fallback
    }
}

// Funktion zur Umwandlung von enum in Text
const char* phaseAlsText(enum AmpelPhase phase) 
{
    switch (phase) {
        case ROT:       return "ROT";
        case ROT_GELB:  return "ROT_GELB";
        case GRUEN:     return "GRUEN";
        case GELB:      return "GELB";
        default:        return "UNBEKANNT";
    }
}

int main() 
{
    enum AmpelPhase phase = ROT;
    int anzahlWechsel;

    printf("Anzahl der Phasenwechsel: ");
    scanf("%d", &anzahlWechsel);

    for (int i = 0; i < anzahlWechsel; i++) {
        printf("Phase: %s (%d)\n", phaseAlsText(phase), phase);

        if (phase == GELB) {
            printf("Achtung: Nächste Phase ist ROT!\n");
        }

        phase = naechstePhase(phase);
    }

    return 0;
}
