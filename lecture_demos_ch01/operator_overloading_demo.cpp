#include <cstdlib>
#include <iostream>

enum MealType
{
    NO_PREF,
    REGULAR,
    LOW_FAT,
    VEGETARIAN
};

struct Passenger
{
    std::string name;        // passenger name
    MealType mealPref;       // meal preference
    bool isFreqFlyer;        // in the frequent flyer program?
    int freqFlyerNo; // the passenger's freq. flyer number
};

bool operator==(const Passenger &x, const Passenger &y)
{
    return x.name == y.name &&
           x.mealPref == y.mealPref &&
           x.isFreqFlyer == y.isFreqFlyer &&
           x.freqFlyerNo == y.freqFlyerNo;
}

std::ostream &operator<<(std::ostream &out, const Passenger &pass)
{
    out << pass.name << " " << pass.mealPref;
    if (pass.isFreqFlyer)
    {
        out << " " << pass.freqFlyerNo;
    }
    return out;
}

int main()
{
    Passenger* p1 = new Passenger;
    p1->name = "Wyatt";
    p1->isFreqFlyer = true;
    p1->freqFlyerNo = 1;
    Passenger* p2 = new Passenger;
    p2->name = "Gomer";
    p2->isFreqFlyer = true;
    p2->freqFlyerNo = 2;

    std::cout << "Passengers " << *p1 << " and " << *p2 << " are";
    if (!(*p1 == *p2))
        std::cout << " not the same." << std::endl;
    else
        std::cout << " the same." << std::endl;

    delete p1;
    delete p2;
    return EXIT_SUCCESS; //  terminate successfully
}