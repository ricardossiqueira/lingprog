#include "NotFoundException.hpp"

const char *NotFoundException::what() const throw()
{
  return "Erro: Paciente nao existe!";
}