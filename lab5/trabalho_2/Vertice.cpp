/** Trabalho 2 - Linguagens de Programacao EL1
 *  Periodo: 2021.1
 *  Autor: Ricardo Santos Siqueira
 *  DRE: 118167558
 *  Arquivo: Vertice.hpp
 *  Descricao: Implementacao da classe Vertice.
 */

#include "Vertice.hpp"

Vertice::Vertice(string name) { _name = name; }

string Vertice::getName() { return _name; }