#include "AccountTree.h"

AccountTree::AccountTree()
{
}

Account *AccountTree::createAccount(int)
{
    return nullptr;
}

Account *AccountTree::deleteAccount(int)
{
    return nullptr;
}

Account *AccountTree::findAccount(int acc_num)
{
    return findAccount(root, acc_num);
}

Account *AccountTree::findAccount(Account* rootAcc, int num) {
    Account* acc = rootAcc;
    while (acc != NULL) {
        if (acc->getKey() == num) return acc;
        else if (num < acc->getKey()) acc = acc->left;
        else acc = acc->right;
    }
    return acc;
}

double AccountTree::totalMoney() const
{
    return 0.0;
}

bool AccountTree::transfer(int payer, int payee, int amt)
{
    return transfer(findAccount(payer), findAccount(payee), amt);
}

bool AccountTree::transfer(Account * payer, Account *payee, int amt)
{
    return payer->pay(payee, amt);
}
