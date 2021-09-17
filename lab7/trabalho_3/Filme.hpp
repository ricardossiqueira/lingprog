/*Exercicio Avaliado 3 - Linguagens de Programacao
 *Aluno: Ricardo Santos Siqueira
 *DRE: 118167558
 *Periodo: 2021.1
 *Arquivo: Filme.hpp
 *Descricao: Cabecalho da struct Filme
 */

#if !defined(FILME_HPP)
#define FILME_HPP
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

struct Filme
{
  // Friends
  friend ostream &operator<<(ostream &out, const Filme &filme);
  friend istream &operator>>(istream &in, Filme &filme);

public:
  // Constructor
  Filme(string nome = "", string produtora = "", double nota = 0.f);

  // Getters
  string getNome() const;
  string getProdutora() const;
  double getNota() const;

  // Setters
  void setProdutora(const string produtora);
  void setNota(const double nota);

  // Operators
  bool operator<(const Filme &) const;
  bool operator>(const Filme &) const;
  bool operator==(const Filme &) const;

private:
  string _nome, _produtora;
  double _nota;

  // Helper function
  string _lower(const string arg) const;
};

#endif // FILME_HPP
