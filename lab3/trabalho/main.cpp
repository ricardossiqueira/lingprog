/** Trabalho 1 - Linguagens de Programacao EL1
 * Periodo: 2021.1
 * Autor: Ricardo Santos Siqueira
 * DRE: 118167558
 * Arquivo: main.cpp
 * Descricao: Implementacao da funcao main que lida com os I/O's
 *            e chama as funcoes e classes necessarias.
 */

#include <iostream>
#include "helpers.hpp"

int main()
{
  // Opcao inicial padrao
  int option = -1;

  // Seed para a funcao rand utilizada para gerar os numeros de obitos
  srand(time(NULL));

  // Inicializa o pais Brasil com um vector de estados populado com numeros de
  // obitos aleatorios
  Nacional brasil = Nacional("Brasil", populateBrazilStates());

  do
  {
    cout << "\nSelecione uma das seguintes opcoes:\n\n"
         << "1 - Exibe a evolucao do numero de obitos no Brasil e estados.\n"
         << "2 - Exibe de forma agrupada os estados em alta, estabilidade e baixa.\n"
         << "3 - Exibe o mesmo dado do item 2, se em alta, baixa ou estabilidade, para o Brasil.\n"
         << "4 - Exibe estado com maior alta e maior baixa segundo a media movel do dia atual.\n"
         << "5 - Exibe os dados acumulados de numero de obitos no Brasil e nos estados individualmente.\n"
         << "0 - Sair\n"
         << endl;

    cout << "Opcao: ";
    cin >> option;
    cout << "\n"
         << endl;

    switch (option)
    {
    case 0:
      cout << "Saindo do programa..." << endl;
      break;

    case 1:
      brasil.printMediaMovelNacional();
      brasil.printMediaMovelPorEstado();
      break;

    default:
      cout << "Opcao invalida!" << endl;
      break;
    }
  } while (option != 0);

  return 0;
}