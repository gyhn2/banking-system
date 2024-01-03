#include "Node.h"

Node::Node() {
}

Node::Node(const int num): key(num) {
}

Node::~Node() {
    // delete left;
    // delete right;
}

Node::Node(const Node& node): 
    key(node.key), left(node.left), right(node.right)
{}

int Node::getKey() const {
    return key;
}

void Node::print() const {
    // draft
    std::cout << "  [" << key << "]  "<< std::endl;
}

Node* Node::leftC() {
    return left;
}

Node* Node::rightC() {
    return right;
}

std::ostream& operator<<(std::ostream & os, const Node & node)
{
    os << "[" << node.key << "]";
    return os;
}
