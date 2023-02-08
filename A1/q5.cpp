#include <cstdlib>
#include <iostream>

int GCD(int n, int m){
    int j = n%m; // initial mod value
    int modder = m; // new value to mod

    if (!j){ //if j is the GCD
        return m;
    }
    else{
        while(modder%j){ //run until mod is 0
            int tempModder = j; // used to set value modder later
        
            j=modder%j;
            modder = tempModder;
        }
        return j;
    }
}

int main(){
    
    std::cout<<GCD(6,4);

    return EXIT_SUCCESS;
}