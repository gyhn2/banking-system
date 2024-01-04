#include "Tree.h"
#include "AccountTree.h"
#include <iostream>
#include <future>

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
    t->traversal();
    // t->freeTree();

    std::cout << "height: " << t->height() << std::endl;
    std::cout << "size: " << t->size() << std::endl;

    delete t;

    // Account test
    AccountTree* at = new AccountTree();
    Account* acc = new Account();
    Account* acc2 = new Account(300.5, "John", "Doe", "johndoe@email.com");
    at->insertAccount(acc2);
    at->changeAccountEmail(acc2, "newemail@gmail.com");

    if (at->findAccount("John", "Doe", "newemail@gmail.com"))
        at->findAccount("John", "Doe", "newemail@gmail.com")->print();
    else
        std::cout << "NULL" << std::endl;

    at->insertAccount(acc);
    at->createAccount(1, "Jane", "Smith", "janesmith@email.com");
    at->createAccount(2, "Ab", "Cd", "abcd@email.com");

    at->transfer(10001, 10000, 15);
    at->traverse();
    std::cout << at->size() << std::endl;
    std::cout << at->totalMoney() << std::endl;
    if (at->findAccount("Jane", "Smith", "janesmith@email.com"))
        at->findAccount("Jane", "Smith", "janesmith@email.com")->print();
    else
        std::cout << "NULL" << std::endl;

    if (at->findAccount(10002))
        at->findAccount(10002)->print();
    else
        std::cout << "NULL" << std::endl;

    at->deleteAccount(3);
    at->deleteAccount(10001);
    at->traverse();
    std::cout <<  "Number of accounts: " << at->size() << std::endl;
    std::cout << "Total money in bank: " << at->totalMoney() << std::endl;

    SavingsAccount* sa = new SavingsAccount(1000, "Jason", "Nam", "jason@email.com");

    delete at;

    return 0;
}
