#include <cstdlib>
#include <iostream>

void f(int value, int& ref) {  // one value and one reference​
  ref += --value + 1;             
}

int main() {
  int v = 2;
  int r = 8;
  f(v, r);
  std::cout << v << " " << r << std::endl;  // what will printed values be?
}