#include <cstdlib>
#include <iostream>

int twice(){
    int value = 21;
    int *A = &value; //pointer to value

    int B = *A*2; //dereference A and multiply by 2

    return B;
}

int main(){

    twice();

    return EXIT_SUCCESS;
}