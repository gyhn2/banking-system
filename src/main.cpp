#include "Tree.h"
#include "AccountTree.h"
#include <iostream>

// std::unordered_map<person, int> AccountTree::nameLookup;

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
    t->insertNode(150);
    t->insertNode(151);

    t->traversal();
    std::cout << "height: " << t->height() << std::endl;
    std::cout << "size: " << t->size() << std::endl;

    std::cout << *(t->getRoot())<< std::endl;
    t->deleteNode(15);
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
    Account* acc2 = new Account(300.5, "John", "Doe");
    at->insertAccount(acc2);
    at->insertAccount(acc);
    at->createAccount(1, "Jane", "Smith");
    at->createAccount(2, "Ab", "Cd");

    at->transfer(10001, 10000, 15);
    at->traverse();
    std::cout << at->size() << std::endl;
    std::cout << at->totalMoney() << std::endl;
    at->findAccount("Jane", "Smith", "email")->print();
    at->findAccount(10002)->print();

    at->deleteAccount(3);
    at->deleteAccount(10001);
    at->traverse();
    std::cout << at->size() << std::endl;
    std::cout << at->totalMoney() << std::endl;
    delete at;

    return 0;
}