#include "AccountTree.h"

AccountTree::AccountTree()
{
}

AccountTree::~AccountTree()
{
    closeBank();
}

// create and insert an account
Account *AccountTree::createAccount(int an, double bal, string fn, string ln)
{
    Account* newAccount = new Account(an, bal, fn, ln);
    return insertAccount(root, newAccount);
}

Account *AccountTree::createAccount(double bal, string fn, string ln)
{
    Account* newAccount = new Account(Account::nextNum++, bal, fn, ln);
    return insertAccount(root, newAccount);
}

Account *AccountTree::createAccount(string fn, string ln)
{
    Account* newAccount = new Account(Account::nextNum++, 0.0, fn, ln);
    return insertAccount(root, newAccount);
}

// insert an existing account
Account* AccountTree::insertAccount(Account*& newAcc) {
    return insertAccount(root, newAcc);
}

Account* AccountTree::insertAccount(Account*& rootAcc, Account* newAcc) {
    if (rootAcc == NULL) {
        rootAcc = newAcc;
    } else {
        if (newAcc->acc_num < rootAcc->acc_num) {
            rootAcc->left = insertAccount(rootAcc->left, newAcc);
        } else if (newAcc->acc_num > rootAcc->acc_num)
            rootAcc->right = insertAccount(rootAcc->right, newAcc);
        else
            std::cout << "Account already exists: " << rootAcc->acc_num << std::endl;
    }
    return rootAcc;
}


Account *AccountTree::deleteAccount(int)
{
    return nullptr;
}

// find account given account number
Account *AccountTree::findAccount(int acc_num)
{
    return findAccount(root, acc_num);
}

Account *AccountTree::findAccount(Account* rootAcc, int num) {
    Account* acc = rootAcc;
    while (acc != NULL) {
        if (acc->acc_num == num) return acc;
        else if (num < acc->acc_num) acc = acc->left;
        else acc = acc->right;
    }
    std::cout << "Account Number " << num << " doesn't exist!" << std::endl;
    // user input: new account number or cancel
    int newAccNum; 
    std::cin >> newAccNum;
    if (newAccNum == -1) {
        std::cout << "Cancelling search..." << std::endl;
        return acc;
    }
    return findAccount(rootAcc, newAccNum);
}

// calculate sum of all balances
double AccountTree::totalMoney()
{
    return totalMoney(root);
}

double AccountTree::totalMoney(Account* rootAcc) {
    if (rootAcc == NULL)
        return 0.0;
    return rootAcc->balance + 
        totalMoney(rootAcc->left) + totalMoney(rootAcc->right);
}

// transfer money between accounts
bool AccountTree::transfer(int payer, int payee, int amt)
{
    return transfer(findAccount(payer), findAccount(payee), amt);
}

bool AccountTree::transfer(Account * payer, Account *payee, int amt)
{
    return payer->pay(payee, amt);
}

// traverse account tree
void AccountTree::traverse() {
    preOrder(root);
    std::cout<<std::endl;
}

void AccountTree::inOrder(Account* root) {
    if (root == NULL)
        return;
    inOrder(root->left);
    std::cout << root->acc_num << " ";
    inOrder(root->right);
}

void AccountTree::preOrder(Account* root) {
    if (root == NULL)
        return;
    std::cout << root->acc_num << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void AccountTree::postOrder(Account* root) {
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    std::cout << root->acc_num << " ";
}

void AccountTree::closeBank() {
    freeAll(root);
}

void AccountTree::freeAll(Account*& acc) {
    if (acc == NULL) return;
    freeAll(acc->left);
    freeAll(acc->right);
    delete acc;
    acc = NULL;
    // delete this;
}