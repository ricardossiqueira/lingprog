/*Exercicio Avaliado 4 - Linguagens de Programacao
 *Aluno: Ricardo Santos Siqueira
 *DRE: 118167558
 *Periodo: 2021.1
 *Arquivo: Paciente.cpp
*/

#include "Paciente.hpp"

// Friend
ostream &operator<<(ostream &out, const Pacient &pacient)
{
  return out
         << "Nome: " << pacient.getName() << endl
         << "Idade: " << pacient.getAge() << endl
         << "Genero: " << pacient.getGender() << endl
         << pacient.getInfo() << endl;
}

// Constructor
Pacient::Pacient(const string name, const unsigned int age, const string gender)
{
  _name = name;
  _age = age;
  _gender = gender;
}

// Getters
string Pacient::getName() const { return _name; }
unsigned int Pacient::getAge() const { return _age; }
string Pacient::getGender() const { return _gender; }

// Setters
void Pacient::setName(const string name) { _name = name; }
void Pacient::setAge(const unsigned int age) { _age = age; }
void Pacient::setGender(const string gender) { _gender = gender; }

// Operators
bool Pacient::operator<(const Pacient &pacient)
{
  return _name < pacient.getName() ? true : false;
}

bool Pacient::operator>(const Pacient &pacient)
{
  return _name > pacient.getName() ? true : false;
}

bool Pacient::operator==(const Pacient &pacient)
{
  return _name == pacient.getName() ? true : false;
}
