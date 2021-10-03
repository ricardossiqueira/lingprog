#include "AlreadyExistsException.hpp"

const char *AlreadyExistsException::what() const throw()
{
  return "Erro: Paciente ja cadastrado!";
}