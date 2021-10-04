/*Exercicio Avaliado 4 - Linguagens de Programacao
 *Aluno: Ricardo Santos Siqueira
 *DRE: 118167558
 *Periodo: 2021.1
 *Arquivo: NotFoundException.cpp
*/

#include "NotFoundException.hpp"

const char *NotFoundException::what() const throw()
{
  return "Erro: Paciente nao existe!";
}