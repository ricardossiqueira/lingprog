#include <string>
#include <vector>

using namespace std;

class Estadual
{
public:
  // Construtor para classe Estadual
  Estadual(string, vector<int>);
  // Setters
  void setNome(string);
  // Getters
  string getNome();
  vector<int> getObitos();

private:
  // Campos privados da classe
  string _nome;
  vector<int> _obitos;
};