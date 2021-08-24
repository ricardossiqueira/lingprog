#include "time.h"
#include <iostream>
#include <iomanip>
#include <string>

#ifndef RELOGIO_H
#define RELOGIO_H

using namespace std;

class Relogio
{
private:
  time_t _hora;
  struct tm *_infoHora;
  int _segundos, _minutos, _horas;

public:
  Relogio();
  Relogio(int h, int m, int s);

  void resetHora(),
      resetHora(int h, int m, int s);

  void setHoras(int h),
      setMinutos(int m),
      setSegundos(int s);

  void mostreHorario();

  int getHoras(),
      getMinutos(),
      getSegundos();
};

#endif