#include <cstdlib>
#include <iostream>

using namespace std;

class Person {  // Person (base class)​
 private:
  string name;   
  string idNum;  
 public:
  Person(const string& nm, const string& id);
  virtual ~Person();
  virtual void print();
  string getName();
};

class Student : public Person {  // Student (derived from Person)​
 private:
  string major;  // major subject​
  int gradYear;  // graduation year​
  double *data;  // an arbitrary data array
 public:
  Student(const string& nm, const string& id, const string& maj, int year);
  virtual ~Student();
  virtual void print();                     
  void changeMajor(const string& newMajor);
};

Person::Person(const string& nm, const string& id)  // Person constructor
    : name(nm),     // initialize name​
      idNum(id) {}  //  initialize ID number​

void Person::print() {
  cout << "Name " << name << endl;
  cout << "IDnum " << idNum << endl;
}

Person::~Person() {}  // empty Person destructor (required)

Student::Student(const string& nm, const string& id, const string& maj,
                 int year)
    : Person(nm, id),  // initialize Person members​
      major(maj),      // initialize major​
      gradYear(year)   // initialize graduation year
      {
        data = new double[1000]; // allocate data array
      }  

Student::~Student() {
    delete[] data;  // free the allocated array
}

void Student::print() {
  Person::print();  // first print Person information​
  cout << "Major " << major << endl;
  cout << "Year " << gradYear << endl;
}

void Student::changeMajor(const string& newMajor) {
    major = newMajor;
}

int main() {
  Person* pp[100];  // array of 100 Person pointers​

  pp[0] = new Person("Sam", "12343");   // add a Person
  pp[1] = new Student("Eli", "12347", "Math", 2022);  // add a Student​

  // dynamic binding works because both classes have print() function
  pp[0]->print();            // calls Person::print()​
  pp[1]->print();            // calls Student::print()

  // dynamic cast requred because changeMajor function only in Student class
  Student* sp = dynamic_cast<Student*>(pp[1]); // cast pp[1] to Student*​
  sp->changeMajor("Chemistry");                // OK!
  pp[1]->print();            // print student with new major
}