/** Trabalho 2 - Linguagens de Programacao EL1
 *  Periodo: 2021.1
 *  Autor: Ricardo Santos Siqueira
 *  DRE: 118167558
 *  Arquivo: Aresta.hpp
 *  Descricao: Arquivo cabecalho da classe Edge(Aresta).
 */

#include "Vertice.hpp"
#include <vector>

using namespace std;

#ifndef EDGE_HPP
#define EDGE_HPP

class Edge
{
private:
  // Arestas do vertice E(x,y) considerando a notacao da Wikipedia
  Vertice *_x, *_y;
  // Peso da aresta
  double _weight;

public:
  // Constructor aresta
  Edge(Vertice *x, Vertice *y, double weight = 1.0);

  // Gettter arestas do vertice
  Vertice *getX(), *getY();
  // Getter peso da aresta
  double getWeight();
};

#endif