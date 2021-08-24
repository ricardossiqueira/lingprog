#include <iostream>
#include "Relogio.hpp"

using namespace std;

int main()
{
  Relogio relogio1 = Relogio();
  relogio1.mostreHorario();

  Relogio relogio2 = Relogio(24, 43, 12);
  relogio2.mostreHorario();
  return 0;
}