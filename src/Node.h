#ifndef NODE_H
#define NODE_H

class Node {
    friend class BSTTree;

    public:
        Node();
        ~Node();
        Node(const Node&);

    protected:
        int key;
        Node *left, *right;

};

#endif