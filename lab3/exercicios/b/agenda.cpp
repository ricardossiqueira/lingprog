#include "agenda.h"

void Agenda::insereNome(string nome)
{
  if (_nomesInseridos > _tamanhoMax)
  {
    cout << "Agenda cheia!" << endl;
  }
  else
  {

    _nomes[_nomesInseridos++] = _verificaNome(nome);
  }
}

void Agenda::mostrarNomes()
{
  for (int i = 0; i < _tamanhoMax; i++)
  {
    cout << i + 1 << "o: " << _nomes[i] << endl;
  }
}

string Agenda::_verificaNome(string nome)
{
  if (nome.length() > 10)
  {
    cout << "Nome maior que 10 caracteres, truncando..." << endl;
    return nome.substr(0, 10);
  }
  return nome;
}