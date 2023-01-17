#include <cstdlib>
#include <iostream>

using namespace std;

struct Dog {
  string name = "Frank";
  int age = 10;
  double weight = 3.0; // weight in pounds
};

void f1(Dog* d, std::string new_name) {
  d->name = new_name;
}

int main() {
  Dog* d = new Dog;
  // d->name = "Gomer";
  // d->age = 13;
  // d->weight = 50.5;

  // f1(d, "Sam");
  
  cout << "Dog name is " << d->name << endl;
}