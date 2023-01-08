#include <cstdlib>
#include <iostream>

class Vector  // a 3-element vector
{
 public:
  Vector(double v);  // construcor, given initial values
  double at(int i);  // access values by index
 private:
  double coord[3];      // storage for coordinates
  friend class Matrix;  // give Matrix access to coord
};

Vector::Vector(double v) {
  for (int i = 0; i < 3; i++) coord[i] = v;
}

double Vector::at(int i) { return coord[i]; }

class Matrix  // a 3x3 matrix
{
 public:
  Matrix(double v);                  // constructor, given initial values
  Vector multiply(const Vector &v);  // multiply by vector v
 private:
  double a[3][3];  // matrix entries
};

Matrix::Matrix(double v) {
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) a[i][j] = v;
}

Vector Matrix::multiply(const Vector &v)  // multiply by vector v
{
  Vector w(0);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      w.coord[i] += a[i][j] * v.coord[j];  // access to coord allowed
  return w;
}

int main() {
  Vector v(7);
  Matrix m(7);
  Vector vm = m.multiply(v);
  for (int i = 0; i < 3; i++) std::cout << " " << vm.at(i);
  std::cout << std::endl;
}