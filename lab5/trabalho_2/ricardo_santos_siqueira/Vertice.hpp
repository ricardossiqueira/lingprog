/** Trabalho 2 - Linguagens de Programacao EL1
 *  Periodo: 2021.1
 *  Autor: Ricardo Santos Siqueira
 *  DRE: 118167558
 *  Arquivo: Vertice.hpp
 *  Descricao: Arquivo cabecalho da classe Vertice.
 */

#include <string>
#include <cmath>

using namespace std;

#ifndef VERTICE_HPP
#define VERTICE_HPP

class Vertice
{
private:
  // Id(nome) do vertice
  string _id;

  // Referencia para o vertice anterior
  Vertice *_previous;

  // Somatorio dos pesos do vertice de origem ate o atual
  float _distanceFromStart;

public:
  // Constructor vertice
  Vertice(
      string id,
      Vertice *previous = NULL,
      float distanceFromStart = INFINITY);

  // Getters
  string getId();
  Vertice *getPrevious();
  float getDistanceFromStart();

  // Setters
  void setPrevious(Vertice *previous),
      setDistanceFromStart(float distanceFromStart);
};

#endif