/*Exercicio Avaliado 4 - Linguagens de Programacao
 *Aluno: Ricardo Santos Siqueira
 *DRE: 118167558
 *Periodo: 2021.1
 *Arquivo: helperFunctions.cpp
 *Descricao: Implementacao do conjunto de funcoes auxiliares para validacao de 
 *           inputs.*/

#include "helperFunctions.hpp"

int requireValidNumber()
{
  int arg;
  while (!(cin >> arg))
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cerr << "Erro: Entrada invalida" << endl;
    cout << ">>> ";
  }
  return arg;
}

bool validInputRange(int num, int min, int max)
{
  if (num < min || num > max)
  {
    cerr
        << "Erro: Entre com um valor valido ["
        << min
        << ".."
        << max
        << "]"
        << endl;

    cout << ">>> ";

    return true;
  }
  return false;
}
