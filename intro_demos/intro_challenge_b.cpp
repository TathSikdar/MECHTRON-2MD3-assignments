#include <cstdlib>
#include <iostream>
#define MAX_INDEX 6

int FindNegative(int A[]) {
    int i, result;
    result = -1;
    for (i = MAX_INDEX - 1; i >= 0; --i) {
      if (A[i] < 0) result = i;
    }
    return result;
}

int main() {
    int A[MAX_INDEX] = {0, 1, 2, 7, -9, 5};
    std::cout << FindNegative(A) << std::endl;
}