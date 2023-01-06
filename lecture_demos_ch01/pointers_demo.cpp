#include <cstdlib>
#include <iostream>
int main()
{
    char ch = 'Q';
    char *p = &ch;  // p holds the address of ch
    std::cout << *p << std::endl;    // outputs the character 'Q'
    ch = 'Z';      // ch now holds 'Z'
    std::cout << *p << std::endl;    // outputs the character 'Z'
    *p = 'X';      // ch now holds 'X'
    std::cout << ch << std::endl;    // outputs the character 'X'
    return EXIT_SUCCESS; //  terminate successfully
}