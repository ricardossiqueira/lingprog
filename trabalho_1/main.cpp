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

  // Instanciando a classe Menu
  Menu menu = Menu();
  // Inicializando o menu interativo
  menu.run();

  // Menu finalizado

  // Chamada de sistma para o script python
  string command = "python python/interface.py " + menu.parseCommand() + " > " + logFile;

  system(command.c_str());

  // Lendo o arquivo log.txt
  FileResolver fileResolver(logFile);
  fileResolver.readFile();

  return 0;
}
