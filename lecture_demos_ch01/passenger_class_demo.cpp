#include <cstdlib>
#include <iostream>

enum MealType { NO_PREF, REGULAR, LOW_FAT, VEGETARIAN };

class Passenger {
 private:
  std::string name;         // passenger name
  MealType mealPref;        // meal preference
  bool isFreqFlyer;         // in the frequent flyer program?
  std::string freqFlyerNo;  // the passenger's freq. flyer number
 public:
  Passenger();  // default constructor​
  Passenger(const std::string &nm, MealType mp,
            const std::string &ffn = "NONE");
  Passenger(const Passenger &pass);  // copy constructor​
  // accessor functions
  std::string GetName() const;
  MealType GetMealPref() const;
  bool CheckFreqFlyer() const;
  std::string GetFreqFlyerNo() const;
  // update functions
  void SetName(std::string nm);
  void SetMealPref(MealType mp);
  void SetFreqFlyer(bool ff);
  void SetFreqFlyerNo(std::string ffn);
};

// default constructor
Passenger::Passenger() {
  name = "--NO NAME--";
  mealPref = NO_PREF;
  isFreqFlyer = false;
  freqFlyerNo = "NONE";
}
// constructor given member values
Passenger::Passenger(const std::string &nm, MealType mp,
                     const std::string &ffn) {
  name = nm;
  mealPref = mp;
  isFreqFlyer = (ffn != "NONE");  // true only if ffn given
  freqFlyerNo = ffn;
}

// copy constructor
Passenger::Passenger(const Passenger &pass) {
  name = pass.name;
  mealPref = pass.mealPref;
  isFreqFlyer = pass.isFreqFlyer;
  freqFlyerNo = pass.freqFlyerNo;
}

// accessor function implementations
std::string Passenger::GetName() const { return name; }
MealType Passenger::GetMealPref() const { return mealPref; }
bool Passenger::CheckFreqFlyer() const { return isFreqFlyer; }
std::string Passenger::GetFreqFlyerNo() const { return freqFlyerNo; }

// updator function implementations
void Passenger::SetName(std::string nm) { name = nm; };
void Passenger::SetFreqFlyer(bool ff) { isFreqFlyer = ff; };
void Passenger::SetFreqFlyerNo(std::string nm) { freqFlyerNo = nm; };

bool operator==(const Passenger &x, const Passenger &y) {
  return x.GetName() == y.GetName() && x.GetMealPref() == y.GetMealPref() &&
         x.CheckFreqFlyer() == y.CheckFreqFlyer() &&
         x.GetFreqFlyerNo() == y.GetFreqFlyerNo();
}

std::ostream &operator<<(std::ostream &out, const Passenger &pass) {
  out << pass.GetName() << " " << pass.GetMealPref();
  if (pass.CheckFreqFlyer()) {
    out << " " << pass.GetFreqFlyerNo();
  }
  return out;
}

int main() {
  Passenger *p1 = new Passenger("Wyatt", REGULAR, "1");

  Passenger *p2 = new Passenger;
  p2->SetName("Gomer");
  p2->SetFreqFlyer(true);
  p2->SetFreqFlyerNo("1");

  Passenger *p3 = new Passenger(*p2);

  std::cout << "Passengers " << *p1 << " and " << *p2 << " are";
  if (!(*p1 == *p2))
    std::cout << " not the same." << std::endl;
  else
    std::cout << " the same." << std::endl;

  std::cout << "Passengers " << *p2 << " and " << *p3 << " are";
  if (!(*p2 == *p3))
    std::cout << " not the same." << std::endl;
  else
    std::cout << " the same." << std::endl;

  delete p1;
  delete p2;
  delete p3;
  return EXIT_SUCCESS;  //  terminate successfully
}