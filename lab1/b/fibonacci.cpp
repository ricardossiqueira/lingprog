#include "fibonacci.h"

void Fibonacci::setFibonacci(int n)
{
  result = fibo(n);
}

int Fibonacci::getFibonacci()
{
  return result;
}

int Fibonacci::fibo(int n)
{
  if (n <= 1)
    return n;
  return Fibonacci::fibo(n - 1) + Fibonacci::fibo(n - 2);
}