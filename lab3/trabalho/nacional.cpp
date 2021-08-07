/** Trabalho 1 - Linguagens de Programacao EL1
 * Periodo: 2021.1
 * Autor: Ricardo Santos Siqueira
 * DRE: 118167558
 * Arquivo: nacional.cpp
 * Descricao: Implementacao da classe Nacional responsavel por cpnfigurar
 *            um novo pais e lidar com as respectivas funcoes.
 */

#include "nacional.hpp"

// Constructor
Nacional::Nacional(string nome, vector<Estadual> estados)
{
  _nome = nome;
  _estados = estados;
}

// Getters
string Nacional::getNome() { return _nome; }
vector<Estadual> Nacional::getEstados() { return _estados; }

void Nacional::printMediaMovelNacional(short unsigned int dias)
{
  float media = 0.0;
  // Arredonda a saida para 2 casas decimais
  cout.precision(4);
  cout << " Pais    | Media Movel " << endl;
  cout << "---------|-------------" << endl;
  cout << " " << getNome();
  cout << "  | ";
  for (long unsigned int i = 0; i < _estados.size(); i++)
  {
    Estadual estado = _estados.at(i);
    media += estado.mediaMovel(dias);
  }
  cout << media / _estados.size() << "\n"
       << endl;
}

void Nacional::printMediaMovelPorEstado(short unsigned int dias)
{
  // Arredonda a saida para 2 casas decimais
  cout.precision(4);
  cout << " Estados | Media Movel " << endl;
  cout << "---------|-------------" << endl;
  for (long unsigned int i = 0; i < _estados.size(); i++)
  {
    Estadual estado = _estados.at(i);
    cout << " " << estado.getNome();
    // \t = 4 espacos
    cout << "\t | " << estado.mediaMovel(dias);
    cout << endl;
  }
}
