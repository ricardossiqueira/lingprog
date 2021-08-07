/** Trabalho 1 - Linguagens de Programacao EL1
 * Periodo: 2021.1
 * Autor: Ricardo Santos Siqueira
 * DRE: 118167558
 * Arquivo: nacioanl.hpp
 * Descricao: Arquivo cabecalho da classe Nacional.
 */

#include "estadual.hpp"
#include <vector>

class Nacional
{
public:
  // Constructor
  Nacional(string, vector<Estadual>);
  // Getters
  string getNome();

  // Imprime a media movel dos estados do objeto para os ultimos n dias,
  // default = 3
  void printMediaMovelPorEstado(short unsigned int = 3);

  // Imprime a media movel do pais para os ultimos n dias, default = 3
  void printMediaMovelNacional(short unsigned int = 3);

  // Imprime os estados agrupados por Alta, Estabilidade e Baixa
  void printAltaEstabilidadeBaixa();

private:
  // Campos privados da classe
  string _nome;
  vector<Estadual> _estados;
};