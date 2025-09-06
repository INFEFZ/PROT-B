#include <iostream>
#include "rechteck.h"

using namespace std;

Rechteck::Rechteck(int b, int h)
    : breite(b), hoehe(h)
{
}

int Rechteck::berechneFlaeche()
{
  return breite * hoehe;
}

int Rechteck::berechneUmfang()
{
  return 2 * (breite + hoehe);
}

void Rechteck::ausgeben()
{
  cout << "Breite: " << breite
       << ", Höhe: " << hoehe
       << ", Fläche: " << berechneFlaeche()
       << ", Umfang: " << berechneUmfang() << endl;
}
