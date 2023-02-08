#include <cstdlib>
#include <iostream>
using namespace std;

template <typename E>  // forward declaration of SLinkedList
class SLinkedList;

template <typename E>
class SNode {  // singly linked list node
 private:
  E elem;                       // linked list element value
  SNode<E>* next;               // next item in the list
  friend class SLinkedList<E>;  // provide SLinkedList access
};

template <typename E>
class SLinkedList {  // a singly linked list
 public:
  SLinkedList();                        // empty list constructor
  ~SLinkedList();                       // destructor
  bool empty() const;                   // is list empty?
  const E& front() const;               // return front element
  void addFront(const E& e);            // add to front of list
  void removeFront();                   // remove front of list
  int countNodes();                     // counts number of nodes
  void printList();                     // prints list in the form of elem1->elem2->...
  void appendList(const SLinkedList<E>& sll);// add sll to end of list
  void reverse();
 private:
  SNode<E>* head;  // head of the list
  int countNodes(SNode<E>* node);
  void reverse(SNode<E>* prev, SNode<E>* cur);
};

template <typename E>
SLinkedList<E>::SLinkedList()  // constructor
    : head(NULL) {}

template <typename E>
bool SLinkedList<E>::empty() const {  // is list empty?
  return head == NULL;
}

template <typename E>
const E& SLinkedList<E>::front() const {  // return front element
  return head->elem;
}

template <typename E>
SLinkedList<E>::~SLinkedList() {  // destructor
  while (!empty()) removeFront();
}

template <typename E>
void SLinkedList<E>::addFront(const E& e) {  // add to front of list
  SNode<E>* v = new SNode<E>;                // create new node
  v->elem = e;                               // store data
  v->next = head;                            // head now follows v
  head = v;                                  // v is now the head
}

template <typename E>
void SLinkedList<E>::removeFront() {  // remove front item
  if (head == NULL) return;
  SNode<E>* old = head;               // save current head
  head = old->next;                   // skip over old head
  delete old;                         // delete the old head
}

template <typename E>
int SLinkedList<E>::countNodes(SNode<E>* node) { // counts number of nodes
    if (!node) return 0;                         // stop at end of list
    return 1 + countNodes(node->next);           // head to next element
}

template <typename E>
int SLinkedList<E>::countNodes() {               // counts number of nodes
    if (empty()) return 0;                       // empty list
    return 1 + countNodes(head->next);           // has elements
}

template <typename E>
void SLinkedList<E>::printList(){
    SNode<E>* currentNode = head;
    while (currentNode->next) {                  // itterate through every element
        std::cout<<currentNode->elem<<"->";      // print current node
        currentNode=currentNode->next;           // go to next node
    }
    std::cout<<currentNode->elem<<std::endl;     // print last node without "->" after
    return;
}

template <typename E>
void SLinkedList<E>::appendList(const SLinkedList<E>& sll){
    SNode<E>* currentNode = head;
    SNode<E>* appendedCurrentNode = sll.head;

    while (currentNode->next) {                   // itterate to end of list
        currentNode = currentNode->next;          // go to next node
    }
    while (appendedCurrentNode) {                 // repeat for each elemnt in sll
        SNode<E>* newNode = new SNode<E>;         // make new node
        newNode->elem = appendedCurrentNode->elem;// copy elements
        currentNode->next = newNode;              // append new node
        currentNode = currentNode->next;          // increment original list node
        appendedCurrentNode = appendedCurrentNode->next;// increment added list node
    }
    currentNode->next = NULL;
    return;
}

template <typename E>
void SLinkedList<E>::reverse(SNode<E>* prev, SNode<E>* cur) {
    if (!cur) {                 // end of list
        head = prev;
        return;
    }

    SNode<E>* nxt = cur->next;
    cur->next = prev;
    reverse(cur, nxt);
}

template <typename E>
void SLinkedList<E>::reverse() {
    SNode<E>* nxt = head->next;
    head->next = NULL;
    reverse(head, nxt);
}

int main() {
  SLinkedList<std::string> list1;
  list1.addFront("four");
  list1.addFront("three");
  list1.addFront("two");
  list1.addFront("one");
  cout << "List 1 has " << list1.countNodes() << " nodes:" << endl; 
  list1.printList();

  SLinkedList<std::string> list2;
  list2.addFront("seven");
  list2.addFront("six");
  list2.addFront("five");
  cout << "List 2 has " << list2.countNodes() << " nodes:" << endl; 
  list2.printList();

  list1.appendList(list2);
  cout << "after appending  list 2 to list 1, list 1 has " << list1.countNodes() << " nodes:" << endl; 
  list1.printList();

  list1.reverse();
  cout << "After reversing list 1, it looks like this:" << endl; 
  list1.printList();
}
