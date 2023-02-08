#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

class DNode {                // doubly linked list node
 private:
  string name;               // name of score recipiant
  int score;
  DNode* prev;               // previous node in list
  DNode* next;               // next node in list
  friend class DLinkedList;  // allow DLinkedList access
};

class DLinkedList {  // doubly linked list
 public:
  DLinkedList();                    // constructor
  DLinkedList(DLinkedList& dll);    // copy constructor
  ~DLinkedList();                   // destructor
  bool empty() const;               // is list empty?
  const string& frontName() const;  // get front element name
  const int& frontScore() const;    // get front element score
  const string& backName() const;   // get back element name
  const int& backScore() const;     // get back element score
  int Size();                       // count number of elements
  void AddScoreInOrder(std::string name, int score); // add game score
  void RemoveScore(int index);   // removes i'th element of list
  bool UpdateScore(std::string name, int score);    // update score associated with given name 
                                                    // return true if name was found and updated
  void Print();                  // prints all elements of list
  void operator=(const DLinkedList& dll);
  void OrderByName();            // orders list in alphabetical order
 private:                        // local type definitions
  DNode* header;                 // list sentinels
  DNode* trailer;
  void init();                      // chain default constructor
  void copy(const DLinkedList& dll);      // copies all elements of dll
  void deleteList();                        // delete all elements except sentinels
  int Size(DNode*& first, DNode*& last, int count); 
  void Print(DNode*& currentNode);

 protected:                           // local utilities
  void addFront(const string& name, const int& score);   // add to front of list
  void addBack(const string& name, const int& score);    // add to back of list
  void removeFront();            // remove from front
  void removeBack();             // remove from back
  void add(DNode* v, const string& e, const int& score);  // insert new node before v
  void remove(DNode* v);              // remove node v
};

DLinkedList::DLinkedList() {  // constructor
    init();
}

DLinkedList::DLinkedList(DLinkedList& dll) {
    init();         // make header and trailer
    copy(dll);
}

DLinkedList::~DLinkedList() {  // destructor
  deleteList();
  delete header;  //  remove the sentinels
  delete trailer;
}

void DLinkedList::init() {
  header = new DNode;      // create sentinels
  trailer = new DNode;
  header->next = trailer;  // have them point to each other
  trailer->prev = header;
  header->prev = NULL;
  trailer->next = NULL;
}

void DLinkedList::copy(const DLinkedList& dll) {
    if (dll.header->next == dll.trailer)            // empty list
        return;

    DNode* firstcopy = dll.header;             // used to increment from head
    DNode* lastcopy = dll.trailer;             // used to increment from tail
    DNode* first = header;
    DNode* last = trailer;
    
    do {
        firstcopy = firstcopy->next;           // increment from head
        lastcopy = lastcopy->prev;             // increment from tail

        if (dll.header-> next == dll.trailer->prev) {  // last node + odd nummber of nodes
            add(first, firstcopy->name, firstcopy->score); // copy final element
            return;
        }

        add(first, firstcopy->name, firstcopy->score); // copy element closer to head
        add(last->prev, lastcopy->name, lastcopy->score); // copy element closer to tail

        first = first->next; // increment from head
        last = last->prev; // increment from tail
    } while ((firstcopy != lastcopy) && (firstcopy->next != lastcopy)); // stop when 
}

void DLinkedList::deleteList() {
    while (!empty()) {
    removeFront();  //  remove all but sentinels
    }
}

bool DLinkedList::empty() const {  // is list empty?
  return (header->next == trailer);
}

const string& DLinkedList::frontName() const {  // get front element
  return header->next->name;
}

const int& DLinkedList::frontScore() const {
    return header->next->score;
}

const string& DLinkedList::backName() const {  // get back element
  return trailer->prev->name;
}

const int& DLinkedList::backScore() const {
    return trailer->prev->score;
}

void DLinkedList::add(DNode* x, const string& name, const int& score) {
  DNode* newNode = new DNode;
  newNode->name = name;
  newNode->score = score;
  newNode->next = x->next;
  newNode->prev = x;
  x->next->prev = newNode;
  x->next = newNode;
}

void DLinkedList::addFront(const string& name, const int& score) {  // add to front of list
  add(header, name, score);
}

void DLinkedList::addBack(const string& name, const int& score) {  // add to back of list
  add(trailer->prev, name, score);
}

void DLinkedList::remove(DNode* v) {  // remove node v
  DNode* u = v->prev;                 // predecessor
  DNode* w = v->next;                 // successor
  u->next = w;                        // unlink v from list
  w->prev = u;
  delete v;
}

void DLinkedList::removeFront() {  // remove from font
  remove(header->next);
}

void DLinkedList::removeBack() {  // remove from back
  remove(trailer->prev);
}

