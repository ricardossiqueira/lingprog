#include "agenda.h"

Agenda::Agenda(int n)
{
  _tamanhoMax = 3;
}

void Agenda::insereNome(string nome)
{
  if ((int)_nomes.size() > _tamanhoMax)
  {
    cout << "Agenda cheia!" << endl;
  }
  else
  {

    _nomes.push_back(_verificaNome(nome));
  }
}

void Agenda::mostrarNomes()
{
  for (int i = 0; i < _tamanhoMax; i++)
  {
    cout << i + 1 << "o: " << _nomes.at(i) << endl;
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