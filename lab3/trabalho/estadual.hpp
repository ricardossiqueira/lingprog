/** Trabalho 1 - Linguagens de Programacao EL1
 * Periodo: 2021.1
 * Autor: Ricardo Santos Siqueira
 * DRE: 118167558
 * Arquivo: estadual.hpp
 * Descricao: Arquivo cabecalho da classe Estadual.
 */

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Estadual
{
public:
  // Construtor para classe Estadual
  Estadual(string, vector<int>);
  // Setters
  void setNome(string);
  // Getters
  string getNome();
  vector<int> getObitos();

  // Retorna a media movel do estado para os ultimos n dias, default = 3
  float mediaMovel(unsigned short int = 3);

private:
  // Campos privados da classe
  string _nome;
  vector<int> _obitos;
};