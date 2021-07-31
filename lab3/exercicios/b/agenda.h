#include <iostream>
#include <string>

using namespace std;

class Agenda
{
public:
  void insereNome(string); //setter
  void mostrarNomes();     //getter

private:
  static const int _tamanhoMax = 3;
  int _nomesInseridos = 0;

  string _nomes[_tamanhoMax];

  string _verificaNome(string);
};