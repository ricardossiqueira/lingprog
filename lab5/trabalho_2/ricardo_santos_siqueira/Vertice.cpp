/** Trabalho 2 - Linguagens de Programacao EL1
 *  Periodo: 2021.1
 *  Autor: Ricardo Santos Siqueira
 *  DRE: 118167558
 *  Arquivo: Vertice.hpp
 *  Descricao: Implementacao da classe Vertice.
 */

#include "Vertice.hpp"

Vertice::Vertice(string id, Vertice *previous, float distanceFromStart)
{
  _id = id;
  _previous = previous;
  _distanceFromStart = distanceFromStart;
}

string Vertice::getId() { return _id; }
Vertice *Vertice::getPrevious() { return _previous; }
float Vertice::getDistanceFromStart() { return _distanceFromStart; }

void Vertice::setPrevious(Vertice *previous) { _previous = previous; }
void Vertice::setDistanceFromStart(float distanceFromStart)
{
  _distanceFromStart = distanceFromStart;
}