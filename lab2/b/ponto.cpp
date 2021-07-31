#include "ponto.h"

Ponto::Ponto(double x, double y, double z)
{
  setX(x);
  setY(y);
  setZ(z);
}

void Ponto::setX(double x) { _x = x; }
void Ponto::setY(double y) { _y = y; }
void Ponto::setZ(double z) { _z = z; }

double Ponto::getX() { return _x; }
double Ponto::getY() { return _y; }
double Ponto::getZ() { return _z; }
