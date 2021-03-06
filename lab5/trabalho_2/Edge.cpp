/** Trabalho 2 - Linguagens de Programacao EL1
 *  Periodo: 2021.1
 *  Autor: Ricardo Santos Siqueira
 *  DRE: 118167558
 *  Arquivo: Vertice.hpp
 *  Descricao: Implementacao da classe Edge(Aresta).
 */

#include "Edge.hpp"

Edge::Edge(Vertice *x, Vertice *y, double weight)
{
  _x = x;
  _y = y;
  _weight = weight;
}

double Edge::getWeight() { return _weight; }
Vertice *Edge::getX() { return _x; }
Vertice *Edge::getY() { return _y; }

bool Edge::connect(Vertice *x, Vertice *y)
{
  return (x == _x && y == _y) || (x == _y && y == _x);
}