/** Trabalho 2 - Linguagens de Programacao EL1
 *  Periodo: 2021.1
 *  Autor: Ricardo Santos Siqueira
 *  DRE: 118167558
 *  Arquivo: Vertice.hpp
 *  Descricao: Arquivo cabecalho da classe Vertice.
 */

#include <string>

using namespace std;

#ifndef VERTICE_HPP
#define VERTICE_HPP

class Vertice
{
private:
  // Nome do vertice
  string _name;

public:
  // Constructor vertice
  Vertice(string name);

  // Getter nome do vertice
  string getName();
};

#endif