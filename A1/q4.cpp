#include <cstdlib>
#include <iostream>

int divideBy2(double x){
    int counter = 0;

    while(x>=2){
        x /= 2;
        counter++;
    }

    return counter;
}

int main(){
    std::cout<<divideBy2(8);

    return EXIT_SUCCESS;
}