/*Exercicio Avaliado 4 - Linguagens de Programacao
 *Aluno: Ricardo Santos Siqueira
 *DRE: 118167558
 *Periodo: 2021.1
 *Arquivo: AlreadyExistsException.cpp
 *Descricao: foo
 */

#include "AlreadyExistsException.hpp"

const char *AlreadyExistsException::what() const throw()
{
  return "Erro: Paciente ja cadastrado!";
}