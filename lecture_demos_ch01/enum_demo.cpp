#include <cstdlib>
#include <iostream>

enum DogBreed { LAB, POODLE, HOUND, BULLDOG };

int main() {
    DogBreed doggo = LAB;
    std::cout << doggo << std::endl;
}