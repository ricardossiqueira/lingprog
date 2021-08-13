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
  // Constructor (string nome_do_pais, vector<Estadual> estados_do_pais)
  Nacional(string, vector<Estadual>);

  // Retorna o nome do pais
  string getNome();

  // Imprime a media movel dos estados do objeto para os ultimos n dias,
  // default = 3
  void printMediaMovelPorEstado(short unsigned int = 3);

  // Imprime a media movel do pais para os ultimos n dias, default = 3
  void printMediaMovelNacional(short unsigned int = 3);

  // Imprime os estados agrupados por Alta, Estabilidade e Baixa
  void printAltaEstabilidadeBaixaPorEstado();

  // Imprime o status do pais, se em Alta, Estabilidade ou Baixa
  void printAltaEstabilidadeBaixaNacional();

  // Imprime o estado com maior alta e o estado com maior baixa
  void printMaiorAltaEMaiorBaixa();

  // Imprime o total de obitos no pais e em cada estado individualmente
  void printTotalDeObitos();

  // Para facilitar a identificacao todos os campos privados comecam com _
private:
  // Nome do pais
  string _nome;
  // Estados do pais
  vector<Estadual> _estados;
};