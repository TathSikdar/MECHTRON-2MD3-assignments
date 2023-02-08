#include <cstdlib>
#include <iostream>

using namespace std;

class Progression{
    public:
        Progression(long f=0)
            :first(f), cur(f){}
        virtual ~Progression(){};
        void printProgression(int n);
    protected:
        virtual long firstValue();
        virtual long nextValue();
    protected:
        long first;
        long cur;
};

void Progression::printProgression(int n){
    cout << firstValue();
    for (int i=2; i<=n; i++)
        cout << ' ' << nextValue();
    cout << endl;
}

long Progression::firstValue(){
    cur = first;
    return cur;
}

long Progression::nextValue(){
    return ++cur;
}

class AbsoluteProgression: public Progression{
    public:
        AbsoluteProgression(long firstNum = 2, long secondNum = 200)
            :Progression(secondNum),lastValue(firstNum){}
        virtual ~AbsoluteProgression(){};
    private:
        long lastValue;
        virtual long nextValue();
};

long AbsoluteProgression::nextValue(){
    long tempLastValue = cur;
    cur = abs(cur - lastValue);
    lastValue = tempLastValue;
    
    return cur;
}

int main(){
    AbsoluteProgression* that = new AbsoluteProgression(3, 300);
    AbsoluteProgression* notthat = new AbsoluteProgression();
    notthat->printProgression(10);
    that->printProgression(10);

    return EXIT_SUCCESS;
}