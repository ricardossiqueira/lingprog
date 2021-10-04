/*Exercicio Avaliado 4 - Linguagens de Programacao
 *Aluno: Ricardo Santos Siqueira
 *DRE: 118167558
 *Periodo: 2021.1
 *Arquivo: NotFoundException.hpp
*/

#if !defined(NOTFOUNDEXCEPTION_HPP)
#define NOTFOUNDEXCEPTION_HPP

#include <iostream>
#include <stdexcept>

class NotFoundException
{
public:
  virtual const char *what() const throw();
};

#endif // NOTFOUNDEXCEPTION_HPP
