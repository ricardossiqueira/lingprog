/*Exercicio Avaliado 4 - Linguagens de Programacao
 *Aluno: Ricardo Santos Siqueira
 *DRE: 118167558
 *Periodo: 2021.1
 *Arquivo: main.cpp
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include "Cadastro.hpp"
#include "Paciente.hpp"
#include "BinaryTree.hpp"
#include "helperFunctions.hpp"
#include "CardioPacient.hpp"
#include "PediatricPacient.hpp"
#include "AlreadyExistsException.hpp"
#include "NotFoundException.hpp"

using namespace std;

int handleSelectFromMenu()
{

  int option;

  cout
      << "Opcoes:"
      << endl
      << "1 - Adicionar paciente."
      << endl
      << "2 - Buscar paciente."
      << endl
      << "3 - Imprimir pacientes."
      << endl
      << "4 - Sair."
      << endl
      << ">>> ";

  do
    option = requireValidNumber();
  while (validInputRange(option, 1, 4));

  return option;
}

int main(int argc, char const *argv[])
{
  enum MainMenu
  {
    AdicionarPaciente = 1,
    BuscarPaciente,
    ImprimirPacientes,
    Sair
  };

  enum SubMenu
  {
    Pediatria = Sair + 1,
    Cardiologia
  };

  int currArg = 1;
  int option;

  BinaryTree<Pacient> *root = new BinaryTree<Pacient>();
  Register reg(root); // register e uma keyword do C++

  do
  {
    option = (argc > currArg) ? stoi(argv[currArg]) : handleSelectFromMenu();

    switch (option)
    {
    case AdicionarPaciente:
    {
      string name, gender;
      unsigned int age;
      int pacientType;
      Pacient *ptr = NULL;

      cout << "Nome do paciente:" << endl
           << ">>> ";
      cin >> name;

      cout << "Idade do paciente:" << endl
           << ">>> ";
      do
      {
        age = requireValidNumber();
      } while (validInputRange(age, 1, 150));

      cout << "Genero do paciente:" << endl
           << ">>> ";
      cin >> gender;

      cout << "Especialidade desejada:" << endl
           << "1- Pediatria." << endl
           << "2- Cardiologia." << endl
           << ">>> ";

      do
      {
        pacientType = requireValidNumber() + Sair;
      } while (validInputRange(pacientType, Pediatria, Cardiologia));

      if (pacientType == Pediatria)
      {
        string parents;
        cout << "Nome dos pais do paciente:" << endl
             << ">>> ";
        cin >> parents;

        ptr = new PediatricPacient(name, age, gender, parents);
      }
      else
      {
        string bloodType;
        cout << "Tipo sanguineo do paciente:" << endl
             << ">>> ";
        cin >> bloodType;

        ptr = new CardioPacient(name, age, gender, bloodType);
      }

      try
      {
        reg.addPacient(ptr);
      }
      catch (AlreadyExistsException &e)
      {
        cerr << e.what() << endl;
      }

      break;
    }

    case BuscarPaciente:
    {
      string name;
      cout << "Entre com o nome do paciente a ser buscado: " << endl
           << ">>> ";
      cin >> name;

      try
      {
        reg.findPacient(name);
      }
      catch (NotFoundException &e)
      {
        cerr << e.what() << endl;
      }
    }

    case ImprimirPacientes:
      reg.listPacients();
      break;

    default:
      break;
    }

    if (currArg <= argc)
      option = stoi(argv[currArg++]);

  } while (option != Sair);

  return 0;
}
