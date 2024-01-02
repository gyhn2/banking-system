#ifndef ACCOUNTTREE_H
#define ACCOUNTTREE_H
#include "Account.h"

/* Banking System implemented as a Binary Search Tree */

class AccountTree {
    public:
        AccountTree();
        ~AccountTree();
        Account* createAccount(const int, const double=0.0, const std::string& = "", const std::string& = "");
        Account* createAccount(const double=0.0, const std::string& ="", const std::string& = "");
        Account* createAccount(const std::string&, const std::string&);
        Account* insertAccount(Account*&);
        Account* deleteAccount(const int);
        Account* findAccount(const int);
        double totalMoney();
        bool transfer(const int, const int, const double);
        void traverse();
        int size();
        void closeBank();

        Account* findAccount(const std::string&, const std::string&, const std::string&);
    private:
        Account* root;
        Account* insertAccount(Account*&, Account*);
        Account* deleteAccount(Account*&, const int);
        bool transfer(Account*, Account*, const double);
        Account* findAccount(Account*, const int);
        double totalMoney(Account*);
        void inOrder(Account*);
        void preOrder(Account*);
        void postOrder(Account*);
        int size(Account*);
        void freeAll(Account*&);


        std::unordered_map<person, int> nameLookup;
        int insertIntoMap(const std::string&, const std::string&, const std::string&, const int);
        int getAccNumFromMap(const std::string&, const std::string&, const std::string&);
        
};

#endif