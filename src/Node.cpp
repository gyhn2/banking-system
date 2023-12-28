#include "Node.h"

Node::Node() {
}

Node::Node(int num): key(num) {
}

Node::~Node() {
}

Node::Node(const Node& node): 
    key(node.key), left(node.left), right(node.right)
{}

int Node::getKey() const {
    return key;
}

void Node::print() const {

    std::cout << "  [" << key << "]  "<< std::endl;
    if (left) std::cout << " /";
    if (right) std::cout << "  \\";
    std::cout << std::endl;
    if (left) std::cout << "[" << left->key << "]"; 
    if (right) std::cout <<  " [" << right->key << "]";
    std::cout << std::endl;
 
}

Node* Node::leftC() {
    return left;
}

Node* Node::rightC() {
    return right;
}