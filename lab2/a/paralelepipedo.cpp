#include "paralelepipedo.h"

Paralelepipedo::Paralelepipedo(double inputX, double inputY, double inputZ)
{
  setX(inputX);
  setY(inputY);
  setZ(inputZ);
}

void Paralelepipedo::setX(double inputX)
{
  if (inputX <= 0)
  {
    cout << "\nO valor informado eh menor ou igual a 0 e sera substituido por 1!" << endl;
    x = 1;
    return;
  }
  x = inputX;
}

void Paralelepipedo::setY(double inputY)
{
  if (inputY <= 0)
  {
    cout << "\nO valor informado eh menor ou igual a 0 e sera substituido por 1!" << endl;
    y = 1;
    return;
  }
  y = inputY;
}

void Paralelepipedo::setZ(double inputZ)
{
  if (inputZ <= 0)
  {
    cout << "\nO valor informado eh menor ou igual a 0 e sera substituido por 1!" << endl;
    z = 1;
    return;
  }
  z = inputZ;
}

double Paralelepipedo::getVolume()
{
  return computeVolume();
}

double Paralelepipedo::computeVolume()
{
  return x * y * z;
}