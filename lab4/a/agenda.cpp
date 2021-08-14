#include "agenda.hpp"

void Agenda::inserirContato(Contato contato)
{
  if (_contatos.size() >= _maxLenAgenda)
    cout << "Agenda cheia!" << endl;
  else if (_contatos.size() != 0 && _encontrarContato(contato) == -1)
    cout << "Contato ja existe!" << endl;
  else
    _contatos.push_back(contato);
}

// returns -1 if Contato exists and index otherwise
int Agenda::_encontrarContato(Contato contato)
{
  for (long unsigned int i = 0; i < _contatos.size(); i++)
    if (_contatos.at(i).getNome().compare(contato.getNome()))
      return i;

  return -1;
}

void Agenda::removerContato(unsigned int index)
{
  _contatos.erase(_contatos.begin() + index);
}

void Agenda::escreverMudancas()
{
  _file.open("db.txt", fstream::out);

  for (long unsigned int i = 0; i < _contatos.size(); i++)
    _file
        << _contatos.at(i).getNome()
        << " "
        << _contatos.at(i).getIdade()
        << " "
        << _contatos.at(i).getProfissao()
        << endl;

  _file.close();
}

void Agenda::lerMudancas()
{
  string nome, profissao;
  unsigned short int idade;

  _file.open("db.txt", fstream::in);

  if (!_file.is_open())
  {
    cout << "Arquivo nao existe!" << endl;
    return;
  }

  while (_file.good())
  {
    nome = "";
    _file >> nome >> idade >> profissao;
    // ensure only new contacts recived via read will execute
    if (nome != "")
      inserirContato(Contato(nome, idade, profissao));
  }

  _file.close();
}