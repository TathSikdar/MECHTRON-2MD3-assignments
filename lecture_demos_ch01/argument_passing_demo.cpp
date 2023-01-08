#include <cstdlib>
#include <iostream>

void f(int value, int& ref) {  // one value and one reference​
  value++;                     // no effect on the actual argument​
  ref += value;                // modifies the actual argument (ref)
}
int main() {
  int v = 1;
  int r = 7;
  f(v, r);
  std::cout << v << " " << r << std::endl;  // what will printed values be?
}