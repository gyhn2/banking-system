#include "AccountTree.h"

AccountTree::AccountTree()
{
}

AccountTree::~AccountTree()
{
    closeBank();
}

// create and insert an account
Account *AccountTree::createAccount(
    const int an, const double bal, const std::string& fn, const std::string& ln)
{
    Account* newAccount = new Account(an, bal, fn, ln);
    return insertAccount(root, newAccount);
}

Account *AccountTree::createAccount(
    const double bal, const std::string& fn, const std::string& ln)
{
    Account* newAccount = new Account(Account::nextNum++, bal, fn, ln);
    return insertAccount(root, newAccount);
}

Account *AccountTree::createAccount(const std::string& fn, const std::string& ln)
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
    insertIntoMap(newAcc->fname, newAcc->lname, "email", newAcc->acc_num);
    return rootAcc;
}

// delete account
Account *AccountTree::deleteAccount(const int an)
{
    return deleteAccount(root, an);
}

Account *AccountTree::deleteAccount(Account*& rootAcc, const int an)
{
    if (rootAcc != NULL) {
        if (an < rootAcc->acc_num) {
            rootAcc->left = deleteAccount(rootAcc->left, an);
        } else if (an > rootAcc->acc_num) {
            rootAcc->right = deleteAccount(rootAcc->right, an);
        } else {
            Account* temp = rootAcc;
            if (rootAcc->left == NULL) {
                rootAcc = rootAcc->right;
                delete temp;
            } else if (rootAcc->right == NULL) {
                rootAcc = rootAcc->left;
                delete temp;
            } else {
                temp = temp->right;
                while (temp && temp->left) {
                    temp = temp->left;
                }
                rootAcc->acc_num = temp->acc_num;
                rootAcc->fname = temp->fname;
                rootAcc->lname = temp->lname;
                rootAcc->balance = temp->balance;
                rootAcc->right = deleteAccount(rootAcc->right, temp->acc_num);
            }
        }
    } else {
        std::cout << "Account #" << an << " doesn't exist!" << std::endl;
    }
    return rootAcc;
}

// find account given account number
Account *AccountTree::findAccount(const int acc_num)
{
    return findAccount(root, acc_num);
}

Account *AccountTree::findAccount(Account* rootAcc, const int num) {
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
bool AccountTree::transfer(const int payer, const int payee, const double amt)
{
    return transfer(findAccount(payer), findAccount(payee), amt);
}

bool AccountTree::transfer(Account * payer, Account *payee, const double amt)
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
    std::cout << root->acc_num << "[" << root->lname << "]" << " ";
    inOrder(root->right);
}

void AccountTree::preOrder(Account* root) {
    if (root == NULL)
        return;
    std::cout << root->acc_num << "[" << root->lname << "]" << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void AccountTree::postOrder(Account* root) {
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    std::cout << root->acc_num << "[" << root->lname << "]" << " ";
}

// number of accounts
int AccountTree::size() {
    return size(root);
}

int AccountTree::size(Account* acc) {
    if (acc == NULL)
        return 0;
    return 1+ size(acc->left)+size(acc->right);
}


// free the bank BST
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

// insert into AccountMap
int AccountTree::insertIntoMap(const std::string& fname, const std::string& lname, 
    const std::string& email, const int acc_num) 
{
    person p = {fname, lname, email};
    nameLookup[p] = acc_num;
    return nameLookup[p];
}

// get Account Number by name and email
int AccountTree::getAccNumFromMap(const std::string& fname, const std::string& lname, 
    const std::string& email) {
    person p = {fname, lname, email};
    return AccountTree::nameLookup[p];
}

// find account by name and email 
Account* AccountTree::findAccount(const std::string& fname, const std::string& lname, 
    const std::string& email) {
    return findAccount(getAccNumFromMap(fname, lname, email));
}