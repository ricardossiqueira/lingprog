/*Trabalho - Linguagens de Programacao
 *Aluno: Ricardo Santos Siqueira
 *DRE: 118167558
 *Periodo: 2021.1
 *Arquivo: Menu.cpp
 *Descricao: Implementacao das funcoes do menu
 */

#include "Menu.hpp"

Menu::Menu()
{
  _handleURI();
}

void Menu::run()
{
  int option = 0;
  string avalilableOptions = "Opcoes:\n\t1 - Cortar faces\n\t2 - Ajustar proporcao da imagem para 3:4\n\t3 - [Filtro] Suavizar detalhes\n\t4 - [Filtro] Realcar detalhes\n\t5 - [Filtro] Ajustar cor\n\t6 - [Filtro] Ajustar contraste\n\t7 - Salvar copias e sair";

  // Enquanto a opcao selecionada nao for 7 (Save), o programa continua recebendo
  // entradas do usuario. Quando selecionada a opcao o menu retorna e o comando
  // e enviado para o script python que sempre executa a opcao de salvar
  while (option != Save)
  {
    cout << avalilableOptions << endl;
    cout << ">>> ";
    cin >> option;

    while (_validateInput(option, Faces, Save) == 0)
    {
      cout << ">>> ";
      cin >> option;
    }

    switch (option)
    {
    case Faces:
      _faces = _handleBool( //_handleFaces
          "Opcoes:\n\t1 - Cortar apenas rostos\n\t2 - Voltar");
      break;

    case AR3x4:
      _3x4 = _handleBool( // _handle3x4
          "Opcoes:\n\t1 - Ajustar para proporcao 3:4\n\t2 - Voltar");
      break;

    case Smooth:
      _smooth = _handleBool( // _handleSmooth
          "Opcoes:\n\t1 - Suavizar detalhes da imagem\n\t2 - Voltar");
      break;

    case Detail:
      _detail = _handleBool( //_handleDetail
          "Opcoes:\n\t1 - Realcar detalhes da imagem\n\t2 - Voltar");
      break;

    case Color:
      _color = _handleSelection( // _handleColor
          "Opcoes:\n\t1 - Ajustar intensidade de cor\n\t2 - Voltar");
      break;

    case Contrast:
      _contrast = _handleSelection( // _handleContrast
          "Opcoes:\n\t1 - Ajustar contraste\n\t2 - Voltar");
      break;

    default:
      break;
    }
  }
}

string _stringfyBool(bool arg) { return arg ? "true" : "false"; }

string Menu::parseCommand()
{
  return "'" + _uri + "' " + _stringfyBool(_faces) + " " + _stringfyBool(_3x4) + " " + _stringfyBool(_smooth) + " " + _stringfyBool(_detail) + " " + to_string(_color) + " " + to_string(_contrast);
}

bool Menu::_handleBool(string msg)
{
  unsigned selected = 0;
  do
  {
    cout
        << msg
        << endl;
    cout << ">>> ";
    cin >> selected;
  } while (_validateInput(selected, 1, 2) == 0);
  if (selected == 1)
    return true;
  else
    return false;
}

float Menu::_handleSelection(string msg)
{
  unsigned selected = 0;
  float value = -1.f;
  do
  {
    cout
        << msg
        << endl;
    cout << ">>> ";
    cin >> selected;
  } while (_validateInput(selected, 1, 2) == 0);
  if (selected == 1)
  {
    do
    {
      cout
          << "Selecione a intensidade desejada entre 0.0 (0%) e 2.0 (200%)"
          << endl;
      cout << ">>> ";
      cin >> value;
    } while (_validateInput(value, 0.f, 2.f) == -1.f);
    return value;
  }
  else
    return 1.f;
}

int Menu::_validateInput(int num, int min, int max)
{
  if (num < min || num > max)
  {
    cerr
        << "Erro: Entre com um valor valido ["
        << min
        << ", "
        << max
        << "]"
        << endl;
    return 0;
  }
  return num;
}

float Menu::_validateInput(float num, float min, float max)
{
  if (num < min || num > max)
  {
    cerr
        << "Erro: Entre com um valor valido ["
        << min
        << ", "
        << max
        << "]"
        << endl;
    return -1.f;
  }
  return num;
}

void Menu::_handleURI()
{
  string uri;
  cout << "Entre com a URL da imagem:" << endl;
  cout << ">>> ";
  cin >> uri;
  while (!regex_match(uri, regex("((http|https)://)(www.)?[a-zA-Z0-9@:%._\\+~#?&//=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%._\\+~#?&//=]*)")))
  {
    cerr << "Erro: Entre com uma URL valida" << endl;
    cout << ">>> ";
    cin >> uri;
  }
  _uri = uri;
}