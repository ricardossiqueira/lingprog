/*Exercicio Avaliado 4 - Linguagens de Programacao
 *Aluno: Ricardo Santos Siqueira
 *DRE: 118167558
 *Periodo: 2021.1
 *Arquivo: CardioPacient.hpp
 *Descricao: foo
 */

#if !defined(CARDIOPACIENT_HPP)
#define CARDIOPACIENT_HPP

#include "Paciente.hpp"
#include <ostream>
#include <string>

using namespace std;

class CardioPacient : public Pacient
{
private:
  string _bloodType;

public:
  CardioPacient(string name, unsigned int age, string gender, string bloodType);
  virtual string getInfo() const;
};

#endif // CARDIOPACIENT_HPP
