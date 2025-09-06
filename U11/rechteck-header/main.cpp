#include <iostream>
#include "quadrat.h"

using namespace std;

int main()
{
  Rechteck r(4, 5);
  r.ausgeben();

  Quadrat q(6);
  q.ausgeben();

  return 0;
}
