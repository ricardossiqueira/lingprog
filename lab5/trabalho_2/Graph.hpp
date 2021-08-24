/** Trabalho 2 - Linguagens de Programacao EL1
 *  Periodo: 2021.1
 *  Autor: Ricardo Santos Siqueira
 *  DRE: 118167558
 *  Arquivo: Graph.hpp
 *  Descricao: Arquivo cabecalho da classe Graph(Grafo).
 */

#include "Edge.hpp"
#include <vector>

using namespace std;

#ifndef GRPAH_HPP
#define GRAPH_HPP

class Grafo
{
private:
  // Estrutura do grafo como um vetor de objetos da classe Edge
  vector<Edge> _graph;

public:
  Grafo();
};

#endif