/*Exercicio Avaliado 4 - Linguagens de Programacao
 *Aluno: Ricardo Santos Siqueira
 *DRE: 118167558
 *Periodo: 2021.1
 *Arquivo: Paciente.hpp
 *Descricao: foo
 */

#if !defined(PACIENTE_HPP)
#define PACIENTE_HPP

#include <string>
#include <ostream>

using namespace std;

class Pacient
{
  // Friends
  friend ostream &operator<<(ostream &out, const Pacient &pacient);

private:
  string _name, _gender;
  unsigned int _age;

public:
  // Constructor
  Pacient(const string name, const unsigned int age, const string gender);

  // Getters
  string getName() const, getGender() const;
  unsigned int getAge() const;

  // Setters
  void setName(const string name),
      setAge(const unsigned int age),
      setGender(const string gender);

  // Sem corpo, puramente virtual
  virtual string getInfo() const = 0;

  // Operators
  bool operator<(const Pacient &pacient),
  operator>(const Pacient &pacient),
  operator==(const Pacient &pacient);
};

#endif // PACIENTE_HPP
