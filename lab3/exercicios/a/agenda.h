#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Agenda
{
public:
  Agenda(int = 3);
  void insereNome(string); //setter
  void mostrarNomes();     //getter

private:
  vector<string> _nomes;
  int _tamanhoMax;

  string _verificaNome(string);
};