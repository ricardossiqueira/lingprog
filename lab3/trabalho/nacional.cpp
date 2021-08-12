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

  for (unsigned short int i = 0; i < _estados.size(); i++)
  {
    Estadual estado = _estados.at(i);
    media += estado.mediaMovel(dias);
  }

  // Considerando que para esse programa apenas existe o pais Brasil, nao criei
  // um script para montar as tabelas dinamicamente, dado qualquer tamanho de
  // nome de pais(es), estado(s) e numero de obito(s)
  cout << " Pais    | Media Movel "
       << "\n"
       << "---------|-------------"
       << "\n"
       << " " << Nacional::getNome()
       << "  | "
       << media / _estados.size() << "\n"
       << endl;
}

void Nacional::printAltaEstabilidadeBaixaPorEstado()
{
  vector<Estadual> alta, estabilidade, baixa;

  // Calcula o a taxa por estado e adiciona o estado ao vetor correto
  for (unsigned short int i = 0; i < _estados.size(); i++)
  {
    Estadual estado = _estados.at(i);

    // Consideramos que mediaMovel(1) = media do dia atual e mediaMovel(2) =
    // media do dia anterior; tendo em vista que consideramos que os novos
    // obitos sempre sao adicionados no inicio do vector (prepend)
    float taxa = estado.mediaMovel(1) / estado.mediaMovel(2);

    if (taxa > 1.1)
      alta.push_back(estado);
    else if (taxa < 0.9)
      baixa.push_back(estado);
    else
      estabilidade.push_back(estado);
  }

  // Imprime as siglas dos estados em Alta
  cout << "Alta: ";
  for (unsigned short int i = 0; i < alta.size(); i++)
  {
    cout << alta.at(i).getNome() << " ";
  }
  cout << endl;

  // Imprime as siglas dos estados em Estabilidade
  cout << "Estabilidade: ";
  for (unsigned short int i = 0; i < estabilidade.size(); i++)
  {
    cout << estabilidade.at(i).getNome() << " ";
  }
  cout << endl;

  // Imprime as siglas dos estados em Baixa
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

  // Funcao para calculo da taxa
  for (unsigned short int i = 0; i < _estados.size(); i++)
  {
    Estadual estado = _estados.at(i);
    taxa += estado.mediaMovel(1) / estado.mediaMovel(2) / _estados.size();
  }

  cout << " " << Nacional::getNome() << " [" << taxa << " ] - ";
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
  // Inicia as variaveis com o primeiro estado do vector
  Estadual
      maiorAlta = _estados.at(0),
      maiorBaixa = _estados.at(0);

  // Arredonda a saida para 2 casas decimais
  cout.precision(4);

  // Percorre todos os estados cadastrados e encontra aqueles com maior alta e
  // maior baixa na media movel do dia atual
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

void Nacional::printTotalDeObitos()
{
  unsigned int totalObitosNacional = 0;

  // Head da tablela
  cout << "\n Estado | Obitos " << endl;

  for (unsigned short int i = 0; i < _estados.size(); i++)
  {
    Estadual estado = _estados.at(i);
    unsigned int totalObitosEstado = 0;
    vector<int> obitosEstado = estado.getObitos();

    // Somatorio do numero de obitos ao longo de todo registro
    for (unsigned short int j = 0; j < obitosEstado.size(); j++)
    {
      totalObitosEstado += obitosEstado.at(j);
    }

    totalObitosNacional += totalObitosEstado;

    // Body da tabela
    cout
        << " "
        << estado.getNome()
        << "     | "
        << totalObitosEstado
        << endl;
  }

  // Considerando que para esse programa apenas existe o pais Brasil, nao criei
  // um script para montar as tabelas dinamicamente, dado qualquer tamanho de
  // nome de pais(es), estado(s) e numero de obito(s)
  cout
      << "\n"
      << " Pais    | Obitos  "
      << "\n"
      << "---------|---------"
      << "\n"
      << " "
      << Nacional::getNome()
      << "  | "
      << totalObitosNacional
      << endl;
}