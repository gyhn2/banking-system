#ifndef TREE_H
#define TREE_H
#include "Node.h"

/* Binary Search Tree */

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
        void freeTree();
        void traversal();
        // todo
        void printTree() const;
        // temporary
        Node* getRoot() const;

    private:
        Node *root;
        Node* find(Node*, int);
        Node* insertNode(Node*&, int);
        Node* deleteNode(Node*&, int);
        void freeTree(Node*& );
        int heightFrom(Node*);
        int size(Node*);
        void inOrder(Node*);
        void preOrder(Node*);
        void postOrder(Node*);
};

#endif