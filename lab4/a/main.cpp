#include <iostream>
#include "agenda.hpp"

using namespace std;

int main()
{
  Agenda agenda;
  Contato contato("ricardo", 10, "padeiro");

  agenda.lerMudancas();

  agenda.inserirContato(contato);

  agenda.escreverMudancas();

  return 0;
}