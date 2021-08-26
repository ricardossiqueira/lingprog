#include <string>
#include <fstream>
#include <iostream>
#include "Graph.hpp"

#ifndef FILEHELPER_HPP
#define FILEHELPER_HPP

// Le o arquivo com os parametros para a criacao do grafo. Nao possui retorno
// explicito, mas popula os vetores edgesMap e verticesMap que contem os dados
// brutos lidos do arquivo.
void readFile(string fileName,
              vector<array<string, 3>> *edgesMap,
              vector<string> *verticesMap);

// Cria o grafo com base no retorno da funcao readFile(). Nao possui retorno
// explicito, mas popula a instancia da classe Graph e o vetor vertices usados
// em main() nas funcoes relativas ao grafo
void createGraph(Graph *graph, vector<Vertice *> *vertices);

#endif