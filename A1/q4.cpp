#include <cstdlib>
#include <iostream>

int divideBy2(double x){
    int counter = 0; // number of divides

    // any number that cannot be divided by 2 without yeilding less than 2
    if(x<4){
        return 0;
    }

    // divides by 2 until x<=2
    while(x>2){
        x /= 2;
        counter++;
    }

    return counter;
}

int main(){
    std::cout<<divideBy2(2.1);

    return EXIT_SUCCESS;
}