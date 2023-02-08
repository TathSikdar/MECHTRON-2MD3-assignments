#include <cstdlib>
#include <iostream>
using namespace std;

int minValueGreater () {
    int n, first, x;        // variable instantiations
    cin >> n >> first >> x; // first inputs
    
    if (n == 0) return -1;  // no elements in list

    int value, next;        // variable instantiations
    int array[2][n];        // array instantiation

    for (int i=0; i<n; i++) { // next n inputs
        cin >> value >> next;
        array[0][i] = value;  // values
        array[1][i] = next;   // pointers
    }

    while (1) {
        if (array[0][n-1] > x) { // element greater than x found
            return array[0][n-1];
        }

        if (array[1][n-1] == -1) // end of list
            break;
        else
            n = array[1][n-1];   // increment list
    }
    return -1;                   // no greater element foundd
}

int main() {
    cout<<minValueGreater();
    return EXIT_SUCCESS;
}