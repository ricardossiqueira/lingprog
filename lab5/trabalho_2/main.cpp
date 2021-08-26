/** Trabalho 2 - Linguagens de Programacao EL1
 *  Periodo: 2021.1
 *  Autor: Ricardo Santos Siqueira
 *  DRE: 118167558
 *  Arquivo: main.cpp
 *  Descricao: Funcao principal.
 */

#include <iostream>
#include <fstream>
#include "Graph.hpp"
#include "filehelper.hpp"

using namespace std;

int main(int argc, char **argv)
{
  vector<Vertice *> vertices;
  Graph graph = Graph();

  createGraph(&graph, &vertices);

  // Definindo ponto inicial
  vertices.at(1)->setDistanceFromStart(0);

  cout << "Edges: " << graph.countEdges() << endl;
  cout << "Vertices: " << graph.countVertices() << endl;
  cout << "Degree: " << graph.degree(vertices.at(0)) << endl;

  // Aplicando o algoritimo no grafo
  graph.dijkstra();
  // Imprimindo menor caminho
  graph.printShortestPath(vertices.at(3));

  return 0;
}