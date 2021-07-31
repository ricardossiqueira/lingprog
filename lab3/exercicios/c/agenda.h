#include "cadastro.h"

class Agenda
{
public:
  void insereCadastro(string, string, int); //setter
  void mostrarCadastros();                  //getter

private:
  static const int _tamanhoMax = 3;
  int _cadastrosAdicionados = 0;

  Cadastro _cadastros[_tamanhoMax];
};