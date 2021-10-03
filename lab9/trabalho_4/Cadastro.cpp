/*Exercicio Avaliado 4 - Linguagens de Programacao
 *Aluno: Ricardo Santos Siqueira
 *DRE: 118167558
 *Periodo: 2021.1
 *Arquivo: Cadastro.cpp
 *Descricao: foo
 */

#include "Cadastro.hpp"

Register::Register(BinaryTree<Pacient> *root) : _tree(root){};

void Register::addPacient(Pacient *pacient)
{
  BinaryTree<Pacient> *ptr = _tree->operator+=(pacient);
  if (ptr == nullptr)
    throw PacientAlreadyExists();
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
  if (ptr == nullptr)
    throw PacientNotFound();
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