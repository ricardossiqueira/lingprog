#include <iostream>

using namespace std;

class Paralelepipedo
{
public:
  Paralelepipedo(double, double, double);
  void setX(double);
  void setY(double);
  void setZ(double);
  double getVolume();

private:
  double x, y, z;
  double computeVolume();
};