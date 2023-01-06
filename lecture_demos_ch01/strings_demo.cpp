#include <cstdlib>
#include <iostream>
int main()
{
    std::string s = "Hello World";
    std::cout << s << std::endl;

    s = "to be";
    std::string t = "not" + s;       // t = "not to be"
    std::string u = s + " or " + t;  // u = "to be or not to be"
    if (s > t)                       // true: "to be" > "not to be"
        std::cout << u << std::endl; // outputs "to be or not to be"

    s = "John";       // s = "John"
    int i = s.size(); // i = 4
    char c = s[3];    // c = 'n'
    s += " Smith";    // now s = "John Smith"
    std::cout << s << std::endl;

    s = "a dog";                   // "a dog"
    s += " is a dog";              // "a dog is a dog"
    std::cout << s.find("dog") << std::endl;    // 2
    std::cout << s.find("dog", 3) << std::endl; // 11
    if (s.find("doug") == std::string::npos)
        std::cout << "true!" << std::endl;
    std::cout << s.substr(7, 5) << std::endl; // "s a d"
    s.replace(2, 3, "frog");     // "a frog is a dog"
    s.erase(6, 3);               // "a frog a dog"
    s.insert(0, "is ");          // "is a frog a dog"
    if (s == "is a frog a dog")  // true
        std::cout << "true!" << std::endl;
    if (s < "is a frog a toad")  // true
        std::cout << "true!" << std::endl;
    if (s < "is a frog a cat")   // false
    {
        std::cout << "true!" << std::endl;
    }
    else
    {
        std::cout << "false!" << std::endl;
    }
    return EXIT_SUCCESS; //  terminate successfully
}