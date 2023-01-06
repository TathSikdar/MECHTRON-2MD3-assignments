#include <cstdlib>
#include <iostream>
#include <unistd.h> // sleep

// a vector class
class Vect
{ 
public:
    Vect(int n); // constructor, given size
    ~Vect();     // destructor
                 // ... other public members omitted
private:
    double *data; // an array holding the vector
    int size;  // number of array entries
};

// constructor
Vect::Vect(int n)
{ 
    size = n;
    data = new double[n]; // allocate array
}

// destructor
Vect::~Vect()
{                  
    delete[] data; // free the allocated array
}

int main()
{
    while (true)
    {
        for (int i = 0; i < 10000; i++)
        {
            Vect a(1000); 
            // do stuff with a ...
        }
        std::cout << "doing stuff..." << std::endl;
        sleep(1);
    }
}