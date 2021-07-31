#include "agenda.h"

void Agenda::insereCadastro(string nome, string profissao, int idade)
{
  if (_cadastrosAdicionados > _tamanhoMax)
  {
    cout << "Agenda cheia!" << endl;
  }
  else
  {
    Cadastro cadastro;
    cadastro.setNome(nome);
    cadastro.setProfissao(profissao);
    cadastro.setIdade(idade);
    _cadastros[_cadastrosAdicionados++] = cadastro;
  }
}

void Agenda::mostrarCadastros()
{
  for (int i = 0; i < _tamanhoMax; i++)
  {
    cout << i + 1 << "o: " << _cadastros[i].getNome() << ", " << _cadastros[i].getIdade() << ", " << _cadastros[i].getProfissao() << endl;
  }
}
