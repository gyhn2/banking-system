#ifndef ACCOUNTTREE_H
#define ACCOUNTTREE_H
#include "Tree.h"
#include "Account.h"

/* Banking System as Binary Search Tree */

class AccountTree : public Tree {
    public:
        AccountTree();
        Account* createAccount(int);
        Account* deleteAccount(int);
        Account* findAccount(int);
        double totalMoney() const;
        bool transfer(int, int, int);

    private:
        Account* root;
        bool transfer(Account*, Account*, int);
        Account* findAccount(Account*, int);
};

#endif