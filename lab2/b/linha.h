#include "ponto.h"
#include <cmath>

using namespace std;

class Linha
{
public:
  Linha(Ponto, Ponto);
  double getComprimento();
  void setPontoA(Ponto), setPontoB(Ponto);

private:
  Ponto _pA, _pB;
};