#include "agenda.h"

void Agenda::getNames()
{
  cout << "\nOs nomes salvos são: " << endl;
  for (int i = 0; i < 3; i++)
  {
    cout << names[i] << endl;
  }
}

void Agenda::setNames()
{
  string name;

  for (int i = 0; i < 3; i++)
  {
    cout << "\nEntre com o nome da pessoa: " << endl;
    cin >> name;
    names[i] = checkName(name);
  }
}

string Agenda::checkName(string name)
{
  if (name.length() > 10)
  {
    name = name.substr(0, 10);
    cout << "Nome truncado para: " << name << endl;
  }
  return name;
}