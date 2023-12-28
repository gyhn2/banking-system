#ifndef TREE_H
#define TREE_H
#include "Node.h"

/* Binary Search Tree*/

class Tree {
    public:
        Tree();
        ~Tree();
        Node* find(int);
        Node* newNode(int);
        Node* insertNode(int);
        Node* deleteNode(int);
        int height();
        int size();
        void printTree() const;
        void free();
        // temporary
        Node* getRoot() const;

    private:
        Node *root;
        Node* find(Node*, int);
        Node* insertNode(Node*, int);
        Node* deleteNode(Node*, int);
        int heightFrom(Node*);
        int size(Node*);
};

#endif