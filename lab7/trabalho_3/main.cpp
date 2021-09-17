/*Exercicio Avaliado 3 - Linguagens de Programacao
 *Aluno: Ricardo Santos Siqueira
 *DRE: 118167558
 *Periodo: 2021.1
 *Arquivo: main.cpp
 *Descricao: Implementacao da funcao principal
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "helperFunctions.hpp"
#include "Filme.hpp"
#include "Catalogo.hpp"

using namespace std;

// Funcoes referentes ao menu da aplicacao
int handleSelectFromMenu()
{

  int option;

  cout
      << "Opcoes:"
      << endl
      << "1 - Adicionar filme."
      << endl
      << "2 - Remover filme."
      << endl
      << "3 - Buscar filme."
      << endl
      << "4 - Editar produtora."
      << endl
      << "5 - Editar nota."
      << endl
      << "6 - Listar filmes."
      << endl
      << "7 - Exibir filme com maior nota."
      << endl
      << "8 - Salvar e sair."
      << endl;

  cout << ">>> ";

  do
    option = requireValidNumber();
  while (validInputRange(option, 1, 8));

  return option;
}

// main
int main(int argc, char const *argv[])
{
  enum options
  {
    AdicionarFilme = 1,
    RemoverFilme,
    BuscarFilme,
    EditarProdutora,
    EditarNota,
    ListarFilmes,
    ExibirFilmeComMaiorNota,
    Sair
  };

  int currArg = 1;
  int option;
  string fileName = "db.txt";
  Catalogo catalog;
  ifstream file(fileName);
  if (file.good())
  {
    catalog.readFromDB(file);
    cout << "Arquivo db.txt lido com sucesso." << endl;
    file.close();
  }
  else
  {
    cout << "Arquivo nao existe" << endl;
    ofstream file(fileName);
    file << catalog;
    file.close();
  }

  do
  {
    option = (argc > currArg) ? stoi(argv[currArg]) : handleSelectFromMenu();

    switch (option)
    {
    case AdicionarFilme:
    {
      vector<Filme> tmpFilmes;
      Filme tmpFilme;
      cout
          << "Entre com os dados do filme"
          << endl
          << "Nome [Enter]"
          << endl
          << "Produtora [Enter]"
          << endl
          << "Nota [Enter]"
          << endl;
      cin >> tmpFilme;
      tmpFilmes.push_back(tmpFilme);
      catalog.sortedPut(tmpFilmes);
      break;
    }

    case RemoverFilme:
    {
      string nome;
      cout << "Entre com o nome do filme a ser removido: ";
      cin >> nome;
      catalog -= nome;
      break;
    }

    case BuscarFilme:
    {
      string nome;
      Filme *ptrFilme = nullptr;
      cout << "Ebtre com o nome do filme a ser buscado: ";
      cin >> nome;
      ptrFilme = catalog(nome);
      if (ptrFilme == nullptr)
        cout << "Filme nao encontrado." << endl;
      else
        cout << *ptrFilme << endl;
      break;
    }

    case EditarProdutora:
    {
      string nome;
      string produtora;
      cout << "Entre com o nome do filme a ser editado: ";
      cin >> nome;
      cout << "Entre com o novo nome da produtora: ";
      cin >> produtora;
      catalog(nome, produtora);
      break;
    }

    case EditarNota:
    {
      string nome;
      string strNota;
      double nota;
      cout << "Entre com o nome do filme a ser editado: ";
      cin >> nome;
      cout << "Entre com a nova nota: ";
      cin >> strNota;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      nota = stod(strNota);
      catalog(nome, nota);
      break;
    }

    case ListarFilmes:
      cout << catalog;
      break;

    case ExibirFilmeComMaiorNota:
      catalog.printBiggestScore();
      break;

    case Sair:
    {
      ofstream file(fileName);
      file << catalog;
      file.close();
      cout << "Dados salvos em " << fileName << "." << endl;
      break;
    }

    default: // Esse bloco nunca deve executar
      break;
    }

    if (currArg <= argc)
      option = stoi(argv[currArg++]);

  } while (option != Sair);

  return 0;
}
