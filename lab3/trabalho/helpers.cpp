#include "helpers.h"

// Retorna um vetor de inteiros aleatorios utilizado para
// popular os obitos de cada estado.
vector<int> populateRandomIntVector()
{
  vector<int> v;

  for (unsigned short int i = 0; i < LEN_RANDOM_INT_VECTOR; i++)
  {
    v.push_back(rand() % 100);
  }

  return v;
}

vector<Estadual> populateBrazilStates()
{
  vector<Estadual> estados;
  vector<string> siglas{
      "AC",
      "AL",
      "AP",
      "AM",
      "BA",
      "CE",
      "DF",
      "ES",
      "GO",
      "MA",
      "MS",
      "MT",
      "MG",
      "PA",
      "PB",
      "PR",
      "PE",
      "PI",
      "RJ",
      "RN",
      "RS",
      "RO",
      "RR",
      "SC",
      "SP",
      "SE",
      "TO"};

  for (unsigned short int i = 0; i < 27; i++)
  {
    Estadual estado = Estadual(siglas.at(i), populateRandomIntVector());
    estados.push_back(estado);
  }
  return estados;
}