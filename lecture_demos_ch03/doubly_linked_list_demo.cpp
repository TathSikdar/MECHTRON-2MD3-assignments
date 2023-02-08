#include <cstdlib>
#include <iostream>

typedef std::string Elem;

class DNode {  // doubly linked list node
 private:
  Elem name;                 // node element value
  DNode* prev;               // previous node in list
  DNode* next;               // next node in list
  friend class DLinkedList;  // allow DLinkedList access
};

class DLinkedList {  // doubly linked list
 public:
  DLinkedList();                 // constructor
  ~DLinkedList();                // destructor
  bool empty() const;            // is list empty?
  const Elem& front() const;     // get front element
  const Elem& back() const;      // get back element
  void addFront(const Elem& e);  // add to front of list
  void addBack(const Elem& e);   // add to back of list
  void removeFront();            // remove from front
  void removeBack();             // remove from back
 private:                        // local type definitions
  DNode* header;                 // list sentinels
  DNode* trailer;

 protected:                           // local utilities
  void add(DNode* v, const Elem& e);  // insert new node before v
  void remove(DNode* v);              // remove node v
};

DLinkedList::DLinkedList() {  // constructor
  header = new DNode;         // create sentinels
  trailer = new DNode;
  header->next = trailer;  // have them point to each other
  trailer->prev = header;
  header->prev = NULL;
  trailer->next = NULL;
}

DLinkedList::~DLinkedList() {  // destructor
  while (!empty()) {
    removeFront();  //  remove all but sentinels
  }
  delete header;  //  remove the sentinels
  delete trailer;
}

bool DLinkedList::empty() const {  // is list empty?
  return (header->next == trailer);
}

const Elem& DLinkedList::front() const {  // get front element
  return header->next->name;
}

const Elem& DLinkedList::back() const {  // get back element
  return trailer->prev->name;
}

void DLinkedList::add(DNode* x, const Elem& value) {
  DNode* newNode = new DNode;
  newNode->name = value;
  newNode->next = x->next;
  newNode->prev = x;
  x->next->prev = newNode;
  x->next = newNode;
}

void DLinkedList::addFront(const Elem& e) {  // add to front of list
  add(header, e);
}

void DLinkedList::addBack(const Elem& e) {  // add to back of list
  add(trailer->prev, e);
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

void listReverse(DLinkedList& L) {  // reverse a list
  DLinkedList T;                    // temporary list
  while (!L.empty()) {              // reverse L into T
    Elem s = L.front();
    L.removeFront();
    T.addFront(s);
  }
  while (!T.empty()) {  // copy T back to L
    Elem s = T.front();
    T.removeFront();
    L.addBack(s);
  }
}

int main() {
  DLinkedList dll;
  dll.addBack("one");
  dll.addBack("two");
  dll.addBack("three");
  listReverse(dll);
  std::cout << dll.front() << std::endl;
}