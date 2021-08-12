/** Trabalho 1 - Linguagens de Programacao EL1
 * Periodo: 2021.1
 * Autor: Ricardo Santos Siqueira
 * DRE: 118167558
 * Arquivo: estadual.cpp
 * Descricao: Implementacao dos metodos da classe responsavel por lidar com os
 *            dados referentes aos estados.
 */

#include "estadual.hpp"

// Construtor
Estadual::Estadual(string nome, vector<int> obitos)
{
  _nome = nome;
  _obitos = obitos;
}

// Getters
string Estadual::getNome() { return _nome; }
vector<int> Estadual::getObitos() { return _obitos; }

float Estadual::mediaMovel(unsigned short int dias)
{
  float media = 0.0;

  if (dias < 1 || dias > 30)
  {
    cout << "Dias deve ser um valor entre 1 e 30!\n"
         << endl;
    return media;
  }

  for (unsigned short int i = 0; i < dias; i++)
    media += _obitos.at(i);

  return media / dias;
}