#ifndef NODE_H
#define NODE_H
#include <iostream>

/* Binary Search Tree - Node */

using namespace std;

class Node {
    friend class Tree;
    friend ostream& operator<<(ostream&, const Node&); 

    public:
        Node();
        Node(const int);
        ~Node();
        Node(const Node&);
        int getKey() const;
        virtual void print() const;
        //temporary getters
        Node* leftC();
        Node* rightC();

    protected:
        int key;
        Node *left, *right;

};

#endif