#include "estadual.h"

Estadual::Estadual(string nome, vector<int> obitos)
{
  _nome = nome;
  _obitos = obitos;
}

// Setters
void Estadual::setNome(string nome) { _nome = nome; }

// Getters
string Estadual::getNome() { return _nome; }
vector<int> Estadual::getObitos() { return _obitos; }