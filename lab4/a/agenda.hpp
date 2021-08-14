#include <vector>
#include <fstream>
#include "contato.hpp"

#define MAX_LEN_NOME 10
#define MAX_LEN_AGENDA 10

using namespace std;

class Agenda
{

private:
  vector<Contato> _contatos;
  unsigned int _maxLenAgenda = MAX_LEN_AGENDA;
  unsigned short int _maxLenNome = MAX_LEN_NOME;
  fstream _file;

  int _encontrarContato(Contato);

public:
  void
      inserirContato(Contato),
      removerContato(unsigned int),
      escreverMudancas(),
      lerMudancas();
};
