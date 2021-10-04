/*Exercicio Avaliado 4 - Linguagens de Programacao
 *Aluno: Ricardo Santos Siqueira
 *DRE: 118167558
 *Periodo: 2021.1
 *Arquivo: AlreadyExistsException.hpp
*/

#if !defined(ALREADYEXISTSEXCEPTION_HPP)
#define ALREADYEXISTSEXCEPTION_HPP

#include <iostream>
#include <stdexcept>

class AlreadyExistsException
{
public:
  virtual const char *what() const throw();
};

#endif // ALREADYEXISTSEXCEPTION_HPP
