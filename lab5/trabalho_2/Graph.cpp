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
  if (&x != &y)
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
    Edge *edge = new Edge(x, y, weight);
    _edges.push_back(edge);
  }
  else
  {
    cout << "\nErro: Impossivel criar aresta com vertices iguais!\n<Aresta<Vertice<"
         << &x
         << ">, Vertice<"
         << &y
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
    //* NAO TEM ERRO, TA RETORNANDO "A" PQ TO JOGANDO ESSE TREM PRA 0 POR SER A
    //* ORIGEM!!!
    if (current->getDistanceFromStart() < smallest->getDistanceFromStart())
    {
      smallest = current;
      smallestIndex = i;
    }
  }
  _vertices.erase(_vertices.begin() + smallestIndex);
  return smallest;
}

// Retorna true caso o vetor vertices contenha o vertice e false caso contrario
bool Graph::_contains(vector<Vertice *> &vertices, Vertice *vertice)
{
  // Funcao find() incluida pela lib "algorithm"
  if (find(vertices.begin(), vertices.end(), vertice) == vertices.end())
    return false;
  else
    return true;
}

// Retorna um vector de ponteiros de vertices adjacentes a um dado vertice que
// ainda nao foi removido do vetor _vertices
vector<Vertice *> *Graph::_adjacentVertices(Vertice *x)
{
  // Inicializando o ponteiro
  vector<Vertice *> *adjacentVertices = new vector<Vertice *>();

  for (unsigned int i = 0; i < _edges.size(); i++)
  {
    Edge *edge = _edges.at(i);
    Vertice *adjacent = NULL;

    // Se um dos vertices da aresta for igual ao vetor informado retornar o
    // adjacente a ele
    if (edge->getX() == x)
      adjacent = edge->getY();
    else if (edge->getY() == x)
      adjacent = edge->getX();

    // Se o vetor _adjacentes ainda nao possuir o vetor mapeado adicionar ao
    // vetor de vertices adjacentes
    if (adjacent && Graph::_contains(_vertices, adjacent))
      adjacentVertices->push_back(adjacent);
  }

  return adjacentVertices;
}

// Grau de um vertice no grafo (interface para Graph::_adjacentVertices())
int Graph::degree(Vertice *x)
{
  return Graph::_adjacentVertices(x)->size();
}

//##############################################################################
Vertice *Graph::interfaceExtractSmallestVertice()
{
  return Graph::_extractSmallestVertice();
}
