#include "linha.h"

Linha::Linha(Ponto pA, Ponto pB)
{
  setPontoA(pA);
  setPontoB(pB);
}

void Linha::setPontoA(Ponto pA) { _pA = pA; }
void Linha::setPontoB(Ponto pB) { _pB = pB; }

double Linha::getComprimento()
{
  return sqrt(
      pow(_pA.getX() - _pB.getX(), 2) +
      pow(_pA.getY() - _pB.getY(), 2) +
      pow(_pA.getZ() - _pB.getZ(), 2));
}