#include <iostream>
#include "fibonacci.h"

using namespace std;

int main()
{
  int n;

  cout << "Entre com o enesimo elemento da serie: ";
  cin >> n;

  cout << "Resultado: " << fibonacci(n) << endl;

  return 0;
}