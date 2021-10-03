/*Exercicio Avaliado 4 - Linguagens de Programacao
 *Aluno: Ricardo Santos Siqueira
 *DRE: 118167558
 *Periodo: 2021.1
 *Arquivo: Cadastro.hpp
 *Descricao: foo
 */

#if !defined(CADASTRO_HPP)
#define CADASTRO_HPP

#include "BinaryTree.hpp"
#include "Paciente.hpp"
#include <exception>

using namespace std;

class PacientAlreadyExists : public exception
{
  virtual const char *what() const throw()
  {
    return "Error: Paciente ja cadastrado!";
  }
};

class PacientNotFound : public exception
{
  virtual const char *what() const throw()
  {
    return "Error: Paciente nao encontrado!";
  }
};

class Register
{
private:
  BinaryTree<Pacient> *_tree;

public:
  Register(BinaryTree<Pacient> *root);

  void addPacient(Pacient *pacient);
  void findPacient(const string pacient);
  void listPacients() const;
  BinaryTree<Pacient> *getRoot();
};

#endif // CADASTRO_HPP
