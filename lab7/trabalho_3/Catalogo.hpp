/*Exercicio Avaliado 3 - Linguagens de Programacao
 *Aluno: Ricardo Santos Siqueira
 *DRE: 118167558
 *Periodo: 2021.1
 *Arquivo: Catalogo.hpp
 *Descricao: Cabecalho da classe Catalogo
 */

#if !defined(CATALOGO_HPP)
#define CATALOGO_HPP
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include "Filme.hpp"

using namespace std;

class Catalogo
{
  // Friend
  friend ostream &operator<<(ostream &out, const Catalogo &catalogo);

private:
  vector<Filme> _filmes;

public:
  // Constructor
  Catalogo();
  // Destructor
  // ~Catalogo();

  // Getters
  vector<Filme> &getFilmes();

  // Operators
  void operator+=(const Filme &filme),
  operator-=(const Filme &filme);

  // Sobrecarga de operators
  Filme *operator()(const string);
  Filme *operator()(const string, const string);
  Filme *operator()(const string, const double);

  // Helper functions
  void sortedPut(vector<Filme> &filmes),
      readFromDB(ifstream &file),
      printBiggestScore() const;
};

#endif // CATALOGO_HPP
