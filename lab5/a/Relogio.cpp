#include "Relogio.hpp"

Relogio::Relogio()
{
  Relogio::resetHora();
}

Relogio::Relogio(int h, int m, int s)
{
  Relogio::resetHora(h, m, s);
}

void Relogio::resetHora()
{
  time(&_hora);
  _infoHora = localtime(&_hora);

  resetHora(_infoHora->tm_hour, _infoHora->tm_min, _infoHora->tm_sec);
}

void Relogio::resetHora(int h, int m, int s)
{
  setHoras(h);
  setMinutos(m);
  setSegundos(s);
}

int Relogio::getHoras() { return _hora; }
int Relogio::getMinutos() { return _minutos; }
int Relogio::getSegundos() { return _segundos; }

void Relogio::setHoras(int h) { _horas = (h >= 0 && h < 24) ? h : 0; }
void Relogio::setMinutos(int m) { _minutos = (m >= 0 && m < 60) ? m : 0; }
void Relogio::setSegundos(int s) { _segundos = (s >= 0 && s < 60) ? s : 0; }

void Relogio::mostreHorario()
{
  cout
      << setfill('0')
      << setw(2)
      << getHoras()
      << ":"
      << setw(2)
      << getMinutos()
      << ":"
      << setw(2)
      << getSegundos()
      << endl;
}