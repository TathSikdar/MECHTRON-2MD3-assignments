#include <cstdlib>
#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

typedef std::string Elem; 

class LinkedBinaryTree {

protected:
    
    struct Node {                                                     // a node of the tree
        Elem elt;                                                     // element value 
        Node *par;                                                    // parent 
        Node *left;                                                   // left child
        Node *right;                                                  // right child
        Node(): elt(), par(NULL), left(NULL), right(NULL) {}          // constructors
    };

public:

    class Position {                                                  // position in the tree
        private:
            Node *v;                                                  // pointer to the node
        public:
            Position(Node *_v=NULL): v(_v) {}                         // constructor 
            Elem &operator*() {                                       // get element                
                return v->elt;
            }
            Position left() const {                                   // get left child
                return Position (v->left);
            }
            Position right() const {                                  // get right child 
                return Position (v->right);
            }
            Position parent() const {                                 // get parent 
                return Position(v->par);
            }
            bool isRoot() const {                                     // root of the tree
                return v->par==NULL;
            }
            bool isExternal() const {                                 // an external node
                return v->left==NULL && v->right==NULL;
            }
            friend class LinkedBinaryTree;                            // give tree access
    };

    typedef list<Position>  PositionList;                             // list of positions 

public:
    LinkedBinaryTree();                                               // constructor 
    int size() const;                                                 // number of nodes
    bool empty() const;                                               // is the tree empty?
    Position root() const;                                            // get the root 
    void addRoot();                                                   // add root to empty tree
    void expandExternal(const Position &p);                           // expand external node
    void expandLeft(const Position &p);
    Position removeAboveExternal(const Position &p);                  // remove p and parent
    int isOperator(const string& element) const;                      // checks for operators
    void printExpression();                                           // prints postfix expression
    double evaluateExpression(double a, double b);                    // compute expression inputting a and b
    double getScore() const;                                          // get score variable
    void setScore(double _score);                                     // set score variable
    bool operator<(const LinkedBinaryTree& LBT) const;                // compare score

protected:
    void preorder(Node *v, PositionList &pl) const;                   // preorder utility
    void postorder(Node *v, PositionList &pl) const;                  // postorder utility
    void inorder(Node *v, PositionList &pl) const;                    // inorder utility

private:
    Node * _root;                                                     // pointer to the root 
    int n;                                                            // number of nodes
    double score;
    void printExpression(Position p);                                           
    double evaluateExpression(double a, double b, Position p);
};

LinkedBinaryTree::LinkedBinaryTree(): _root(NULL), n(0), score(0) {}  //constructor 

int LinkedBinaryTree::size() const {                                  //number of nodes
    return n;
}

bool LinkedBinaryTree::empty() const {                                //is the tree empty?
    return size()==0;
}

LinkedBinaryTree::Position LinkedBinaryTree::root() const {           //get the root
    return Position(_root);
}

void LinkedBinaryTree::addRoot() {                                    //add root to the empty tree
    _root=new Node;
    n=1;
    _root->elt=n;
}
    
void LinkedBinaryTree::expandExternal(const Position &p) {            //expand external node
    Node* v = p.v;                                                    //p's node                      
    v->left = new Node;                                               //add a new left child 
    v->left->par = v;                                                 //v is its parent
    v->right = new Node;                                              //add a new right child    
    v->right->par = v;                                                //v is its paren
    n+=2;                                                             //number of nodes increased by 2
}

void LinkedBinaryTree::expandLeft(const Position &p) {
    Node* v = p.v;
    v->left = new Node;
    v->left->par = v;
    n++;
}


void LinkedBinaryTree::preorder(Node *v, PositionList &pl) const {
    pl.push_back(Position(v));
    if (v->left)                                                      // traverse left branch
        preorder(v->left, pl);
    if (v->right)                                                     // traverse right branch
        preorder(v->right, pl);
}

void LinkedBinaryTree::postorder(Node *v, PositionList &pl) const {
    if (v->left)                                                      // traverse left branch
        postorder(v->left, pl);
    if (v->right)                                                     // traverse right branch
        postorder(v->right, pl);
    pl.push_back(Position(v));
}

void LinkedBinaryTree::inorder(Node *v, PositionList &pl) const {
    if (v->left)                                                      // traverse left branch
        inorder(v->left, pl);
    pl.push_back(Position(v));
    if (v->right)                                                     // traverse right branch
        inorder(v->right, pl);
}

int LinkedBinaryTree::isOperator(const string& element) const {
    if (                                                              // check for normal operators
    element == "-" ||
    element == "+" ||
    element == "*" ||
    element == "/" ||
    element == ">") {
        return 1;
    }

    else if (element == "abs") {                                      // check for abs operator
        return 2;
    }

    return 0;                                                         // non operators
}


void LinkedBinaryTree::printExpression() {                            // recursively print tree as expression
    Position p = root();                                              // start at root

    if (p.isExternal()) {                                             // print number
        cout << *p;
    } 

    else if (isOperator(*p) == 2) {                                   // print abs operator
        cout << *p << "(";
        printExpression(p.left());                                    // traverse left branch
        cout << ")";
    }
    else {                                                            // print normal operators
        cout << "(";
        printExpression(p.left());                                    // traverse left branch
        cout  << *p;
        printExpression(p.right());                                   // traverse right branch
        cout << ")";
    }
}

void LinkedBinaryTree::printExpression(Position p) {
    if (p.isExternal()) {                                             // print number
        cout << *p;
    } 

    else if (isOperator(*p) == 2) {                                   // print abs operator
        cout << *p << "(";
        printExpression(p.left());                                    // traverse left branch
        cout << ")";
    }
    else {                                                            // print normal operators
        cout << "(";
        printExpression(p.left());                                    // traverse left branch
        cout  << *p;
        printExpression(p.right());                                   // traverse right branch
        cout << ")";
    }
}

