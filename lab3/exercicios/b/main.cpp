#include "agenda.h"

int main()
{

  Agenda agenda;
  string nome;

  cout << "Entre com os 3 nomes para serem adicionados:" << endl;

  for (int i = 0; i < 3; i++)
  {
    cout << "Entre com o " << i + 1 << "o nome:";
    cin >> nome;
    cout << endl;
    agenda.insereNome(nome);
  }

  cout << "Os nomes na agenda sao:" << endl;
  agenda.mostrarNomes();
  return 0;
}