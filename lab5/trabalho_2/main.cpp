/** Trabalho 2 - Linguagens de Programacao EL1
 *  Periodo: 2021.1
 *  Autor: Ricardo Santos Siqueira
 *  DRE: 118167558
 *  Arquivo: main.cpp
 *  Descricao: Funcao principal.
 */

#include "Graph.hpp"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
  Vertice
      a("A"),
      b("B"),
      c("C"),
      d("D"),
      e("E"),
      f("F"),
      g("G");

  Graph graph = Graph();

  graph.createEdge(&a, &b, 3.54);
  graph.createEdge(&c, &d, 3.2);
  graph.createEdge(&a, &c, 5.1);
  graph.createEdge(&g, &c, 1.1);

  // Definindo a como comeco
  b.setDistanceFromStart(0);

  cout << "Edges: " << graph.countEdges() << endl;
  cout << "Vertices: " << graph.countVertices() << endl;
  // cout << "Degree: " << graph.degree(&a) << endl;
  // graph.getVerticesOverview();
  graph.dijkstra();
  graph.printShortestPath(&d);

  return 0;
}