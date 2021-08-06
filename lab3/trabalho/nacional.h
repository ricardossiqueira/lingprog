#include "estadual.h"
#include <vector>

class Nacional
{
public:
  Nacional(string, vector<Estadual>);
  // Getters
  string getNome();
  vector<Estadual> getEstados();

private:
  // Campos privados da classe
  string _nome;
  vector<Estadual> _estados;
};