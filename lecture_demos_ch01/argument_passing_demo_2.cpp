#include <cstdlib>
#include <iostream>

struct Dog {
  std::string name;
  int age;
  double weight; // weight in pounds
};

void changeName(Dog* d, std::string new_name) {
  d->name = new_name;
}

int main() {
  Dog* d = new Dog;
  d->name = "Gomer";
  d->age = 13;
  d->weight = 50.5;

  changeName(d, "Sam");
  
  std::cout << "A dog named " << d->name << std::endl;
}