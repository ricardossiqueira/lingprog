#include "agenda.h"

int main()
{

  Agenda agenda;
  string nome, profissao;
  int idade;

  cout << "Entre com os 3 nomes para serem adicionados:" << endl;

  for (int i = 0; i < 3; i++)
  {
    cout << "Entre com o " << i + 1 << "o nome:";
    cin >> nome;
    cout << endl;
    cout << "Entre com a " << i + 1 << "a profissao:";
    cin >> profissao;
    cout << endl;
    cout << "Entre com a " << i + 1 << "a idade:";
    cin >> idade;
    cout << endl;

    agenda.insereCadastro(nome, profissao, idade);
  }

  cout << "Os cadastros na agenda sao:" << endl;
  agenda.mostrarCadastros();
  return 0;
}