#include "Tree.h"

Tree::Tree(): root(NULL) {}

Tree::~Tree() {
    freeTree(root);
}

Node* Tree::newNode(const int key) {
    Node* node = new Node(key);
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* Tree::insertNode(const int num) {
    // return insertNode(&*root, num);
    return insertNode(root, num);
}

Node* Tree::insertNode(Node*& rootNode, const int num) {
    if (rootNode == NULL) {
        rootNode = newNode(num);
    } else {
        if (num < rootNode->key) {
            rootNode->left = insertNode(rootNode->left, num);
        } else if (num > rootNode->key) {
            rootNode->right = insertNode(rootNode->right, num);
        } else {
            std::cout<< "Duplicate key not allowed: " << num << std::endl;
        }
    }
    return rootNode;
}

Node* Tree::deleteNode(Node*& rootNode, const int num) {
    if (rootNode == NULL) {
        std::cout << "No such node!" << std::endl;
        return rootNode;
    } else if (num == rootNode->key) {
        Node* curNode = rootNode;
        // int isRoot = 0;
        // if (curNode == root) isRoot = 1;
        if (rootNode->left == NULL) {
            rootNode = rootNode->right;
            delete curNode;
        }
        else if (rootNode->right == NULL) {
            rootNode = rootNode->left;
            delete curNode;
        } else {
            curNode = curNode->right;
            while (curNode && curNode->left != NULL) {
                curNode = curNode->left;
            }
            rootNode->key = curNode->key;
            rootNode->right = deleteNode(rootNode->right, curNode->key);
        }
        // if (isRoot == 1) root = rootNode;
        
    } else if (num < rootNode->key) {
        rootNode->left = deleteNode(rootNode->left, num);
    } else if (num > rootNode->key) {
        rootNode->right = deleteNode(rootNode->right, num);
    } 
    return rootNode;
}

Node* Tree::deleteNode(const int num) {
    return deleteNode(root, num);
}


Node* Tree::find(const int num) {
    return find(root, num);
}

Node* Tree::find(Node* node, const int num) {
    /* Recursive */
    // if (node == NULL) return node;
    // if (node->key==num) return node;
    // else if (num < node->key) return find(node->left, num);
    // else return find(node->right, num);

    /* Iterative */
    Node* rootNode = node;
    while (rootNode != NULL) {
        if (rootNode->key == num) return rootNode;
        else if (num < rootNode->key) rootNode = rootNode->left;
        else rootNode = rootNode->right;
    }
    return rootNode;
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
    preOrder(root);
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
