#include <string>   // provides string
#include <iostream> // provides ostream
#include <vector>   // provides STL vector

using namespace std; // make std accessible

class CreditCard
{
public:
  CreditCard(const std::string &no, // constructor
             const std::string &nm, int lim, double bal = 0);
  // accessor functions
  std::string getNumber() const { return number; }
  std::string getName() const { return name; }
  double getBalance() const { return balance; }
  int getLimit() const { return limit; }

  bool chargeIt(double price);      // make a charge
  void makePayment(double payment); // make a payment
private:                            // private member data
  std::string number;               // credit card number
  std::string name;                 // card owner's name
  int limit;                        // credit limit
  double balance;                   // credit card balance
};

// print card information
std::ostream &operator<<(std::ostream &out, const CreditCard &c);

// standard constructor
CreditCard::CreditCard(const string &no, const string &nm, int lim, double bal)
{
  number = no;
  name = nm;
  balance = bal;
  limit = lim;
}

// make a charge
bool CreditCard::chargeIt(double price)
{
  if (price + balance > double(limit))
    return false; // over limit
  balance += price;
  return true; // the charge goes through
}

// make a payment
void CreditCard::makePayment(double payment)
{
  balance -= payment;
}

// print card information
ostream &operator<<(ostream &out, const CreditCard &c)
{
  out << "Number = " << c.getNumber() << "\n"
      << "Name = " << c.getName() << "\n"
      << "Balance = " << c.getBalance() << "\n"
      << "Limit = " << c.getLimit() << "\n";
  return out;
}

// CreditCard test function
void testCard()
{
  vector<CreditCard *> wallet(10); // vector of 10 CreditCard pointers
  // allocate 3 new cards
  wallet[0] = new CreditCard("5391 0375 9387 5309", "John Bowman", 2500);
  wallet[1] = new CreditCard("3485 0399 3395 1954", "John Bowman", 3500);
  wallet[2] = new CreditCard("6011 4902 3294 2994", "John Bowman", 5000);

  for (int j = 1; j <= 16; j++)
  {                                 // make some charges
    wallet[0]->chargeIt(double(j)); // explicitly cast to double
    wallet[1]->chargeIt(2 * j);     // implicitly cast to double
    wallet[2]->chargeIt(double(3 * j));
  }

  cout << "Card payments:\n";
  for (int i = 0; i < 3; i++)
  { // make more charges
    cout << *wallet[i];
    while (wallet[i]->getBalance() > 100.0)
    {
      wallet[i]->makePayment(100.0);
      cout << "New balance = " << wallet[i]->getBalance() << "\n";
    }
    cout << "\n";
    delete wallet[i]; // deallocate storage
  }
}

int main()
{
  testCard();
  return EXIT_SUCCESS;
}