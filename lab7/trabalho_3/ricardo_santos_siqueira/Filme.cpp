/*Exercicio Avaliado 3 - Linguagens de Programacao
 *Aluno: Ricardo Santos Siqueira
 *DRE: 118167558
 *Periodo: 2021.1
 *Arquivo: Filme.cpp
 *Descricao: Implementacao da struct Filme
 */

#include "Filme.hpp"

using namespace std;

// Friends
ostream &operator<<(ostream &out, const Filme &filme)
{
  out
      << "Nome: "
      << filme._nome
      << endl
      << "Produtora: "
      << filme._produtora
      << endl
      << "Nota: "
      << filme._nota
      << endl;

  return out;
}

istream &operator>>(istream &in, Filme &filme)
{
  in >> filme._nome;
  in >> filme._produtora;
  in >> filme._nota;

  return in;
}

// Constructor
Filme::Filme(string nome, string produtora, double nota)
    : _nome(nome), _produtora(produtora), _nota(nota){};

// Getters
string Filme::getNome() const { return _nome; }
string Filme::getProdutora() const { return _produtora; }
double Filme::getNota() const { return _nota; }

// Setters
void Filme::setProdutora(const string produtora) { _produtora = produtora; }
void Filme::setNota(const double nota) { _nota = nota; }

// Operators
bool Filme::operator<(const Filme &filme) const
{
  if (_lower(_nome) < _lower(filme._nome))
    return true;
  return false;
}

bool Filme::operator>(const Filme &filme) const
{
  if (_lower(_nome) < _lower(filme._nome))
    return true;
  return false;
}

bool Filme::operator==(const Filme &filme) const
{
  if (_lower(_nome) == _lower(filme._nome))
    return true;
  return false;
}

// Helper function
string Filme::_lower(const string arg) const
{
  string res;
  for (auto &letter : arg)
    res += tolower(letter);
  return res;
}