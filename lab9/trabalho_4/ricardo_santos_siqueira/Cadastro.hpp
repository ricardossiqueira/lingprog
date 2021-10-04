/*Exercicio Avaliado 4 - Linguagens de Programacao
 *Aluno: Ricardo Santos Siqueira
 *DRE: 118167558
 *Periodo: 2021.1
 *Arquivo: Cadastro.hpp
*/

#if !defined(CADASTRO_HPP)
#define CADASTRO_HPP

#include "BinaryTree.hpp"
#include "Paciente.hpp"
#include <exception>
#include <string>

using namespace std;

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
