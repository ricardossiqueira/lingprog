/*Exercicio Avaliado 4 - Linguagens de Programacao
 *Aluno: Ricardo Santos Siqueira
 *DRE: 118167558
 *Periodo: 2021.1
 *Arquivo: PediatricPacient.hpp
 *Descricao: foo
 */

#if !defined(PEDIATRICPACIENT_HPP)
#define PEDIATRICPACIENT_HPP

#include "Paciente.hpp"
#include <ostream>
#include <string>

using namespace std;

class PediatricPacient : public Pacient
{
private:
  string _parents;

public:
  PediatricPacient(string name, unsigned int age, string gender, string parents);
  virtual string getInfo() const;
};

#endif // PEDIATRICPACIENT_HPP
