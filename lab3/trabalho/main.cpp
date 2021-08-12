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
  short unsigned int option = 0;

  // Seed para a funcao rand utilizada para gerar os numeros de obitos
  srand(time(NULL));

  // Inicializa o pais Brasil com um vector de estados populado com numeros de
  // obitos aleatorios
  Nacional brasil = Nacional("Brasil", populateBrazilStates());

  do
  {
    cout << "\n Selecione uma das seguintes opcoes:\n\n"
         << " 1 - Exibe a evolucao do numero de obitos no Brasil e estados.\n"
         << " 2 - Exibe de forma agrupada os estados em alta, estabilidade e baixa.\n"
         << " 3 - Exibe o mesmo dado do item 2, se em alta, baixa ou estabilidade, para o Brasil.\n"
         << " 4 - Exibe estado com maior alta e maior baixa segundo a media movel do dia atual.\n"
         << " 5 - Exibe os dados acumulados de numero de obitos no Brasil e nos estados individualmente.\n"
         << " 6 - Sair\n"
         << endl;

    cout << "Opcao: ";
    cin >> option;
    cout << endl;

    switch (option)
    {
    case 0:
      cout << "Entrada inesperada! Saindo do programa...\n"
           << endl;
      exit(1);

    case 1:
      brasil.printMediaMovelNacional();
      brasil.printMediaMovelPorEstado();
      break;

    case 2:
      brasil.printAltaEstabilidadeBaixaPorEstado();
      break;

    case 3:
      brasil.printAltaEstabilidadeBaixaNacional();
      break;

    case 4:
      brasil.printMaiorAltaEMaiorBaixa();
      break;

    case 5:
      brasil.printTotalDeObitos();
      break;

    case 6:
      cout << "Saindo do programa..." << endl;
      break;

    default:
      break;
    }
  } while (option != 6);

  return 0;
}