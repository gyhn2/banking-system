#ifndef ACCOUNTTREE_H
#define ACCOUNTTREE_H
#include "Tree.h"
#include "Account.h"

/* Banking System as Binary Search Tree */

class AccountTree : public Tree {
    public:
        AccountTree();
        ~AccountTree();
        Account* createAccount(int, double=0.0, string="", string="");
        Account* createAccount(double=0.0, string="", string="");
        Account* createAccount(string, string);
        Account* insertAccount(Account*&);
        Account* deleteAccount(int);
        Account* findAccount(int);
        double totalMoney();
        bool transfer(int, int, int);
        void traverse();
        void closeBank();
    private:
        Account* root;
        Account* insertAccount(Account*&, Account*);
        bool transfer(Account*, Account*, int);
        Account* findAccount(Account*, int);
        double totalMoney(Account*);
        void inOrder(Account*);
        void preOrder(Account*);
        void postOrder(Account*);
        void freeAll(Account*&);
};

#endif