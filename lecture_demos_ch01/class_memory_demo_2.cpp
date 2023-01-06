#include <cstdlib>
#include <iostream>
#include <unistd.h> // sleep

// a vector class
class Vect
{
public:                  // all members are public for simplicity
    Vect(int n);         // constructor, given size
    Vect(const Vect &a); // copy constructor
    ~Vect();             // destructor
    void fill(double x);
    Vect &operator=(const Vect &a);

    double *data; // an array holding the vector
    int size;     // number of array entries
};

// constructor
Vect::Vect(int n)
{
    size = n;
    data = new double[n]; // allocate array
}

// copy constructor
Vect::Vect(const Vect &a)
{
    size = a.size;           // copy sizes​
    data = new double[size]; // allocate new array​
    for (int i = 0; i < size; i++)
    { // copy the vector contents​
        data[i] = a.data[i];
    }
}

// assignment operator
Vect &Vect::operator=(const Vect &a)
{
    if (this != &a)
    {                            // avoid self-assignment
        delete[] data;           // delete old array
        size = a.size;           // set new size
        data = new double[size]; // allocate new array
        for (int i = 0; i < size; i++)
        { // copy the vector contents
            data[i] = a.data[i];
        }
    }
    return *this;
}

// destructor
Vect::~Vect()
{
    delete[] data; // free the allocated array
}

void Vect::fill(double x)
{
    for (int i = 0; i < size; i++)
        data[i] = x;
}

int main()
{
    Vect a(7); // a is a vector of size 7
    a.fill(0.1);
    Vect b = a; // initialize b from a (OK with assignment operator!)
    
    // print both Vect to check
    for (int i = 0; i < a.size; i++)
        std::cout << " a[" << i << "] is " << a.data[i] << " b[" << i << "] is " << b.data[i] << std::endl;
     std::cout << std::endl;   

    Vect c(3); // c is a vector with size 10
    c = a;     // assign a to c (OK because assigment operator will resize!)

    // print both Vect to check
    for (int i = 0; i < a.size; i++)
        std::cout << " a[" << i << "] is " << a.data[i] << " c[" << i << "] is " << c.data[i] << std::endl;
}