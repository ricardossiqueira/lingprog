/*Exercicio Avaliado 4 - Linguagens de Programacao
 *Aluno: Ricardo Santos Siqueira
 *DRE: 118167558
 *Periodo: 2021.1
 *Arquivo: Cadastro.cpp
 *Descricao: foo
 */

#include "Cadastro.hpp"
#include "NotFoundException.hpp"
#include "AlreadyExistsException.hpp"

Register::Register(BinaryTree<Pacient> *root) : _tree(root){};

void Register::addPacient(Pacient *pacient)
{
  BinaryTree<Pacient> *ptr = (*_tree) += (pacient);
  if (ptr == nullptr)
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
  BinaryTree<Pacient> *ptr = (*_tree)(name);
  if (ptr == nullptr)
    throw NotFoundException();
  else
    cout
        << "Paciente encontrado!"
        << endl
        << endl
        << "Nome: " << ptr->getSelf()->getName()
        << endl
        << "Idade: " << ptr->getSelf()->getAge()
        << endl
        << "Genero: " << ptr->getSelf()->getGender()
        << endl;
}

void Register::listPacients() const
{
  cout
      << "Lista de pacientes"
      << endl
      << (*_tree);
}