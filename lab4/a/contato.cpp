#include "agenda.hpp"

Contato::Contato(string nome, unsigned short int idade, string profissao)
{
  setNome(nome);
  setIdade(idade);
  setProfissao(profissao);
}

void Contato::setNome(string nome)
{
  if (nome.length() > MAX_LEN_NOME)
  {
    nome.substr(0, MAX_LEN_NOME);
    cout << "Nome excede 10 caracteres, truncado para: " << nome << endl;
  }
  _nome = nome;
}
void Contato::setIdade(unsigned short int idade) { _idade = idade; }
void Contato::setProfissao(string profissao) { _profissao = profissao; }

string Contato::getNome() { return _nome; }
unsigned short int Contato::getIdade() { return _idade; }
string Contato::getProfissao() { return _profissao; }
