/** Trabalho 1 - Linguagens de Programacao EL1
 * Periodo: 2021.1
 * Autor: Ricardo Santos Siqueira
 * DRE: 118167558
 * Arquivo: nacional.cpp
 * Descricao: Implementacao da classe Nacional responsavel por configurar um
 *            novo pais e lidar com as respectivas funcoes.
 */

#include "nacional.hpp"

// Constructor
Nacional::Nacional(string nome, vector<Estadual> estados)
{
  _nome = nome;
  _estados = estados;
}

// Getters
string Nacional::getNome() { return _nome; }

void Nacional::printMediaMovelPorEstado(short unsigned int dias)
{
  // Arredonda a saida para 2 casas decimais
  cout.precision(4);
  cout << " Estados | Media Movel " << endl;
  cout << "---------|-------------" << endl;
  for (unsigned short int i = 0; i < _estados.size(); i++)
  {
    Estadual estado = _estados.at(i);
    cout << " " << estado.getNome();
    // \t = 4 espacos
    cout << "\t | " << estado.mediaMovel(dias);
    cout << endl;
  }
}

void Nacional::printMediaMovelNacional(short unsigned int dias)
{
  float media = 0.0;

  // Arredonda a saida para 2 casas decimais
  cout.precision(4);
  cout << " Pais    | Media Movel " << endl;
  cout << "---------|-------------" << endl;
  cout << " " << getNome();
  cout << "  | ";

  for (unsigned short int i = 0; i < _estados.size(); i++)
  {
    Estadual estado = _estados.at(i);
    media += estado.mediaMovel(dias);
  }

  cout << media / _estados.size() << "\n"
       << endl;
}

void Nacional::printAltaEstabilidadeBaixaPorEstado()
{
  vector<Estadual> alta, estabilidade, baixa;

  for (unsigned short int i = 0; i < _estados.size(); i++)
  {
    Estadual estado = _estados.at(i);
    float taxa = estado.mediaMovel(1) / estado.mediaMovel(2);
    if (taxa > 1.1)
      alta.push_back(estado);
    else if (taxa < 0.9)
      baixa.push_back(estado);
    else
      estabilidade.push_back(estado);
  }

  cout << "Alta: ";
  for (unsigned short int i = 0; i < alta.size(); i++)
  {
    cout << alta.at(i).getNome() << " ";
  }
  cout << endl;

  cout << "Estabilidade: ";
  for (unsigned short int i = 0; i < estabilidade.size(); i++)
  {
    cout << estabilidade.at(i).getNome() << " ";
  }
  cout << endl;

  cout << "Baixa: ";
  for (unsigned short int i = 0; i < baixa.size(); i++)
  {
    cout << baixa.at(i).getNome() << " ";
  }
  cout << endl;
}

void Nacional::printAltaEstabilidadeBaixaNacional()
{
  float taxa;

  // Arredonda a saida para 2 casas decimais
  cout.precision(4);

  for (unsigned short int i = 0; i < _estados.size(); i++)
  {
    Estadual estado = _estados.at(i);
    taxa += estado.mediaMovel(1) / estado.mediaMovel(2) / _estados.size();
  }

  cout << " " << getNome() << " [" << taxa << " ] - ";
  if (taxa > 1.1)
    cout << "Alta";
  else if (taxa < 0.9)
    cout << "Baixa";
  else
    cout << "Estavel";

  cout << endl;
}

void Nacional::printMaiorAltaEMaiorBaixa()
{
  Estadual maiorAlta = _estados.at(1), maiorBaixa = _estados.at(1);

  // Arredonda a saida para 2 casas decimais
  cout.precision(4);

  for (unsigned short int i = 0; i < _estados.size(); i++)
  {
    Estadual estado = _estados.at(i);
    if (maiorAlta.mediaMovel(1) < estado.mediaMovel(1))
      maiorAlta = estado;
    if (maiorBaixa.mediaMovel(1) > estado.mediaMovel(1))
      maiorAlta = estado;
  }

  cout << " Estado com maior alta: "
       << maiorAlta.getNome()
       << " [ "
       << maiorAlta.mediaMovel(1)
       << "] "
       << endl;

  cout << " Estado com maior baixa: "
       << maiorBaixa.getNome()
       << " [ "
       << maiorBaixa.mediaMovel(1)
       << "] "
       << endl;
}