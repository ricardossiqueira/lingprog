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
    _cadastros.push_back(cadastro);
    _cadastrosAdicionados++;
  }
}

void Agenda::mostrarCadastros()
{
  for (int i = 0; i < _tamanhoMax; i++)
  {
    Cadastro cadastro = _cadastros.at(i);
    cout << i + 1 << "o: " << cadastro.getNome() << ", " << cadastro.getIdade() << ", " << cadastro.getProfissao() << endl;
  }
}
