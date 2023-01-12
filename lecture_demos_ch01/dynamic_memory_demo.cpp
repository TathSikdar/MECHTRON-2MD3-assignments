#include <unistd.h>  // sleep

#include <cstdlib>
#include <iostream>

enum MealType { NO_PREF, REGULAR, LOW_FAT, VEGETARIAN };

struct Passenger {
  std::string name;         // passenger name
  MealType mealPref;        // meal preference
  bool isFreqFlyer;         // in the frequent flyer program?
  std::string freqFlyerNo;  // the passenger's freq. flyer number
  double data[10000000];    // some arbitrary data
};

int main() {
  while (true) {
    for (int i = 0; i < 100000; i++) {
      Passenger *p = new Passenger;  // p points to the new Passenger
                                     // do stuff with p ...
                                     // delete p;
    }
    std::cout << "doing stuff..." << std::endl;
    sleep(1);
  }
  return EXIT_SUCCESS;  //  terminate successfully
}