double LinkedBinaryTree::evaluateExpression(double a, double b) {
    Position p = root();
    if (p.isExternal()) {                                             // base case (at outer branches)
        if (*p == "a")                                                // return variable a value
            return a;

        else if (*p == "b")                                           // return variable b value
            return b;
            
        else
            return stod(*p);                                          // return converted element
    }
    else {                                                            // traverse branches and perform operations
        if (*p == "abs") {
            double x = evaluateExpression(a, b, p.left());
            return abs(x);
        }
        else {
            double x = evaluateExpression(a, b, p.left());
            double y = evaluateExpression(a, b, p.right());

            if (*p == "+")
                return x+y;
            else if (*p == "-") 
                return x-y;
            else if (*p == "*")
                return x*y;
            else if (*p == "/")
                return x/y;
            else 
                if (x>y) 
                    return 1;
                else
                    return -1;
        }
    }
}

double LinkedBinaryTree::evaluateExpression(double a, double b, Position p) {
    if (p.isExternal()) {                                             // base case 
        if (*p == "a")                                                // return variable a value
            return a;

        else if (*p == "b")                                           // return variable b value 
            return b;
            
        else
            return stod(*p);                                          // return converted element
    }
    else {                                                            // traverse branches and perform operations
        if (*p == "abs") {
            double x = evaluateExpression(a, b, p.left());
            return abs(x);
        }
        else {
            double x = evaluateExpression(a, b, p.left());
            double y = evaluateExpression(a, b, p.right());

            if (*p == "+")
                return x+y;
            else if (*p == "-") 
                return x-y;
            else if (*p == "*")
                return x*y;
            else if (*p == "/")
                return x/y;
            else 
                if (x>y) 
                    return 1;
                else
                    return -1;
        }
    }
}

double LinkedBinaryTree::getScore() const {
    return score;
}

void LinkedBinaryTree::setScore(double _score) {
    score = _score;
}

bool LinkedBinaryTree::operator<(const LinkedBinaryTree& LBT) const {
    return score < LBT.getScore();
}



LinkedBinaryTree createExpressionTree(string postfix) {

    stack<string> stk;                                                // operator/operand stack
    stringstream str(postfix);
    string word;
    bool isLeft = false;                                              // add to left or right node
    LinkedBinaryTree LBT = LinkedBinaryTree();
    LBT.addRoot();                                                    // make root
    LinkedBinaryTree::Position pos = LBT.root();                      // make position object
    
    while (str >> word) {                                             // seperate postfix every space
        stk.push(word);                                               // add operator/operand to stack
    }

    int stackSize = stk.size();

    *pos = stk.top();                                                 // set pos element
    stk.pop();                                                        // remove added element


    if(LBT.isOperator(*pos) == 1)                                     // normal operators
        LBT.expandExternal(pos);                                      // add nodes

    else if(LBT.isOperator(*pos) == 2) {                              // abs operator
        LBT.expandLeft(pos);                                          // only add left node
        isLeft = true;
    }

    else
        return LBT;


    for (int i = 1; i<stackSize; i++) {                               // itterate through stack

        if(LBT.isOperator(stk.top()) == 1) {                          // normal operators
            pos = pos.left();                                         // set postion to left child
            *pos = stk.top(); stk.pop();                              // set element at pos
            LBT.expandExternal(pos);                                  // add children to pos
            isLeft = false;
        }
        else if(LBT.isOperator(stk.top()) == 2) {                     // abs operator
            pos = pos.left();                                         // set position to left child
            *pos = stk.top(); stk.pop();                              // set element at pos
            LBT.expandLeft(pos);                                      // add left child to pos
            isLeft = true;
        }
        else {
            LinkedBinaryTree::Position tempNode;                      // temp child node
            if(isLeft) {                                              // left child
                tempNode = pos.left();                                // go to left child
                *tempNode = stk.top(); stk.pop();                     // set element
                isLeft = false;
            }
            else {                                                    // right child
                tempNode = pos.right();                               // go to right child
                *tempNode = stk.top(); stk.pop();                     // set element
                isLeft = true;
            }
        }
    }

    return LBT;
}

// int main() {
//     LinkedBinaryTree a = createExpressionTree("3.7 -1.2 * abs");
//     a.printExpression();
//     cout << "\n" << a.evaluateExpression(1, 0) << endl;
//     a.setScore(1);
//     LinkedBinaryTree b = createExpressionTree("1 abs");
//     b.printExpression();
//     b.setScore(2);
//     bool c = a<b;
//     cout << "\n" << c;
// }

int main() {
    // Read postfix expressions into vector
    vector<LinkedBinaryTree> trees;
    ifstream exp_file ("expressions.txt");
    string line;
    while (getline(exp_file, line)) {
        trees.push_back(createExpressionTree(line));
    }
    // Read input data into 2D vector
    vector<vector<double>> inputs;
    ifstream input_file("input.txt");
    while (getline(input_file, line)) {
        vector<double> ab_input;
        stringstream ss(line);
        string str;
        while (getline(ss, str, ' ')) {
            ab_input.push_back(stod(str));
        }
        inputs.push_back(ab_input);
    }
    // Evaluate expressions on input data
    for (auto& t : trees) {
        double sum = 0;
            for (auto& i : inputs) {
            sum += t.evaluateExpression(i[0], i[1]);
        }
        t.setScore(sum/inputs.size());
    }
    // Sort trees by their score
    sort(trees.begin(), trees.end());
    for (auto& t : trees) {
        cout << "Exp ";
        t.printExpression();
        cout << " Score " << t.getScore() << endl;
    }
}