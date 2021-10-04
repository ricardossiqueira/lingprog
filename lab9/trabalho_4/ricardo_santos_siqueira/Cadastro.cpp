/*Exercicio Avaliado 4 - Linguagens de Programacao
 *Aluno: Ricardo Santos Siqueira
 *DRE: 118167558
 *Periodo: 2021.1
 *Arquivo: Cadastro.cpp
*/

#include "Cadastro.hpp"
#include "NotFoundException.hpp"
#include "AlreadyExistsException.hpp"

Register::Register(BinaryTree<Pacient> *root) : _tree(root){};

void Register::addPacient(Pacient *pacient)
{
  BinaryTree<Pacient> *ptr = (*_tree) += (pacient);
  if (ptr == NULL)
    throw AlreadyExistsException();
  else
    cout
        << "Paciente "
        << ptr->getSelf()->getName()
        << " adicionado com sucesso!"
        << endl;
}

void Register::findPacient(const string name)
{
  BinaryTree<Pacient> *ptr = _tree->operator()(name);
  if (ptr == NULL)
  {
    throw NotFoundException();
  }
  else
    cout
        << "Paciente encontrado!"
        << endl
        << "Nome: " << ptr->getSelf()->getName()
        << endl
        << "Idade: " << ptr->getSelf()->getAge()
        << endl
        << "Genero: " << ptr->getSelf()->getGender()
        << endl
        << ptr->getSelf()->getInfo()
        << endl;
}

void Register::listPacients() const
{
  cout
      << "Lista de pacientes"
      << endl
      << (*_tree);
}