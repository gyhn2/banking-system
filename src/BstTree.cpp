#include "BstTree.h"

BstTree::BSTTree() {}

BstTree::~BSTTree() {
    delete root;
}

Node* BstTree::newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}