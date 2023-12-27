#include "Node.h"

Node::Node() {}

Node::~Node() {
    delete left;
    delete right;
}

Node::Node(const Node& node): 
    key(node.key), left(node.left), right(node.right)
{}