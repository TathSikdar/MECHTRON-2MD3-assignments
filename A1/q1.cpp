#include <cstdlib>
#include <iostream>


int main(){
    int value = 21;
    int *A = &value; //pointer to value

    int B = *A*2; //dereference A and multiply by 2

    std::cout << "B: " << B << std::endl;

    return EXIT_SUCCESS;
}