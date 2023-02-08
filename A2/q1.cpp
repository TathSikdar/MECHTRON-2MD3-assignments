#include <cstdlib>
#include <iostream>
#include <vector>
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
  void swapNodes(int nodeIndex1, int nodeIndex2); // swaps node elements
 private:
  SNode<E>* head;  // head of the list
  int countNodes(SNode<E>* node);
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
    if (!node) {    // stop at end of list
        return 0;
    }
    else {
        return 1 + countNodes(node->next);       // head to next element
    }
}

template <typename E>
int SLinkedList<E>::countNodes() {               // counts number of nodes
    if (empty()) { 
        return 0;                                // empty list
    }
    else{
        return 1 + countNodes(head->next);       // has elements
    }
}

template <typename E>
void SLinkedList<E>::printList(){
    SNode<E>* currentNode = head;
    for (int i=0; i<countNodes()-1; i++){        // itterate through every element
        std::cout<<currentNode->elem<<"->";      // print current node
        currentNode=currentNode->next;           // go to next node
    }
    std::cout<<currentNode->elem<<std::endl;     // print last node without "->" after
    return;
}

template <typename E>
void SLinkedList<E>::swapNodes(int nodeIndex1, int nodeIndex2) {
    SNode<E>* currentNode = head;
    int index = 0;
    vector<SNode<E>*> nodes;
    
    while (currentNode) {
        if ((index == nodeIndex1) || (index == nodeIndex2)) {
            nodes.push_back(currentNode);
            nodes.push_back(currentNode->next);
        }
        currentNode = currentNode->next;
        index++;
    }
    for (int i=0; i<4; i++){
        cout<<nodes[i]<<"||";
    }
    return;
}

int main() {
  SLinkedList<std::string> sll;
  sll.addFront("one");
  sll.addFront("two");
  sll.addFront("three");
  sll.addFront("four");
  sll.addFront("five");
  sll.swapNodes(1,3);
  sll.printList();
//   std::cout << sll.countNodes() <<std::endl;
}
