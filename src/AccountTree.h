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

    private:

};

#endif