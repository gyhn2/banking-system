#include "Tree.h"
#include "AccountTree.h"
#include <iostream>

int main() {

    // BST test
    Tree* t = new Tree();

    t->insertNode(3);
    t->insertNode(5);
    t->insertNode(15);
    t->insertNode(152);
    t->insertNode(10);
    t->insertNode(2);
    t->insertNode(1);
    t->insertNode(8);
    t->insertNode(13);
    t->insertNode(4);

    t->traversal();
    std::cout << "height: " << t->height() << std::endl;
    std::cout << "size: " << t->size() << std::endl;

    // t->getRoot()->rightC()->print();   
    t->deleteNode(5);
    // t->getRoot()->rightC()->print();
    // t->getRoot()->rightC()->rightC()->leftC()->print();
    t->traversal();
    // t->freeTree();

    std::cout << "height: " << t->height() << std::endl;
    std::cout << "size: " << t->size() << std::endl;

    delete t;

    // Account test
    AccountTree* at = new AccountTree();
    Account* acc = new Account();
    Account* acc2 = new Account(300.5, "I", "Am");
    acc->print();
    acc2->print();
    at->insertNode(5);
    at->deleteNode(5);
    delete acc;
    delete acc2;
    delete at;

    return 0;
}