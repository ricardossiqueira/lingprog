/** Trabalho 2 - Linguagens de Programacao EL1
 *  Periodo: 2021.1
 *  Autor: Ricardo Santos Siqueira
 *  DRE: 118167558
 *  Arquivo: Aresta.hpp
 *  Descricao: Implementacao da classe Grafo(Graph).
 */

#include "Graph.hpp"

// Adiciona um vertice ao vetor do grafo
void Graph::createEdge(Vertice *x, Vertice *y, double weight)
{
  // Conferir se os vertices sao diferentes, ou seja, temos uma entrada valida
  if (x != y)
  {
    // Adicionando vertices unicos ao vetor vertices
    if (_vertices.empty())
    {
      _vertices.push_back(x);
      _vertices.push_back(y);
    }
    else
    {
      if (find(_vertices.begin(), _vertices.end(), x) == _vertices.end())
        _vertices.push_back(x);
      if (find(_vertices.begin(), _vertices.end(), y) == _vertices.end())
        _vertices.push_back(y);
    }

    // Cria a aresta e adiciona ao vetor de arestas(grafo)
    Edge edge(x, y, weight);
    _edges.push_back(&edge);
  }
  else
  {
    cout << "\nErro: Impossivel criar aresta com vertices iguais!\n<Aresta<Vertice<"
         << x
         << ">, Vertice<"
         << y
         << ">>>\n"
         << endl;
    exit(2);
  }
}

// Retorna o numero de vertices do grafo(comprimento do vetor grafo)
int Graph::countEdges() { return _edges.size(); }

// Retorna o numero de vertices do grafo
int Graph::countVertices() { return _vertices.size(); }

Vertice *Graph::_extractSmallestVertice()
{
  unsigned int length = _vertices.size();
  if (length == 0)
    return NULL;
  float smallestIndex = 0;
  Vertice *smallest = _vertices.at(0);
  for (unsigned int i; i < length; i++)
  {
    Vertice *current = _vertices.at(i);
    //! ERRO NESSA DISTANCIA
    if (current->getDistanceFromStart() < smallest->getDistanceFromStart())
    {
      smallest = current;
      smallestIndex = i;
    }
  }
  _vertices.erase(_vertices.begin() + smallestIndex);
  return smallest;
}

void Graph::dijkstraShortestPath()
{
}

//##############################################################################
Vertice *Graph::interfaceExtractSmallestVertice()
{
  return Graph::_extractSmallestVertice();
}
