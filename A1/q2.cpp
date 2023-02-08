#include <cstdlib>
#include <iostream>

double** array(){
    double** dp = new double*[10]; // allocate memory for 10 double pointers

    // sets all indexes of dp
    for(int i =0; i<10; i++){
        double* n = new double; // allocate memory for double
        *n = 0.0; // set value of double
        dp[i] = n; // assign each index
    }
    return dp;
}

int main(){
    
    double** list = array();
    for(int i=0; i<10; i++)
        std::cout<<(list[i])<<'\n';
    

    return EXIT_SUCCESS;
}

