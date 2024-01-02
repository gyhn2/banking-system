#include "Tree.h"
#include <stdio.h>

Tree::Tree(): root(NULL) {}

Tree::~Tree() {
    freeTree(root);
}

Node* Tree::newNode(int key) {
    Node* node = new Node(key);
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* Tree::insertNode(Node*& aNode, int num) {
    if (aNode == NULL) {
        aNode = newNode(num);
    } else {
        if (num < aNode->key) {
            aNode->left = insertNode(aNode->left, num);
        } else if (num > aNode->key) {
            aNode->right = insertNode(aNode->right, num);
        } else {
            std::cout<< "Duplicate key not allowed: " << num << std::endl;
        }
    }
    return aNode;
}

Node* Tree::insertNode(int num) {
    // return insertNode(&*root, num);
    return insertNode(root, num);
}

Node* Tree::deleteNode(Node*& aNode, int num) {
    if (aNode == NULL) {
        std::cout << "No such node!" << std::endl;
        return aNode;
    } else if (num == aNode->key) {
        Node* curNode = aNode;
        // int isRoot = 0;
        // if (curNode == root) isRoot = 1;
        if (aNode->left == NULL) {
            aNode = aNode->right;
            delete curNode;
        }
        else if (aNode->right == NULL) {
            aNode = aNode->left;
            delete curNode;
        } else {
            curNode = curNode->right;
            while (curNode && curNode->left != NULL) {
                curNode = curNode->left;
            }
            aNode->key = curNode->key;
            aNode->right = deleteNode(aNode->right, aNode->key);
        }
        // if (isRoot == 1) root = aNode;
        
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

    /* Iterative */
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

// Size of subtree
int Tree::size(Node* rootp) {
    if (rootp == NULL) return 0;
    return 1+size(rootp->left)+size(rootp->right);
}

// Size of BST
int Tree::size() {
    return size(root);
}

// Root getter
Node* Tree::getRoot() const {
    return root;
}

// Clear the BST
void Tree::freeTree() {
    freeTree(root);
}

// Delete the subtree
void Tree::freeTree(Node*& node) {
    if (node == NULL) return;
    freeTree(node->left);
    freeTree(node->right);
    delete node;
    node = NULL;
}

// Perform a traversal method
void Tree::traversal() {
    postOrder(root);
    std::cout<< std::endl;
}

// In-Order Traversal
void Tree::inOrder(Node* node) {
    if (node == NULL)
        return;
    inOrder(node->left);
    std::cout << node->key << " ";
    inOrder(node->right);
}

// Pre-Order Traversal
void Tree::preOrder(Node* node) {
    if (node == NULL)
        return;
    std::cout << node->key << " ";
    preOrder(node->left);
    preOrder(node->right);
}

// Post-Order Traversal
void Tree::postOrder(Node* node) {
    if (node == NULL)
        return;
    postOrder(node->left);
    postOrder(node->right);
    std::cout << node->key << " ";
}

void Tree::printTree() const {
}
