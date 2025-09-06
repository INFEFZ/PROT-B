#include <iostream>
using namespace std;

class Rechteck
{
private:
  int breite;
  int hoehe;

public:
  Rechteck(int b, int h);

  int berechneFlaeche();
  int berechneUmfang();
  void ausgeben();
};
