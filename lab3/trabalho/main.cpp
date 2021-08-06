#include <iostream>
#include "helpers.h"

int main()
{
  // int option = -1;
  srand(time(NULL));

  Nacional brasil = Nacional("Brasil", populateBrazilStates());

  cout << brasil.getNome() << endl;
  vector<Estadual> estadosBrasileiros = brasil.getEstados();

  for (long unsigned int i = 0; i < estadosBrasileiros.size(); i++)
  {
    Estadual estado = estadosBrasileiros.at(i);
    vector<int> obitos = estado.getObitos();
    cout << estado.getNome();
    for (short unsigned int j = 0; j < LEN_RANDOM_INT_VECTOR; j++)
    {
      cout << " " << obitos.at(j);
    }
    cout << endl;
  }

  // do
  // {

  //   cout << "\nSelecione uma das seguintes opcoes:\n\n"
  //        << "1 - Exibe a evolucao do numero de obitos no Brasil e estados.\n"
  //        << "2 - Exibe de forma agrupada os estados em alta, estabilidade e baixa.\n"
  //        << "3 - Exibe o mesmo dado do item 2, se em alta, baixa ou estabilidade, para o Brasil.\n"
  //        << "4 - Exibe estado com maior alta e maior baixa segundo a media movel do dia atual.\n"
  //        << "5 - Exibe os dados acumulados de numero de obitos no Brasil e nos estados individualmente.\n"
  //        << "0 - Sair" << endl;

  //   cout << "\nOpcao: ";
  //   cin >> option;

  //   switch (option)
  //   {
  //   case 0:
  //     break;

  //   default:
  //     cout << "Opcao invalida!" << endl;
  //     break;
  //   }
  // } while (option != 0);

  return 0;
}