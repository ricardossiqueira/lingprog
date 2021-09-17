/*Exercicio Avaliado 3 - Linguagens de Programacao
 *Aluno: Ricardo Santos Siqueira
 *DRE: 118167558
 *Periodo: 2021.1
 *Arquivo: helperFunctions.hpp
 *Descricao: Arquivo cabecalho. Conjunto de funcoes auxiliares para validacao do
 *           menu da aplicacao.
 */

#if !defined(HELPERFUNCTIONS_HPP)
#define HELPERFUNCTIONS_HPP
#include <iostream>
#include <limits>

using namespace std;

int requireValidNumber();
bool validInputRange(int num, int min, int max);

#endif // HELPERFUNCTIONS_HPP
