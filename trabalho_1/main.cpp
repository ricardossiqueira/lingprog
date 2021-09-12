/*Trabalho - Linguagens de Programacao
 *Aluno: Ricardo Santos Siqueira
 *DRE: 118167558
 *Periodo: 2021.1
 *Arquivo: main.cpp
 *Descricao: Funcao principal do programa, chama o menu e controla o fluxo
 */

#include <iostream>
#include <string>
#include "Menu.hpp"
#include "FileResolver.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  const string logFile = "tmp.log";

  Menu menu = Menu();
  menu.run();
  string command = "python python/interface.py " + menu.parseCommand() + " > " + logFile;

  cout << command << endl;

  system(command.c_str());

  FileResolver fileResolver = FileResolver(logFile);
  fileResolver.readFile();

  return 0;
}
