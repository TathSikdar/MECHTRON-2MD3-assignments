#include <cstdlib>
#include <iostream>

template <typename T>
T genericMin(T a, T b) {  // returns the minimum of a and b
  return (a < b ? a : b);
}

int main() {
  std::cout << genericMin(3, 4) << ' '      // = genericMin<int>(3,4)
            << genericMin(1.1, 3.1) << ' '  // = genericMin<double>(1.1, 3.1)
            << genericMin('t', 'g')         // = genericMin<char>('t','g')
            << std::endl;  
}