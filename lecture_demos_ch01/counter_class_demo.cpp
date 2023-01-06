#include <cstdlib>
#include <iostream>

class Counter // a simple counter
{ 
public:
    Counter();              // initialization
    int getCount();         // get the current count
    void increaseBy(int x); // add x to the count
private:
    int count; // the counter's value
};

Counter::Counter() // constructor
{
    count = 0;
}

int Counter::getCount() // get current count
{
    return count;
}

void Counter::increaseBy(int x) // add x to the count
{
    count += x;
}

int main()
{
    Counter ctr;                    // an instance of Counter
    std::cout << ctr.getCount() << std::endl; // prints the initial value (0)
    ctr.increaseBy(3);              // increase by 3
    std::cout << ctr.getCount() << std::endl; // prints 3
    ctr.increaseBy(5);              // increase by 5
    std::cout << ctr.getCount() << std::endl; // prints 8
}