#include <cstdlib>
#include <iostream>
#define MAX_INDEX 6

int FindNegative(int* A) {
    int i = 0;
    while (A[i] >= 0 && i < MAX_INDEX) { i++; }
    return i < MAX_INDEX ? i : -1;
}

int main() {
    int A[MAX_INDEX] = {3, 1, 2, 7, -9, 5};
    std::cout << "Index of negative int: "<< FindNegative(A) << std::endl;
}