int DLinkedList::Size() {
    if (header->next == trailer) return 0;                      // empty list
    else if (header->next == trailer->prev) return 1;
    else if (header->next->next == trailer->prev) return 2;
    return Size(header->next->next, trailer->prev->prev, 2);    // more than 2 elements
} 

int DLinkedList::Size(DNode*& first, DNode*& last, int count) {
    if (first == last) return ++count;                          // odd base case
    else if (first->next == last) return count+2;               // even base case
    return Size(first->next, last->prev, count+2);              // more elements in list
}

void DLinkedList::AddScoreInOrder(string name, int score) {
    if (empty()) {
        addFront(name, score);      // add score to empty list
        return;
    }

    DNode* currentNode = header->next;

    for (int i=0; i<Size(); i++) {
        if ((currentNode->score) < score) {        // new score less than inputted score
            add(currentNode->prev, name, score);   // add score behind node
            return;
        }
        currentNode = currentNode->next;           // increment node
    }
    addBack(name, score);                          // no elements less than inputted score
    return;
}


void DLinkedList:: RemoveScore(int index) {
    if (header->next == trailer) 
        throw std::out_of_range ("There are no elements in list");          // no elements in list

    int len = Size();

    if (index > len || index < 0) 
        throw std::out_of_range ("Index is out of bounds");

    DNode* currentNode;

    if (index > len/2) {                          // index closer to trailer
        currentNode = trailer;
        for (int i=0; i < len-index; i++) {
            currentNode = currentNode->prev;
        }
    }
    else {
        currentNode = header;
        for (int i=0; i<=index; i++) {             // index closer to header
            currentNode = currentNode->next;       // itterate node
        }
    }
    remove(currentNode);
}

bool DLinkedList::UpdateScore(std::string name, int score) {
    if (header->next == trailer)                   // empty list
        return false;
    DNode* front = header;
    DNode* last = trailer;
    do {
        front = front ->next;                      // increment node
        last = last -> prev;                       // increment node
        if (front->name == name) {                 // node found closer to header
            remove(front);                         // remove node
            AddScoreInOrder(name, score);          // reorder node
            return true;
        }
        else if (last->name == name) {             // node found closer to trailer
            remove(last);                          // remove node
            AddScoreInOrder(name, score);          // reorder node
            return true;
        }
    }
    while ((front != last) && (front->next != last));// node not found
    return false;
}

void DLinkedList::Print() {
    if (empty()) cout << "{}" << endl;
    return Print(header->next);
}

void DLinkedList::Print(DNode*& currentNode) {
    if (currentNode->next->next) {  // has 2 next nodes
        cout << "{" << currentNode->name << ", " << currentNode->score << "}" << "->"; 
        return Print(currentNode->next);
    }
    cout << "{" << currentNode->name << ", " << currentNode->score << "}" << endl;  // print final node
    return;
}

void DLinkedList::operator=(const DLinkedList& dll) {
    deleteList();   // remove all contents of previous list
    copy(dll);      // copy all contents from dll
}

void DLinkedList::OrderByName() {
    int len = Size();
    if (len == 1 || len == 0) return;       // no sorting required

    int changes;                            // number of changes made to list
    do {
        changes = 0;
        DNode* currentNode = header->next;  // reset node
        for (int i=0; i<len-1; i++) {
            DNode* nextNode = currentNode->next; // save next node before remove
            if (strcmp(currentNode->name.c_str(), nextNode->name.c_str()) > 0) { // swap if out of order
                string name = currentNode->name; // save values before remove
                int score = currentNode->score;  // ''
                remove(currentNode);
                add(nextNode, name, score);
                changes++;                  // node changed
            }
            currentNode = nextNode;         // increment node
        }
    } while (changes);                      // run until no changes are made to list
}

int main() {
DLinkedList scores;
scores.AddScoreInOrder("Jeff", 7);
scores.AddScoreInOrder("Jen", 9);
scores.AddScoreInOrder("Ilya", 3);
scores.AddScoreInOrder("Sara", 10);
scores.AddScoreInOrder("Sam", 11);
// Test size function
cout << "Number of scores is " << scores.Size() << endl;
scores.Print();
// Test remove function
scores.RemoveScore(3);
cout << "Number of scores is now " << scores.Size() << endl;
scores.Print();
// Test update function
if (scores.UpdateScore("Jeff",6))
    scores.Print();
// Test copy construcor
DLinkedList scores_copy_1(scores);
scores.UpdateScore("Jen",5);
scores.Print();
scores_copy_1.Print();
// Test assignment operator overload
DLinkedList scores_copy_2 = scores_copy_1;
scores_copy_1.UpdateScore("Jen",5);
scores_copy_1.Print();
scores_copy_2.Print();

// Test OrderByName function
scores_copy_2.OrderByName();
scores_copy_2.Print();
}