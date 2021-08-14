#include <iostream>
#include <string>

using namespace std;

class Contato
{
private:
  string _nome;
  unsigned short int _idade;
  string _profissao;

public:
  Contato(string nome, unsigned short int idade, string profissao);

  string
  getNome(),
      getProfissao();
  unsigned short int getIdade();

  void
      setNome(string),
      setIdade(unsigned short int),
      setProfissao(string);
};
