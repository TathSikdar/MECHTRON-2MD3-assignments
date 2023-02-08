#include <cstdlib>
#include <iostream>

template <typename T1, typename T2> class Pair{
    public:
      Pair(T1 val1, T2 val2)
        :value1(val1),value2(val2){}
      void print();
    private:
      T1 value1;
      T2 value2;
};

template <typename T1, typename T2> void Pair<T1,T2>::print(){
    std::cout<<'<'<<value1<<','<<value2<<'>'<<std::endl;
}



int main() {
    Pair<int, double> p1(1, 7.3);
    p1.print();
    Pair<std::string, double> p2("hello", 7.7);
    p2.print();
    Pair<float, long> p3(1.2, 777777773);
    p3.print();
}