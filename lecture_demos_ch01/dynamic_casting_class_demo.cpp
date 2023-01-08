#include <cstdlib>
#include <iostream>
using namespace std;

class Person {  // Person (base class)
 private:
  string name;   // name
  string idNum;  // university ID number
 public:
  Person(const string& nm, const string& id);  // constructor
  virtual void print();                        // print information
  string getName();                            // retrieve name
  virtual ~Person() {}                         // empty destructor
};

Person::Person(const string& nm, const string& id)  // constructor
    : name(nm),                                     // initialize name
      idNum(id) {}                                  //  initialize ID number

void Person::print() {  // definition of Person print
  cout << "Name " << name << endl;
  cout << "IDnum " << idNum << endl;
}

class Student : public Person {  // Student (derived from Person)
 private:
  string major;  // major subject
  int gradYear;  // graduation year
 public:
  Student(const string& nm, const string& id,  // constructor
          const string& maj, int year);
  virtual ~Student() {}                      // empty destructor
  virtual void print();                      // print information
  void changeMajor(const string& newMajor);  // change major
};

Student::Student(const string& nm, const string& id, const string& maj,
                 int year)
    : Person(nm, id),    // initialize Person members
      major(maj),        // initialize major
      gradYear(year) {}  //  initialize graduation year

void Student::print() {  // definition of Student print
  Person::print();       // first print Person information
  cout << "Major " << major << endl;
  cout << "Year " << gradYear << endl;
}

void Student::changeMajor(const string& newMajor) { major = newMajor; }

int main() {
  Person* pp[100];                         // array of 100 Person pointers
  pp[0] = new Person("Bob Smith", "123");  // add a Person
  pp[1] = new Student("Bard Smith", "1234", "Fine Art", 2022);  // add a Student

  for (int i = 0; i <= 1; i++) {
    Student* sp = dynamic_cast<Student*>(pp[i]);
    if (sp != NULL)                  // cast succeeded?
      sp->changeMajor("Undecided");  // change major
  }
  pp[1]->print();
}