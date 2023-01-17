#include <cstdlib>
#include <iostream>

template <typename T>
class BasicVector {  // a simple vector class
 public:
  BasicVector(int capac = 10);  // constructor
  T &operator[](int i)          // access element at index i
  {
    return a[i];
  }
 private:
  T *a;          // array storing the elements
  int capacity;  // length of array a
};

template <typename T>  // constructor
BasicVector<T>::BasicVector(int capac) {
  capacity = capac;
  a = new T[capacity];  // allocate array storage
}

int main() {
  BasicVector<int> iv(5);           // vector of 5 integers
  BasicVector<double> dv(20);       // vector of 20 doubles
  BasicVector<std::string> sv(10);  // vector of 10 strings

  iv[3] = 8;
  dv[14] = 2.5;
  sv[7] = "hello";

  std::cout << iv[3] << " " << dv[14] << " " << sv[7] << std::endl;
}