#ifndef BSTTREE_H
#define BSTTREE_H

class BSTTree {
    public:
        BSTTree();
        ~BSTTree();
        Node* find() const;
        Node* newNode(int)
        Node* insertNode(Node*, int);
        Node* deleteNode(Node*, int);

    private:
        Node *root;
};


#endif