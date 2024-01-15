#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include "AccountMap.h"

/* Bank Acoount as a BST node */

class Account {
    friend class AccountTree;

    public:
        // Account();
        Account(const double=0.0, const std::string& = "", const std::string& = "", const std::string& = "");
        Account(const std::string&, const std::string&, const std::string&);
        Account(const int, const double=0.0, const std::string& = "", const std::string& = "", const std::string& = "");
        ~Account();
        bool deposit(const double);
        bool withdraw(const double);
        bool pay(Account*&, const double);
        bool changeFName(const std::string&);
        bool changeLName(const std::string&);
        bool changeEmail(const std::string&);
        double getBalance() const;
        virtual void print() const;

    protected:
        static int nextNum;
        int acc_num;
        double balance;
        std::string fname;
        std::string lname;
        std::string email;
        Account* left, *right;  
};

#endif