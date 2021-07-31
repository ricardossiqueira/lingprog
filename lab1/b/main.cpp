#include <iostream>
#include "fibonacci.h"

using namespace std;

int main()
{
  Fibonacci fibonacci;
  int n;

  cout << "Entre com o enesimo elemento da serie: ";
  cin >> n;

  fibonacci.setFibonacci(n);

  cout << "Resultado: " << fibonacci.getFibonacci() << endl;

  return 0;
}