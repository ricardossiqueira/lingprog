/** Trabalho 2 - Linguagens de Programacao EL1
 *  Periodo: 2021.1
 *  Autor: Ricardo Santos Siqueira
 *  DRE: 118167558
 *  Arquivo: filehelper.cpp
 *  Descricao: Implementacao da dupla de funcoes.
 */

#include "filehelper.hpp"

void readFile(string fileName,
              vector<array<string, 3>> *edgesMap,
              vector<string> *verticesMap)
{
  fstream fs;
  string x, y, weight;

  fs.open(fileName, fstream::in);

  if (!fs.is_open())
  {
    cout << "Arquivo nao existe!" << endl;
    return;
  }

  while (fs.good())
  {
    fs >> x >> y >> weight;
    edgesMap->push_back({x, y, weight});
    if (find(verticesMap->begin(), verticesMap->end(), x) == verticesMap->end())
      verticesMap->push_back(x);
    if (find(verticesMap->begin(), verticesMap->end(), y) == verticesMap->end())
      verticesMap->push_back(y);
  }

  fs.close();
}

void createGraph(Graph *graph, vector<Vertice *> *vertices)
{
  vector<array<string, 3>> edgesMap;
  vector<string> verticesMap;
  char *endptr;

  readFile("db.txt", &edgesMap, &verticesMap);

  for (unsigned int i = 0; i < verticesMap.size(); i++)
  {
    vertices->push_back(new Vertice(verticesMap.at(i)));
  }

  for (unsigned int i = 0; i < edgesMap.size(); i++)
  {
    array<string, 3> edgeTemplate = edgesMap.at(i);
    for (unsigned int j = 0; j < vertices->size(); j++)
    {
      Vertice *x = vertices->at(j);
      if (edgeTemplate[0] == x->getId())
      {
        for (unsigned int k = 0; k < vertices->size(); k++)
        {
          Vertice *y = vertices->at(k);
          if (edgeTemplate[1] == y->getId())
          {
            graph->createEdge(x, y, strtof(edgeTemplate[2].c_str(), &endptr));
          }
        }
      }
    }
  }
}