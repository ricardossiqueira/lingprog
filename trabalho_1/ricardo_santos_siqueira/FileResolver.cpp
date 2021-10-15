/*Trabalho - Linguagens de Programacao
 *Aluno: Ricardo Santos Siqueira
 *DRE: 118167558
 *Periodo: 2021.1
 *Arquivo: FileResolver.cpp
 *Descricao: Implementacao da classe FileResolver
 */

#include "FileResolver.hpp"

FileResolver::FileResolver(string fileName)
{
  _file.open(fileName, fstream::in);
}

FileResolver::~FileResolver() { _file.close(); }

void FileResolver::readFile()
{
  if (!_file.is_open())
  {
    cerr << "Erro: Erro ao abrir arquivo" << endl;
    return;
  }

  cout << "Arquivos gerados: " << endl;
  while (_file.good())
  {
    string fileName = "";
    _file >> fileName;
    cout << "\t" << fileName << endl;
  }
}