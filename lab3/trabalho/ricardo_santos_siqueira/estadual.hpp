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
  // Constructor (string nome_do_estado, vector<int> numero_de_obitos)
  Estadual(string, vector<int>);

  // Retorna o nome do estado
  string getNome();

  // Retorna um vector com o historico de obitos do estado
  vector<int> getObitos();

  // Retorna a media movel do estado para os ultimos n dias, default = 3
  float mediaMovel(unsigned short int = 3);

  // Para facilitar a identificacao todos os campos privados comecam com _
private:
  // Nome do estado
  string _nome;
  // Historico de obitos do estado
  vector<int> _obitos;
};