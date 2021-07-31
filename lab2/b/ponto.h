class Ponto
{
public:
  Ponto(double = 1.0, double = 1.0, double = 1.0);
  void setX(double), setY(double), setZ(double);
  double getX(), getY(), getZ();

private:
  double _x, _y, _z;
};