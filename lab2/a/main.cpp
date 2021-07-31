#include "paralelepipedo.h"

int main()
{
  double dX = 3.0, dY = 1.0, dZ = 2.0;

  Paralelepipedo paralelepipedo(dX, dY, dZ);

  cout << "\nO volume do paralelepipedo eh " << paralelepipedo.getVolume() << endl;

  paralelepipedo.setX(0);

  cout << "\nO novo volume do paralelepipedo eh " << paralelepipedo.getVolume() << endl;

  return 0;
}