/*Exercicio Avaliado 4 - Linguagens de Programacao
 *Aluno: Ricardo Santos Siqueira
 *DRE: 118167558
 *Periodo: 2021.1
 *Arquivo: CardioPacient.hpp
*/

#include "CardioPacient.hpp"

using namespace std;

CardioPacient::CardioPacient(
    const string name,
    const unsigned int age,
    const string gender,
    const string bloodType)
    : Pacient(name, age, gender)
{
  _bloodType = bloodType;
}

string CardioPacient::getInfo() const
{
  return "Tipo sanguineo: " + _bloodType;
}