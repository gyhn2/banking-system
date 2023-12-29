#ifndef NODE_H
#define NODE_H
#include <iostream>

/* Binary Search Tree - Node */


class Node {
    friend class Tree;
    
    public:
        Node();
        Node(int);
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