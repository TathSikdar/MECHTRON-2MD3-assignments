#include <cstdlib>
#include <iostream>

using namespace std;

class Progression{
    public:
        Progression(long f=0)
            :first(f), cur(f){}
        virtual ~Progression(){};
        void printProgression(int n);
    public:
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

class GeomProgression : public Progression{
    public:
        GeomProgression(long b);
    public:
        virtual long nextValue();
    protected:
        long base;
};

GeomProgression::GeomProgression(long b=2)
    :Progression(1), base(b){}

long GeomProgression::nextValue(){
    cur *= base;
    return cur;
}



int main(){

    Progression* p = new GeomProgression();
    std::cout<<q->nextValue()<<'\n';
    std::cout<<q->nextValue()<<'\n';
    Progression* c = new Progression();
    std::cout<<c->nextValue()<<'\n';
    std::cout<<c->nextValue()<<'\n';


    return EXIT_SUCCESS;
}