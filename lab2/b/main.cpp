// Ponto ja foi incluido em linha.h
// #include "ponto.h"
#include "linha.h"
#include <iostream>

void printCoordenadas(Ponto p)
{
  static int count = 1;
  cout << "[Impressao no. " << count << " ] : Coordenadas de p (" << p.getX() << ", " << p.getY() << ", " << p.getZ() << ")" << endl;
  count++;
}

int main()
{
  Ponto pA;
  Ponto pB(-1.0, -1.0, -1.0);
  Linha linha(pA, pB);

  printCoordenadas(pA);
  printCoordenadas(pB);

  cout << "O comprimento da linha eh " << linha.getComprimento() << endl;

  cout << "Redefinindo o valor do ponto A para (2,2,2) e recalculando..." << endl;

  pA.setX(2.0);
  pA.setY(2.0);
  pA.setZ(2.0);

  linha.setPontoA(pA);

  printCoordenadas(pA);
  printCoordenadas(pB);

  cout << "O novo comprimento da linha eh " << linha.getComprimento() << endl;

  return 0;
}