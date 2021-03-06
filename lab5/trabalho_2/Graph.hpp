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

  // Retorna a lista de vertices adjacentes a um vertice do vetor _edges
  vector<Vertice *> *_adjacentVertices(Vertice *x);

  // Retorna o vertice com menor peso e remove o mesmo do vetor _vertices
  Vertice *_extractSmallestVertice();

  // Verifica se um dado vetor de vertices contem um dado vertice
  bool _contains(vector<Vertice *> &vertices, Vertice *vertice);

public:
  // Cria uma aresta e adiciona ao vetor _edges(grafo)
  void createEdge(Vertice *x, Vertice *y, double weight = STD_WEIGHT);

  // Numero de vertices do grafo
  int countVertices(),
      // Numero de arestas/enlaces do grafo
      countEdges();

  // Computa o algoritimo de Dijkstra no grafo a partir de um vertice inicial
  void dijkstra();

  // Imprime o caminho mais curto para um vertice qualquer
  void printShortestPath(Vertice *target);

  // Diametro do grafo
  int graphDiametre(); //! NAO IMPLEMENTADO

  // Grau de um vertice no grafo (interface para Graph::_adjacentVertices())
  int degree(Vertice *x);
};

#endif