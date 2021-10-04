/*Exercicio Avaliado 4 - Linguagens de Programacao
 *Aluno: Ricardo Santos Siqueira
 *DRE: 118167558
 *Periodo: 2021.1
 *Arquivo: PediatricPacient.hpp
*/

#include "PediatricPacient.hpp"

using namespace std;

PediatricPacient::PediatricPacient(
    const string name,
    const unsigned int age,
    const string gender,
    const string parents)
    : Pacient(name, age, gender)
{
  _parents = parents;
}

string PediatricPacient::getInfo() const
{
  return "Pais: " + _parents;
}