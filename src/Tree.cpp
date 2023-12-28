#include "Tree.h"
#include <stdio.h>

Tree::Tree(): root(NULL) {}

Tree::~Tree() {
    delete root;
}

Node* Tree::newNode(int key) {
    Node* node = new Node(key);
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* Tree::insertNode(Node* aNode, int num) {
    if (root == NULL) {
        root = newNode(num);
        return root;
    }
    if (aNode == NULL) {
        aNode = newNode(num);
    } else {
        if (num < aNode->key) {
            aNode->left = insertNode(aNode->left, num);
        } else if (num > aNode->key) {
            aNode->right = insertNode(aNode->right, num);
        } else {
            std::cout<< "Duplicate node!" <<std::endl;
        }
    }
    return aNode;
}

Node* Tree::insertNode(int num) {
    return insertNode(&*root, num);
}

Node* Tree::deleteNode(Node* aNode, int num) {
    if (aNode == NULL) {
        std::cout << "No such node!" << std::endl;
        return aNode;
    } else if (num == aNode->key) {
        Node* curNode = aNode;
        if (aNode->left == NULL) {
            aNode = aNode->right;
            delete curNode;
        }
        else if (aNode->right == NULL) {
            aNode = aNode->left;
            delete curNode;
        } else { // children on both sides
            curNode = curNode->right;
            while (curNode && curNode->left != NULL) {
                curNode = curNode->left;
            }
            aNode->key = curNode->key;
            aNode->right = deleteNode(aNode->right, aNode->key);
        }
        
    } else if (num < aNode->key) {
        aNode->left = deleteNode(aNode->left, num);
    } else if (num > aNode->key) {
        aNode->right = deleteNode(aNode->right, num);
    } 
    return aNode;
}

Node* Tree::deleteNode(int num) {
    return deleteNode(root, num);
}


Node* Tree::find(int num) {
    return find(root, num);
}

Node* Tree::find(Node* node, int num) {
    /* Recursive */
    // if (node == NULL) return node;
    // if (node->key==num) return node;
    // else if (num < node->key) return find(node->left, num);
    // else return find(node->right, num);

    Node* aNode = node;
    while (aNode != NULL) {
        if (aNode->key == num) return aNode;
        else if (num < aNode->key) aNode = aNode->left;
        else aNode = aNode->right;
    }
    return aNode;
}

int Tree::heightFrom(Node* rootp) {
    if (rootp == NULL) return -1;
    return 1+std::max(heightFrom(rootp->left), heightFrom(rootp->right));
}

int Tree::height() {
    return heightFrom(root);
}

int Tree::size(Node* rootp) {
    if (rootp == NULL) return 0;
    return 1+size(rootp->left)+size(rootp->right);
}

int Tree::size() {
    return size(root);
}


Node* Tree::getRoot() const {
    return root;
}

void Tree::printTree() const {
}

void Tree::free() {}

void Tree::traversal() {}