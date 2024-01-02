#ifndef TREE_H
#define TREE_H
#include "Node.h"

/* Binary Search Tree */

class Tree {
    public:
        Tree();
        ~Tree();
        Node* find(const int);
        Node* newNode(const int);
        Node* insertNode(const int);
        Node* deleteNode(const int);
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
        Node* find(Node*, const int);
        Node* insertNode(Node*&, const int);
        Node* deleteNode(Node*&, const int);
        void freeTree(Node*& );
        int heightFrom(Node*);
        int size(Node*);
        void inOrder(Node*);
        void preOrder(Node*);
        void postOrder(Node*);
};

#endif