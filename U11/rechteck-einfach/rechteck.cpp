#include <iostream>
using namespace std;

class Rechteck {
private:
    int breite;
    int hoehe;
public:
    Rechteck(int b, int h) : breite(b), hoehe(h) {}
    int berechneFlaeche() { return breite * hoehe; }
    int berechneUmfang() { return 2 * (breite + hoehe); }
    void ausgeben() {
        cout << "Breite: " << breite
             << ", Höhe: " << hoehe
             << ", Fläche: " << berechneFlaeche()
             << ", Umfang: " << berechneUmfang() << endl;
    }
};

// Zusatz: Quadrat erbt von Rechteck
class Quadrat : public Rechteck {
public:
    Quadrat(int seite) : Rechteck(seite, seite) {}
};

int main() {
    Rechteck r(4, 5);
    r.ausgeben();

    Quadrat q(6);
    q.ausgeben();

    return 0;
}