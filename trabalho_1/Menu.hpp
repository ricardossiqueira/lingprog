/*Trabalho - Linguagens de Programacao
 *Aluno: Ricardo Santos Siqueira
 *DRE: 118167558
 *Periodo: 2021.1
 *Arquivo: Menu.hpp
 *Descricao: Cabecalho da classe Menu
 */

#include <iostream>
#include <string>
#include <regex>
#include <limits>

#ifndef MENU_HPP
#define MENU_HPP

using namespace std;

class Menu
{
private:
  // Url da imagem
  string _uri = "";
  // Parametros enviados para o script python
  bool
      _faces = false,
      _3x4 = false,
      _smooth = false,
      _detail = false;
  float
      _color = 1.f,
      _contrast = 1.f;

  enum _options
  {
    Faces = 1,
    AR3x4,
    Smooth,
    Detail,
    Color,
    Contrast,
    Save
  };

  // Lida com selecoes booleanas (_faces, _3x4, _smooth, _detail)
  bool _handleBool(string msg);
  // Lida com selecao de floats (_color, _contrast)
  float _handleSelection(string msg);

  // Permite apenas entradas validas
  int _validateInput(int num, int min, int max);
  // Sobrecarga para o caso de float (_color, _contrast)
  float _validateInput(float num, float min, float max);

  // Inicializa a URI da classe
  void _handleURI();

  // Implementacao de std::cin para receber apenas valores int
  int _handleNumber();

public:
  // Instancia a classe e garante que todos os valores iniciem "zerados"
  Menu();
  // Inicializa o menu
  void run();
  // Retorna os parametros convertidos para a interface do script python
  string parseCommand();
};

#endif