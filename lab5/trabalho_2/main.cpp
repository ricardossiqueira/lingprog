/** Trabalho 2 - Linguagens de Programacao EL1
 *  Periodo: 2021.1
 *  Autor: Ricardo Santos Siqueira
 *  DRE: 118167558
 *  Arquivo: main.cpp
 *  Descricao: Funcao principal.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include "Vertice.hpp"
#include "Graph.hpp"
#include "filehelper.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  vector<Vertice *> vertices;
  Graph graph = Graph();
  string origin, target;
  Vertice *originptr, *targetptr, *biggestDegree;

  createGraph(&graph, &vertices);

  for (int i = 1; i < argc; i++)
  {
    switch (atoi(argv[i]))
    {
    case 1:
      cout
          << "\n1- Numero de vertices e enlaces no grafo"
          << "\nEnlaces: "
          << graph.countEdges()
          << "\nVertices: "
          << vertices.size()
          << endl;
      break;

    case 2:
      cout
          << "\n2- Lista de todos os vertices no grafo"
          << "\nVertices: ";
      for (unsigned int i = 0; i < vertices.size(); i++)
        cout << vertices.at(i)->getId() << " ";
      cout
          << endl;
      break;

    case 3:
      cout
          << "\n3- Caminho de menor custo (Dijkstra)";

      cout
          << "\nVertices : ";
      for (unsigned int i = 0; i < vertices.size(); i++)
        cout << vertices.at(i)->getId() << " ";

      cout
          << "\nEntre com a origem: ";
      cin >> origin;

      cout
          << "\nEntre com o alvo: ";
      cin >> target;

      for (unsigned int i = 0; i < vertices.size(); i++)
      {
        if (vertices.at(i)->getId() == origin)
          originptr = vertices.at(i);
        if (vertices.at(i)->getId() == target)
          targetptr = vertices.at(i);
      }

      // Definindo ponto inicial
      originptr->setDistanceFromStart(0);

      // Aplicando o algoritimo no grafo
      graph.dijkstra();

      // Imprimindo menor caminho ate o alvo
      graph.printShortestPath(targetptr);

      cout << endl;
      break;

    case 4:
      cout
          << "\n4- Diametro do grafo\n";

      break;

    case 5:
      cout
          << "\n5- Vertice com maior grau\n";

      biggestDegree = vertices.at(0);
      for (unsigned int i = 1; i < vertices.size(); i++)
        if (graph.degree(vertices.at(i)) > graph.degree(biggestDegree))
          biggestDegree = vertices.at(i);

      cout << "Vertice: "
           << biggestDegree->getId()
           << "\nDegree: "
           << graph.degree(biggestDegree) << endl;
      break;

    case 6:
      cout
          << "\n6- Vertice com maior centralidade de intermediacao\n";

      break;

    default:
      cout
          << "\nOpcoes:\n"
          << "\n1- Numero de vertices e enlaces no grafo"
          << "\n2- Lista de todos os vertices no grafo"
          << "\n3- Caminho de menor custo (Dijkstra)"
          << "\n4- Diametro do grafo"
          << "\n5- Vertice com maior grau"
          << "\n6- Vertice com maior centralidade de intermediacao"
          << endl;
      break;
    }
  }

  return 0;
}