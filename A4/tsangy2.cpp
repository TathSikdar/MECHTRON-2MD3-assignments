#include <cstdlib>
#include <iostream>
#include <cstring>
#include <list>
#include <stack>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

typedef std::string Elem;                                     // base element type

class LinkedBinaryTree {
  protected:
    struct Node {                                             // a node of the tree
      Elem elt;                                               // element value
      Node* par;                                              // parent
      Node* left;                                             // left child
      Node* right;                                            // right child
      Node() : elt(), par(NULL), left(NULL), right(NULL) { }  // constructor
    };

  public:
    class Position {        // position in the tree

    private:
      Node* v;              // pointer to the node

    public:
      Position(Node* v = NULL) : v( v) { }                   // constructor
      Elem& operator*() {                                    // get element
        return v->elt; 
      }
      Position left() const {                                // get left child
        return Position(v->left); 
      }
      Position right() const {                               // get right child
        return Position(v->right); 
      }
      Position parent() const {                              // get parent
        return Position(v->par); 
      }
      bool isRoot() const {                                  // root of the tree?
        return v->par == NULL; 
      }
      bool isExternal() const {                              // an external node?
        return v->left == NULL && v->right == NULL; 
      }

      friend class LinkedBinaryTree;                         // give tree access
    };

    typedef std::list<Position> PositionList;                // list of positions

public:
  LinkedBinaryTree();                                        // constructor
  bool isOperator(std::string str) const;                    // check if operator
  // bool isOperand(std::string str) const;                     // check if operand
  int size() const;                                          // number of nodes
  bool empty() const;                                        // is tree empty?
  Position root() const;                                     // get the root
  PositionList positions(int traversal) const;               // list of nodes
  void addRoot();                                            // add root to empty tree
  void expandExternal(const Position& p);                    // expand external node
  void expandOne(const Position& p);                         // expand a single node
  Position removeAboveExternal(const Position& p);           // remove p and parent

protected:                                                   // local utilities
  void preorder(Node* v, PositionList& pl) const;            // preorder utility
  void postorder(Node* v, PositionList& pl) const;
  void inorder(Node* v, PositionList& pl) const;

private:
  Node* _root;                                               // pointer to the root
  int n;                                                     // number of nodes
};

LinkedBinaryTree::LinkedBinaryTree()                         // constructor
  : _root(NULL), n(0) {}

bool LinkedBinaryTree::isOperator(std::string str) const {   // check if operator
  if (str=="+"||str=="-"||str=="*"||str=="/"||str==">"||str=="abs") {
    return true;
  }
  else {
    return false;
  }
}

// bool LinkedBinaryTree::isOperand(std::string str) const {    // check if operand
//   if (isdigit(postfix[i])) {
//     i++;
//     return true;
//   }
//   else {
//     return false;
//   }
// }

int LinkedBinaryTree::size() const {                         // number of nodes
  return n; 
}

bool LinkedBinaryTree::empty() const {                       // is tree empty?
  return size() == 0; 
}

LinkedBinaryTree::Position LinkedBinaryTree::root() const {  // get the root
  return Position(_root); 
}

LinkedBinaryTree::PositionList LinkedBinaryTree::positions(int traversal) const {  // list of all nodes
  PositionList pl;
  if (traversal==1)                                          // preorder traversal
    preorder(_root, pl); 
  else if (traversal==2)                                     // postorder traversal
    postorder(_root, pl);
  else                                                       // inorder traversal
    inorder(_root, pl);
  return PositionList(pl);                                   // return resulting list
}

void LinkedBinaryTree::addRoot() {                           // add root to empty tree
  _root = new Node; 
  n = 1; 
  _root->elt = n;
}

void LinkedBinaryTree::expandExternal(const Position& p) {   // expand external node
  Node* v = p.v; // p’s node
  v->left = new Node; // add a new left child
  v->left->par = v; // v is its parent
  v->right = new Node; // and a new right child
  v->right->par = v; // v is its parent
  n += 2; // two more nodes
}

void LinkedBinaryTree::expandOne(const Position& p) {         // expand a single node
  Node* v = p.v;
  v->left = new Node;                                         // only one child
  v->left->par = v;
  n+=1;                                                       // one more node
}

LinkedBinaryTree::Position // remove p and parent
LinkedBinaryTree::removeAboveExternal(const Position& p) {
  Node* w = p.v; Node* v = w->par; // get p’s node and parent
  Node* sib = (w == v->left ? v->right : v->left);
  if (v == _root) { // child of root?
  _root = sib; // . . .make sibling root
  sib->par = NULL;
  }
  else {
  Node* gpar = v->par; // w’s grandparent
  if (v == gpar->left) gpar->left = sib; // replace parent by sib
  else gpar->right = sib;
  sib->par = gpar;
  }
  delete w; delete v; // delete removed nodes
  n -= 2; // two fewer nodes
  return Position(sib);
}

void LinkedBinaryTree::preorder(Node* v, PositionList& pl) const {  // preorder traversal
  pl.push_back(Position(v)); // add this node
  if (v->left != NULL) // traverse left subtree
    preorder(v->left, pl);
  if (v->right != NULL) // traverse right subtree
    preorder(v->right, pl);
}

void LinkedBinaryTree::postorder(Node* v, PositionList& pl) const {   // postorder traversal
  if (v->left != NULL)    // traverse left subtree
    preorder(v->left, pl);
  if (v->right != NULL)   // traverse right subtree
    preorder(v->right, pl);
  pl.push_back(v);
}

void LinkedBinaryTree::inorder(Node* v, PositionList& pl) const {   // inorder traversal
  if (v->left != NULL)    // traverse left subtree
    preorder(v->left,pl);
  pl.push_back(v);        
  if (v->right != NULL)   // traverse right subtree
    preorder(v->right, pl);
}

LinkedBinaryTree createExpressionTree(std::string postfix) {   // build and return binary expression tree
  LinkedBinaryTree tree = LinkedBinaryTree();
  std::stack<std::string> makeStack;
  bool atLeft = 0;                                             // at left or right side

  std::stringstream ss(postfix);   // separate by space
  std::string substring;
  while (ss >> substring) {
    makeStack.push(substring);    // push onto stack
  }

  int stackSize = makeStack.size();
  tree.addRoot();
  LinkedBinaryTree::Position posNode = tree.root();
  *posNode = makeStack.top();
  makeStack.pop();

  if (*posNode=="abs") {
    tree.expandOne(posNode);
    atLeft = 1;
  }
  else if (tree.isOperator(*posNode)) tree.expandExternal(posNode);
  else { return tree; }

  for (int i=1;i<stackSize;i++) {
    if (tree.isOperator(makeStack.top())) {                    // create child for abs operator
      if (makeStack.top()=="abs") {
        posNode = posNode.left();
        *posNode = makeStack.top();
        makeStack.pop();
        tree.expandOne(posNode);
        atLeft = 1;
      }
      else {                                                   // create left and right child if operator
        posNode = posNode.left();
        *posNode = makeStack.top();
        makeStack.pop();
        tree.expandExternal(posNode);
        atLeft = 0;
      }
    }
    else {
      LinkedBinaryTree::Position curNode;
      if (atLeft==1) {
        curNode = posNode.left();
        *curNode = makeStack.top();
        makeStack.pop();
        atLeft = 0;
      }
      else {
        curNode = posNode.right();
        *curNode = makeStack.top();
        makeStack.pop();
        atLeft = 1;
      }
    }
  }
  return tree;
}

int main() {
  createExpressionTree("-3.7 abs");
  return 0;
}