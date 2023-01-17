#include <cstdlib>
#include <iostream>
#include <ctime>

// generates a list of birthdays (int list ranging from 0 to 365)
int* makeBirthdays(const int& n){
    int* birthdays = new int[n];
    for(int i=0; i<n; i++){
        birthdays[i] = rand() % 364; // generate random numbers from 0 to 364
    }
    return birthdays;
}

bool compareBirthdays(const int* birthdays, const int& n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if (birthdays[i]==birthdays[j]){
                return true; // matching birthdays found
            }
        }
    }
    return false; // matching birthdays not found
}

void experiment(const int& n){
    srand(time(0));
    int counter = 0;
    for(int i=0; i<100; i++){
        int* birthdays = makeBirthdays(n);
        counter+=compareBirthdays(birthdays,n);
    }
    std::cout<<n<<","<<counter<<","<<counter/100.0<<std::endl;
}



int main(){
    for (int i = 5; i <= 100; i+=5)
    {
        experiment(i);
    }
    

    return EXIT_SUCCESS;
}