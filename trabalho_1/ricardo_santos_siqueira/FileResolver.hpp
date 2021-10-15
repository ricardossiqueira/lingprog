/*Trabalho - Linguagens de Programacao
 *Aluno: Ricardo Santos Siqueira
 *DRE: 118167558
 *Periodo: 2021.1
 *Arquivo: FileResolver.hpp
 *Descricao: Cabecalho da classe FileResolver responsavel por ler o arquivo 
 *           log.tmp que armazena os nomes das imagens geradas.
 */

#include <fstream>
#include <iostream>
#include <string>

#ifndef FILERESOLVER_HPP
#define FILERESOLVER_HPP

using namespace std;

class FileResolver
{
private:
  fstream _file;

public:
  // Abre o arquivo no constructor
  FileResolver(string fileName);
  // Fecha o arquivo no destructor
  ~FileResolver();

  // Le o arquivo
  void readFile();
};

#endif