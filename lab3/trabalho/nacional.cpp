#include "nacional.h"

Nacional::Nacional(string nome, vector<Estadual> estados)
{
  _nome = nome;
  _estados = estados;
}

// Getters
string Nacional::getNome() { return _nome; }
vector<Estadual> Nacional::getEstados() { return _estados; }