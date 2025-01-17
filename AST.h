#include <iostream>
using namespace std;

struct Node {
    Node *left;
    Node *right;
    string content; 
    string type;
};

class AST {

    Node *root;

    public:
    AST();
    void AddNode(string content,Node*left,Node*right,string type);
    void printTree();
    string evaluateTree();
    Node * getroot();
    ~AST();
};