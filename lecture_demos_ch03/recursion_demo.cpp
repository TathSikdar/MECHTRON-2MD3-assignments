#include <cstdlib>
#include <iostream>

int recursiveFactorial(int n) {  // recursive factorial function
  if (n == 0)
    return 1;  // basis case
  else
    return n * recursiveFactorial(n - 1);  // recursive case
}

int tailRecursiveFactorial(
    int n, int accumulator) { 
  if (n == 0)
    return accumulator;
  else
    return tailRecursiveFactorial(n - 1, n * accumulator);
}

typedef struct {
  int first, second;
} Pair;

Pair LinearFib(int k) {
  if (k == 0) {
    Pair p = {1, 0};
    return p;
  } else {
    Pair p1 = LinearFib(k - 1);
    Pair p2;
    p2.first = p1.first + p1.second;
    p2.second = p1.first;

    return p2;
  }
}

int Fibonacci(int k) { return LinearFib(k).first; }

int main() {
  std::cout << recursiveFactorial(7) << std::endl;
  std::cout << tailRecursiveFactorial(7, 1) << std::endl;
  std::cout << Fibonacci(7) << std::endl;
}