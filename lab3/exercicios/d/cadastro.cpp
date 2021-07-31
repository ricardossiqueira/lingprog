#include "cadastro.h"

void Cadastro::setNome(string nome) { _nome = _verificaNome(nome); }
void Cadastro::setProfissao(string profissao) { _profissao = profissao; }
void Cadastro::setIdade(int idade) { _idade = idade; }

string Cadastro::getNome() { return _nome; }
string Cadastro::getProfissao() { return _profissao; }
int Cadastro::getIdade() { return _idade; }

string Cadastro::_verificaNome(string nome)
{
  if (nome.length() > 10)
  {
    cout << "Nome maior que 10 caracteres, truncando..." << endl;
    return nome.substr(0, 10);
  }
  return nome;
}