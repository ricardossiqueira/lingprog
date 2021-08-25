/** Trabalho 2 - Linguagens de Programacao EL1
 *  Periodo: 2021.1
 *  Autor: Ricardo Santos Siqueira
 *  DRE: 118167558
 *  Arquivo: Graph.hpp
 *  Descricao: Arquivo cabecalho da classe Graph(Grafo).
 */

#include "Edge.hpp"
#include <vector>
#include "algorithm"
#include <cmath>
#include <iostream>

using namespace std;

#ifndef GRAPH_HPP
#define GRAPH_HPP

class Graph
{
private:
  // Vetor de ponteiros para arestas(grafo)
  vector<Edge *> _edges;
  // Vetor de ponteiros para vertices
  vector<Vertice *> _vertices;

  // Retorna a distancia entre dois vertices
  float _distanceBetweenVertices(Vertice *x, Vertice *y);

  // Retorna os vertices adjascentes a um vertice
  vector<Vertice *> *_adjacentVertices(Vertice *x);

  // Retorna o vertice com menor peso e remove o mesmo do vetor _vertices
  Vertice *_extractSmallestVertice();

public:
  // Cria uma aresta e adiciona ao vetor _edges(grafo)
  void createEdge(Vertice *x, Vertice *y, double weight = STD_WEIGHT); //*OK

  // Numero de vertices do grafo
  int countVertices(), //*OK
      // Numero de arestas/enlaces do grafo
      countEdges(); //*OK

  // Caminho mais curto entre dois vertices usando o algoritimo de Dijkstra
  void dijkstraShortestPath();

  // Diametro do grafo
  int graphDiametre();

  // Grau de um vertice no grafo
  int degree(Vertice x);

  //############################################################################
  Vertice *interfaceExtractSmallestVertice();
};

#endif