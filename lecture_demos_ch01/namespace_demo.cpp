#include <cstdlib>
#include <iostream>

namespace myglobals {
  int cat;
  std::string dog = "Bow Wow!";
}

using std::string;                 // makes just std::string accessible
using std::cout;                   // makes just std::cout accessible
using namespace std;               // make entire std namespace accessible
using namespace myglobals;         // makes all of myglobals accessible

int main()
{
    // can now omit "std::"
    string s = "Hello dog.";
    cout << s << endl;
    cout << dog << endl;
    return EXIT_SUCCESS; //  terminate successfully
}