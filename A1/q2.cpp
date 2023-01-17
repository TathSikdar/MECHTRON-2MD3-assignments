#include <cstdlib>
#include <iostream>

int main(){
    double* dp = new double[10]; // allocate memory for array of 10 elements

    // replace all elements with 0.0
    for(int i =0; i<10; i++){ 
        dp[i]=0.0;
    }

    // prints list
    std::cout<<"index: value"<<std::endl<<"------------"<<std::endl;
    for(int i=0; i<10; i++){
        std::cout<<i<<": "<<std::to_string(*dp)<<std::endl;
    }

    return EXIT_SUCCESS;
}

